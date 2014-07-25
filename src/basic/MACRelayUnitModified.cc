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
// This module is an extension of the MACRelayUnitSTPNP module

#include "MACRelayUnitModified.h"

Define_Module(MACRelayUnitModified);


void MACRelayUnitModified::initialize()
{
    // TODO - Generated method body
    MACRelayUnitSTPNP::initialize();
    table8021q.loadTable("table8021q.txt");
    table8021q.printState();
}

void MACRelayUnitModified::handleMessage(cMessage *msg)
{
    // TODO - Generated method body
    if (msg->isSelfMessage())
    {
        if (dynamic_cast<STPTimer*>(msg))
        {
            this->handleTimer(msg);
        }
        else
        {
            this->processFrame(msg);
        }
        return;
    }
    else
    {
        if (this->active)
        {
            if (dynamic_cast<EtherFrame*>(msg))
            {
                //EV << "-----------------------------------Ethernet frame arrived." << endl;
                cPacket* frame = ((EtherFrame*)msg)->getEncapsulatedPacket();
                if (dynamic_cast<BPDU*>(frame))
                {
                    cPacket* frame = ((EtherFrame*)msg)->decapsulate();
                    BPDU* bpdu = dynamic_cast<BPDU*>(frame);
                    bpdu->setArrival(this,msg->getArrivalGateId());
                    this->handleBPDU(bpdu);
                }
                else
                {
                    // Etherframe incoming, handle it
                    //EtherFrame* frame = dynamic_cast<EtherFrame*>(msg);
                    //EV << "-----------------------------------Non BPDU frame arrived." << endl;
                    //EthernetIIFrame* frame1q = check_and_cast<EthernetIIFrame *>(frame);
                    if (dynamic_cast<Ieee8021QFrame *>(frame))
                    {
                        handleincomming8021QFrame(check_and_cast<EthernetIIFrame *>(msg));
                    }
                    else
                    {
                        handleincommingNon8021QFrame(check_and_cast<EthernetIIFrame *>(msg));
                    }
                    //this->handleIncomingFrame(frame);
                    return;
                }
            }
            else
            {
                EV << "Non Ethernet frame arrived. Discarding it" << endl;
            }
        }
        else
        {
            EV << "Bridge not active. discarding packet" << endl;
        }
    }
    delete (msg);
}
void MACRelayUnitModified::handleincomming8021QFrame(EtherFrame *msg)
{
    //Get VID, MAC Dest and MAC Src from the encapsulated EtherFrame
    EV << "IEEE 802.1Q EthernetIIFrame received. Processing..." << endl;
    table8021q.printState();
    Ieee8021QFrame *qFrame = check_and_cast<Ieee8021QFrame *>(msg->getEncapsulatedPacket());
    ev <<"TableMacVidSize: "<< table8021q.TableMacVid.size()<< endl;
    ev<< "Source: " <<qFrame->getDest()<<endl;
    ev << " Source VLAN: "<< qFrame->getVid() << endl;
    if (table8021q.resolveMAC(qFrame->getVid(),qFrame->getDest()))
    {
        EV << "Destination MAC address ("<< qFrame->getDest()<<") belongs to the same VLAN: "<< qFrame->getVid()<< endl;
        handleIncomingFrame(msg);
    }
    else
    {
        EV << "Source("<<qFrame->getSrc()<<") and Dest("<<qFrame->getDest()<< ")do not belong to the same VLAN: "<<qFrame->getVid()<<". Deleting... " << endl;
    }

}

void MACRelayUnitModified::handleincommingNon8021QFrame(EtherFrame *msg)
{
    //Open Etherframe
    //Assign VID according with the MACVID Table. If does not belong to any VID, use VID=1
    //Encapsulate Ether8021Qframe
    EV << "Non IEEE 802.1Q Frame. Processing it" << endl;
    table8021q.printState();
    ev <<"TableMacVidSize: "<< table8021q.TableMacVid.size()<< endl;
    //Tag with VID=1 (Only IEC61850)
    handleIncomingFrame(msg);

}
