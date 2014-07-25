//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

#include <stdio.h>
#include <iostream>
#include "pcapper.h"
#include "Ethernet.h"
#include "EtherFrame_m.h"
#include "Ieee802Ctrl_m.h"
#include "iec61850message_m.h"
#include "Ieee8021QFrame_m.h"

Define_Module(Pcapper);

void Pcapper::initialize()
{
    // TODO - Generated method body
    if(par("pcapperOn").boolValue()==true)
        {
            struct pcap_hdr fh;
            const char* name = par("fileName").stringValue();

            if (!name || !name[0])
                throw cRuntimeError("Cannot open pcap file: file name is empty");

            dumpfile = fopen(name, "wb");
            if (!dumpfile)
                    throw cRuntimeError("Cannot open pcap file [%s] for writing: %s", name, strerror(errno));

            fh.magic = 0xa1b2c3d4;
            fh.version_major = 2;
            fh.version_minor = 4;
            fh.thiszone = 0;
            fh.sigfigs = 0;
            fh.snaplen = 65535;
            fh.network = 1;

            fwrite(&fh, sizeof(fh), 1, dumpfile);
        }
}

void Pcapper::handleMessage(cMessage *msg)
{
    // TODO - Generated method body
    if(msg->arrivedOn("upperIn")) //From App
    {
        if(par("pcapperOn").boolValue()==true)
        {
            //EtherFrame *frame = check_and_cast<EtherFrame *>(msg);
            if(dynamic_cast<EthernetIIFrame *> (msg) != NULL)
            {
                EV << "------------------- Ethernet II Frame from upperIn: " << msg->getArrivalGate() << ". \n";
                processEtherframe(check_and_cast<EtherFrame *>(msg));
            }
//            switch (msg->getKind())
//            {
//                case IEEE802CTRL_DATA:
//                case 0: // default message kind (0) is also accepted
//                    processPacketFromUpper(PK(msg));
//                    break;
//                default:
//                    throw cRuntimeError("Received message `%s' with unknown message kind %d", msg->getName(), msg->getKind());
//            }

        }
        send(msg,"lowerOut");
    }
    if(msg->arrivedOn("lowerIn")) //From Encap
    {
        if(par("pcapperOn").boolValue()==true)
        {
            if(dynamic_cast<EthernetIIFrame *> (msg) != NULL)
            {
                EV << "------------------- Ethernet II Frame from lowerIn: " << msg->getArrivalGate() << ". \n";
                processEtherframe(check_and_cast<EthernetIIFrame *>(msg));
            }
//            switch (msg->getKind())
//            {
//                case IEEE802CTRL_DATA:
//                case 0: // default message kind (0) is also accepted
//                    processPacketFromLower(PK(msg));
//                    break;
//                default:
//                    throw cRuntimeError("Received message `%s' with unknown message kind %d", msg->getName(), msg->getKind());
//            }
        }
        send(msg,"upperOut");
    }
}

