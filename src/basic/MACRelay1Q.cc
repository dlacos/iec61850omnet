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

#include "MACRelay1Q.h"

Define_Module(MACRelay1Q);

void MACRelay1Q::initialize()
{
    // TODO - Generated method body
    MACRelayUnitSTPNP::initialize();
    //table8021q.loadTable("table8021q.txt"); //Must be activated!!!
    //table8021q.printState();
    /*cModule *ieee1q_module = simulation.getModuleByPath("ieee8021QConfigurator"); //New
    Ieee8021QConfigurator *ieee1q = check_and_cast<Ieee8021QConfigurator *>(ieee1q_module);
    ieee1q->printState();*/
}

void MACRelay1Q::handleMessage(cMessage *msg)
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
void MACRelay1Q::handleincomming8021QFrame(EtherFrame *msg)
{
    //Get VID, MAC Dest and MAC Src from the encapsulated EtherFrame
    EV << "IEEE 802.1Q EthernetIIFrame received. Processing..." << endl;
    //table8021q.printState();
    Ieee8021QFrame *qFrame = check_and_cast<Ieee8021QFrame *>(msg->getEncapsulatedPacket());
    //ev <<"TableMacVidSize: "<< table8021q.TableMacVid.size()<< endl;
    ev<< "Dest: " <<qFrame->getDest()<<endl;
    ev << " Source VLAN: "<< qFrame->getVid() << endl;
    if (qFrame->getDest().isBroadcast())//Do the same, just for future functions..
    {
        //Broadcast in VLAN VID
        //Find all host in VLAN VID
        EV << "Broadcast destination address..." << endl;
        handleIncomingFrame(msg);

        /*ev<<"Looking for VID"<<endl;
        for (int p=0; p<numPorts; ++p)
        {
            for(unsigned int i=0; i<table8021q.TableMacVid.size(); i++)
            {
                if(qFrame->getVid() == table8021q.TableMacVid[i].Vid)
                {
                    MACAddress tmpMac = table8021q.TableMacVid[i].MAC;
                    if (getPortForAddress(tmpMac)>=0)
                    {
                        send((EtherFrame*)frame->dup(), "lowerLayerOut", i);
                    }
                }
            }
        }*/
    }
    else if (qFrame->getDest().isMulticast()) //Do the same, just for future implementations..
    {
        EV << "Multicast destination address..." << endl;
        handleIncomingFrame(msg);
    }
    else
    {
        cModule *ieee1q_module = simulation.getModuleByPath("ieee8021QConfigurator"); //New
        Ieee8021QConfigurator *ieee1q = check_and_cast<Ieee8021QConfigurator *>(ieee1q_module);
        EV << "--------------------------------- ieee1q teste ---------------------" << endl;
        ieee1q->printState();
        if (ieee1q->resolveMACwithVID(qFrame->getVid(),qFrame->getDest()))
        {
            //EV << "--------------------------------- Destination MAC found ---------------------" << endl;
            ieee1q->printState();
            EV << "Destination MAC address ("<< qFrame->getDest()<<") belongs to the same VLAN: "<< qFrame->getVid()<< endl;
            handleIncomingFrame(msg);
        }
        //EV << "--------------------------------- table8021q teste ---------------------" << endl;
        /*if (table8021q.resolveMAC(qFrame->getVid(),qFrame->getDest()))
        {
            EV << "Destination MAC address ("<< qFrame->getDest()<<") belongs to the same VLAN: "<< qFrame->getVid()<< endl;
            handleIncomingFrame(msg);
        }*/
        else
        {
            EV << "Source("<<qFrame->getSrc()<<") and Dest("<<qFrame->getDest()<< ")do not belong to the same VLAN: "<<qFrame->getVid()<<". Deleting... " << endl;
        }
    }
}

void MACRelay1Q::handleincommingNon8021QFrame(EtherFrame *msg)
{
    //Open Etherframe
    //Assign VID according with the MACVID Table. If does not belong to any VID, use VID=1?
    //Encapsulate Ether8021Qframe
    EV << "Non IEEE 802.1Q Frame. Processing it" << endl;
    //table8021q.printState();
    //ev <<"TableMacVidSize: "<< table8021q.TableMacVid.size()<< endl;
    //Tag with VID=1 (Only IEC61850)
    handleIncomingFrame(msg);
}
void MACRelay1Q::broadcastFrame(EtherFrame *frame, int inputport)
{
    EV << "Using new broadcast handler" << endl;
    //Ieee8021QFrame *qFrame = check_and_cast<Ieee8021QFrame *>(frame->getEncapsulatedPacket());
    if (dynamic_cast<Ieee8021QFrame *>(frame->getEncapsulatedPacket()))
    {
        EV << "Processing broadcast 8021Q Frame" << endl;
        Ieee8021QFrame *qFrame = check_and_cast<Ieee8021QFrame *>(frame->getEncapsulatedPacket());
        unsigned int vid = qFrame->getVid();
        //Get VID frame
        //Search VID hosts
        //Send frame
        int cnt=0;
        for (int i=0; i<numPorts; ++i) //Each port
        {
            if(i!=inputport) //Except the incoming port
            {
                cModule *ieee1q_module = simulation.getModuleByPath("ieee8021QConfigurator"); //New
                Ieee8021QConfigurator *ieee1q = check_and_cast<Ieee8021QConfigurator *>(ieee1q_module);
                //for(unsigned int n=0; n<table8021q.TableMacVid.size(); n++) //Search VID in all lines
                for(unsigned int n=0; n<ieee1q->Table1Q.size(); n++) //Search VID in all lines
                {
                    if(vid == ieee1q->Table1Q[n].Vid)
                    {
                        MACAddress tmpMac = ieee1q->Table1Q[n].MAC;
                        if (getPortForAddress(tmpMac)==i) //If there is at least one, then...
                        {
                            EV << "Found port "<< i << " and MAC " << tmpMac << endl;
                            cnt++;
                            //send((EtherFrame*)frame->dup(), "lowerLayerOut", i);//... send the frame
                        }

                    }
                    if (cnt>0)
                    {
                        send((EtherFrame*)frame->dup(), "lowerLayerOut", i);//... send the frame
                        cnt=0;
                        break;
                    }

                }

            }
        }
        delete frame;
    }
    else
    {
        EV << "Legacy broadcasting..." << endl;
        for (int i=0; i<numPorts; ++i)
            if (i != inputport)
                send((EtherFrame*)frame->dup(), "lowerLayerOut", i);
        delete frame;
    }
}
