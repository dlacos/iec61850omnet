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

#include "MACRelayUnitHost.h"

Define_Module(MACRelayUnitHost);

void MACRelayUnitHost::initialize()
{
    // TODO - Generated method body
    MACRelayUnit1Q::initialize();
}

void MACRelayUnitHost::handleMessage(cMessage *msg)
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
    //Arrival gate = upperlayer
    if(msg->arrivedOn("upperLayerIn"))
    {
        ev<<"Ethernet Frame from upper layer... "<<endl;
        EtherFrame* frame = (check_and_cast<EtherFrame *>(msg));
        int outputport = getPortForAddress(frame->getDest());
        ev<<"Output port: "<<outputport<<"NumPorts: "<<numPorts<<endl;
        if (outputport >= 0)
            {
                EV << "--- Sending frame " << frame << " with dest address " << frame->getDest() << " to port " << outputport << endl;
                send(frame, "lowerLayerOut", outputport);
            }
        else
            {
                EV << "--- Dest address " << frame->getDest() << " unknown, broadcasting frame " << frame << endl;
                broadcastFrame(frame, numPorts+1);
            }
        //MACRelayUnitNP::handleIncomingFrame(check_and_cast<EtherFrame *>(msg));
        //handleIncomingFrame((EtherFrame*)msg);
        //scheduleAt(simTime(), msg->dup());
        //send(msg,"")
        //delete(msg);
        //this->processFrame((EtherFrame*)msg);
//        cPacket* frame = ((EtherFrame*)msg)->getEncapsulatedPacket();
//        if (dynamic_cast<Ieee8021QFrame *>(frame))
//        {
//            handleincomming8021QFrame(check_and_cast<EthernetIIFrame *>(msg));
//        }
//        else
//        {
//            handleincommingNon8021QFrame(check_and_cast<EthernetIIFrame *>(msg));
//        }
//        return;
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
    delete (msg);
    }
}