void Pcapper::processEtherframe(EtherFrame *msg)
{
    EV << "Processing EtherIIFrame \n";
    if(dynamic_cast<Ieee8021QFrame *>(msg->getEncapsulatedPacket()))
    {
        Ieee8021QFrame *frame = check_and_cast<Ieee8021QFrame *>(msg->getEncapsulatedPacket());
        if(dynamic_cast<Iec61850message *> (frame->getEncapsulatedPacket()) != NULL)
        {
            EV << "Processing IEC61850 \n";
            writeFrame(check_and_cast<EtherFrame *>(msg));
        }
    }//TODO else... it could be an iec61850 message without 802.1Q, record it too.
}
void Pcapper::writeFrame (EtherFrame *msg)
{
    Ieee8021QFrame *frame = check_and_cast<Ieee8021QFrame *>(msg->getEncapsulatedPacket());
    Iec61850message *msgiec = check_and_cast<Iec61850message *>(frame->getEncapsulatedPacket());
    EV << "IEC61850 TCI: " << msgiec->getTci()<< ".\n";
    EV << "IEC61850 eType: " << msgiec->getEType()<< ".\n"; //shifted because 802.1Q optional bytes
    //EV << "IEC61850 etherType: " << msg-> << ".\n";

    EthernetIIFrame *ethIIframe = check_and_cast<EthernetIIFrame*>(msg);
    EV << "Dest: " << ethIIframe->getDest() << ".\n";
    EV << "Src: " << ethIIframe->getSrc() << ".\n";
    EV << "Length: " << ethIIframe->getByteLength() << ".\n";
    EV << "EtherType: " << ethIIframe->getEtherType() << ".\n";

    int  length;
    int i;
    unsigned char hdr_ETH[26]; //8(Preamble)+6(DestMac)+6(SrcMAC)+4(802.1Q)+2(Ethertype)
    unsigned char longitud_packet[2];

    packet_header.ts_sec = (int32) simTime().dbl(); //Only seconds in int
    packet_header.ts_usec = (uint32)((simTime().dbl() - packet_header.ts_sec)*1000000);

    //Message length:
    length = ethIIframe->getByteLength()+26;
    packet_header.incl_len = length;
    packet_header.orig_len = packet_header.incl_len;

    //length = msg->getByteLength()+26;
    //packet_header.incl_len = length;

    //Saving statistics:
    fwrite(&packet_header, sizeof(packet_header), 1, dumpfile);

    //Saving content:
    buffer = (unsigned char *) calloc(length, sizeof(unsigned char));

    for(i=0; i<6; i++)
    {
        hdr_ETH[i]=frame->getDest().getAddressByte(i); //Destination MAC
    }
    for(i=0; i<6; i++)
    {
        hdr_ETH[6+i]=frame->getSrc().getAddressByte(i); //Source MAC
    }

    if(ethIIframe->getEtherType()==0x8100)//EtherframeII IEEE802.1Q
    {
        hdr_ETH[12]=(ethIIframe->getEtherType()>>8) & 0xff; //higher bits
        hdr_ETH[13]=ethIIframe->getEtherType() & 0xff; //lower bits
    }
    //else if(etherctrl->getEtherType()!=0x8100)//EtherframeII normal
    //{
    //    hdr_ETH[12]=(etherctrl->getEtherType()>>8) & 0xff; //higher bits
    //    hdr_ETH[13]=etherctrl->getEtherType() & 0xff; //lower bits
    //}
    hdr_ETH[14]=(msgiec->getTci()>>8) & 0xFF; //Testing
    hdr_ETH[15]=msgiec->getTci() & 0xFF; //Testing
    //if(msg->getc(0)==0x61)
    //{
        //GOOSE
    hdr_ETH[16]=(msgiec->getEType()>>8) & 0xFF; //Testing
    hdr_ETH[17]=msgiec->getEType() & 0xFF; //Testing
    //hdr_ETH[16]=0x88; //Testing
    //hdr_ETH[17]=0xb8; //Testing
    hdr_ETH[18]=0x30; //Testing
    hdr_ETH[19]=0x00; //Testing
//    }
//    else
//    {
//        //SV
//    hdr_ETH[16]=0x88;
//    hdr_ETH[17]=0xbA;
//    hdr_ETH[18]=0x40;
//    hdr_ETH[19]=0x00;
//    }


    //Longitud_a_Cadena(length-26+10, &longitud_packet[0]); //Pasa la longitud enviada a hexadecimal.
    hdr_ETH[20]=longitud_packet[0];
    hdr_ETH[21]=longitud_packet[1];

    hdr_ETH[22]=0x00; //Testing
    hdr_ETH[23]=0x00; //Testing
    hdr_ETH[24]=0x00; //Testing
    hdr_ETH[25]=0x00; //Testing

    for(i=0; i<26; i++)
    {
        buffer[i]=hdr_ETH[i];
    }
    for(i=26; i<length; i++)
    {
        //buffer[i]=copia_mensaje->getContenido(i-26);
        buffer[i]=0x11;
    }
    fwrite(buffer, length, 1, dumpfile);
    free(buffer);
}
void Pcapper::finish()
{
    if(par("pcapperOn").boolValue()==true)
    {
        fclose(dumpfile);
    }

}
