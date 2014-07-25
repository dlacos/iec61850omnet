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

#include "MACRelayUnit1Q.h"

Define_Module(MACRelayUnit1Q);

void MACRelayUnit1Q::initialize()
{
    // TODO - Generated method body
    MACRelayUnitSTPNP::initialize();
}

void MACRelayUnit1Q::handleMessage(cMessage *msg)
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
void MACRelayUnit1Q::handleincomming8021QFrame(EtherFrame *msg)
{
    //Get VID, MAC Dest and MAC Src from the encapsulated EtherFrame
    EV << "IEEE 802.1Q EthernetIIFrame received. Processing..." << endl;
    //table8021q.printState();
    Ieee8021QFrame *qFrame = check_and_cast<Ieee8021QFrame *>(msg->getEncapsulatedPacket());
    //ev <<"TableMacVidSize: "<< table8021q.TableMacVid.size()<< endl;
    ev<< "Dest: " <<qFrame->getDest()<<endl;
    ev << " Source VLAN: "<< qFrame->getVid() << endl;
    if (qFrame->getDest().isBroadcast())//Do the same, just for future implementations..
    {
        //Broadcast in VLAN VID
        //Find all host in VLAN VID
        EV << "Broadcast destination address..." << endl;
        this->handleIncomingFrame(msg);

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
        this->handleIncomingFrame(msg);
    }
    else
    {
        cModule *ieee1q_module = simulation.getModuleByPath("ieee8021QConfigurator"); //New
        Ieee8021QConfigurator *ieee1q = check_and_cast<Ieee8021QConfigurator *>(ieee1q_module);
        //EV << "--------------------------------- ieee1q teste ---------------------" << endl;
        //ieee1q->printState();
        if (ieee1q->resolveMACwithVID(qFrame->getVid(),qFrame->getDest()))
        {
            //EV << "--------------------------------- Destination MAC found ---------------------" << endl;
            //ieee1q->printState();
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
            delete(msg);
        }
    }
}

void MACRelayUnit1Q::handleincommingNon8021QFrame(EtherFrame *msg)
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
void MACRelayUnit1Q::broadcastFrame(EtherFrame *frame, int inputport)
{
    EV << "Using new broadcast handler" << endl;
    //Ieee8021QFrame *qFrame = check_and_cast<Ieee8021QFrame *>(frame->getEncapsulatedPacket());
    if (dynamic_cast<Ieee8021QFrame *>(frame->getEncapsulatedPacket()))
    {
        EV << "Processing broadcast 8021Q Frame" << endl;
        Ieee8021QFrame *qFrame = check_and_cast<Ieee8021QFrame *>(frame->getEncapsulatedPacket());
        unsigned int vid = qFrame->getVid();
        ev<<"Broadcast VID Frame: "<<vid<<endl;
        //Get VID frame
        //Search VID hosts
        //Send frame
        bool sendFrameThroughThisPort=false;
        int cnt=0;
        bool bc=false;
        for (int i=0; i<numPorts; ++i) //Each port
        {
            if(i!=inputport) //Except the incoming port
            {
                if (this->port_status[i].state == FORWARDING)
                {
                    cModule *ieee1q_module = simulation.getModuleByPath("ieee8021QConfigurator"); //New
                    Ieee8021QConfigurator *ieee1q = check_and_cast<Ieee8021QConfigurator *>(ieee1q_module);
                    //for(unsigned int n=0; n<table8021q.TableMacVid.size(); n++) //Search VID in all lines
                    for(unsigned int n=0; n<ieee1q->Table1Q.size(); n++) //Search the VID in all table entries
                    {
                        if(vid == ieee1q->Table1Q[n].Vid)
                        {
                            MACAddress tmpMac = ieee1q->Table1Q[n].MAC;
                            if (getPortForAddress(tmpMac)==i) //If there is at least one, then send...
                            {
                                EV << "Found MAC "<< tmpMac  << " through port " << i << endl;
                                sendFrameThroughThisPort=true;
                                cnt++;
                                //send((EtherFrame*)frame->dup(), "lowerLayerOut", i);//... send the frame
                            }
                        }
//                        if (cnt>0)
//                        {
//                            EV << "Cnt > 0 sending " << endl;
//
//                            cnt=0;
//                            bc=false;
//                            break;
//                        }else if (cnt==0){
//                            bc=true;
//                            break;
//                        }
                    }
                    if (sendFrameThroughThisPort)
                    {
                        EV << "Sending through port: " <<i<< endl;
                        send((EtherFrame*)frame->dup(), "lowerLayerOut", i);//... send the frame through this port
                        sendFrameThroughThisPort=false;//
                        bc=false;
                    }
                }
            }
        }
        if (bc)
        {
            EV << "None to broadcasting. Any MAC found for this VID:" << endl;

//            for (int i=0; i<numPorts; ++i)
//            {
//                if (i != inputport)
//                {
//                    if (this->port_status[i].state == FORWARDING)
//                    {
//                        ev << "Port "<<i<< "Status: "<<this->port_status[i].state <<endl;
//                        send((EtherFrame*)frame->dup(), "lowerLayerOut", i);
//                    }
//                }
//            }
            //delete frame;
            //MACRelayUnitBase::broadcastFrame(frame,inputport);
            //for (int i=0; i<numPorts; ++i)
                //if (i != inputport)
                    //send((EtherFrame*)frame->dup(), "lowerLayerOut", i);
            //delete frame;
            //break;
        }
        delete frame;
    }
    else
    {
        EV << "Legacy broadcasting... input port: "<< inputport << endl;
        //MACRelayUnitBase::broadcastFrame(frame,inputport);
        for (int i=0; i<numPorts; ++i)
        {
            if (i != inputport)
            {
                if (this->port_status[i].state == FORWARDING)
                {
                    ev << "Port "<<i<< "Status: "<<this->port_status[i].state <<endl;
                    send((EtherFrame*)frame->dup(), "lowerLayerOut", i);
                }
            }
        }
        EV << "------------------Deleting frame..."<<endl;
        delete frame;
    }
}
double MACRelayUnit1Q::readChannelBitRate(int index)
{
    //cModule* mac = this->gate("lowerLayerOut",index)->getPathEndGate()->getOwnerModule();//Original
    cModule* sublayer1q = this->gate("lowerLayerOut",index)->getPathEndGate()->getOwnerModule(); //DLAM
    cModule* classifier = sublayer1q->gate("lowerLayerOut")->getPathEndGate()->getOwnerModule(); //DLAM
    cModule* queueCoS = classifier->gate("p1")->getPathEndGate()->getOwnerModule(); //DLAM
    cModule* scheduler = queueCoS->gate("out")->getPathEndGate()->getOwnerModule(); //DLAM
    cModule* mac = scheduler->gate("out")->getPathEndGate()->getOwnerModule();//DLAM
    cGate* physOutGate = mac->gate("phys$o");
    cGate* physInGate = mac->gate("phys$i");

    cChannel *outTrChannel = physOutGate->findTransmissionChannel();
    cChannel *inTrChannel = physInGate->findIncomingTransmissionChannel();

    bool connected = physOutGate->getPathEndGate()->isConnected() && physInGate->getPathStartGate()->isConnected();

    if (connected && ((!outTrChannel) || (!inTrChannel)))
        throw cRuntimeError("Ethernet phys gate must be connected using a transmission channel");

    double txRate = outTrChannel ? outTrChannel->getNominalDatarate() : 0.0;
    double rxRate = inTrChannel ? inTrChannel->getNominalDatarate() : 0.0;
    bool dataratesDiffer;
    if (!connected)
    {
        dataratesDiffer = (outTrChannel != NULL) || (inTrChannel != NULL);
    }
    else
    {
        dataratesDiffer = (txRate != rxRate);
    }

    if (dataratesDiffer)
    {
        throw cRuntimeError("The input/output datarates differ (%g / %g bps)", rxRate, txRate);
    }

    return txRate;

}
void MACRelayUnit1Q::setPortStatus(int port_idx, PortStatus status)
{
    //if (this->port_status.find(port_idx) != this->port_status.end())
    if (port_idx >=0 &&  port_idx < (int)this->port_status.size())
    {

        if (this->port_status[port_idx].role == status.role && this->port_status[port_idx].state == status.state)
        {
            // port is in the same status, no need to change port status
            return;
        }

        this->port_status[port_idx].role = status.role;
        this->port_status[port_idx].state = status.state;

        this->port_status[port_idx].BPDUQueue.clear(); // clean the BPDU queue since the port status have change

        if (status.state == LEARNING && status.role == ROOT_PORT)
        {
            this->port_status[port_idx].sync      = true;   // root port was proposed
            this->port_status[port_idx].proposing = false;  // root port is not proposing
            this->port_status[port_idx].proposed  = true;   // root port was proposed
            this->port_status[port_idx].agree     = false;  // wait for the allSynced to agree
            this->port_status[port_idx].agreed    = false;  // reset this flag
        }

        if ((status.state == LISTENING || status.state == LEARNING) && status.role == DESIGNATED_PORT)
        {
            // we are in position to propose
            this->port_status[port_idx].sync = true;      // we are in the sync process
            this->port_status[port_idx].proposing = true; // we start proposing until we block/edge the port
            this->port_status[port_idx].agreed = false;   // wait to be agreed with the proposal
            this->port_status[port_idx].agree = false;    // reset this flag
            this->port_status[port_idx].synced = false;   // wait until we agreed
            this->port_status[port_idx].proposed_pr = PriorityVector(this->priority_vector.root_id,this->priority_vector.root_path_cost,this->priority_vector.root_id,this->priority_vector.port_id);
            this->port_status[port_idx].observed_pr = PriorityVector();
        }

        if (status.state == FORWARDING && status.role == DESIGNATED_PORT)
        {
            // we are agreed to change to forward on this port
            this->port_status[port_idx].sync = false;      // sync finished
            this->port_status[port_idx].proposing = false; // reset this flag
            this->port_status[port_idx].proposed = false; // reset this flag
            this->port_status[port_idx].agreed = true;   // port is agreed
            this->port_status[port_idx].synced = true;   // port synced
        }

        if (status.role == EDGE_PORT || status.role == BACKUP_PORT)
        {
            // this port is synced
            this->port_status[port_idx].sync = true;      // sync process finished
            this->port_status[port_idx].synced = true;     // port synced
            this->port_status[port_idx].proposing = false; // reset this flag
        }

        if (status.role == ALTERNATE_PORT)
        {
            // this port is synced
            this->port_status[port_idx].sync = true;      // sync process finished
            this->port_status[port_idx].synced = true;    // port synced
            this->port_status[port_idx].agree = true;     // agree to set this port in alternate mode
            this->port_status[port_idx].proposing = false; // reset this flag
        }

        EV << "Port " << port_idx << " change status : " << this->port_status[port_idx] << endl;

        if (status.state == BLOCKING)
        {

            // color the internal port's link in red
            this->gate("lowerLayerOut",port_idx)->getDisplayString().setTagArg("ls",0,"red");
            // color the external port's link in red

            // TODO: make this code safe for unconnected gates
            //cModule* mac = this->gate("lowerLayerOut",port_idx)->getPathEndGate()->getOwnerModule(); //Original
            cModule* sublayer1q = this->gate("lowerLayerOut",port_idx)->getPathEndGate()->getOwnerModule(); //DLAM
            cModule* classifier = sublayer1q->gate("lowerLayerOut")->getPathEndGate()->getOwnerModule(); //DLAM
            cModule* queueCoS = classifier->gate("p1")->getPathEndGate()->getOwnerModule(); //DLAM
            cModule* scheduler = queueCoS->gate("out")->getPathEndGate()->getOwnerModule(); //DLAM
            cModule* mac = scheduler->gate("out")->getPathEndGate()->getOwnerModule(); //DLAM
            cGate* outport = mac->gate("phys$o")->getNextGate(); //Original
            outport->getDisplayString().setTagArg("ls",0,"red");
            cGate* inport = mac->gate("phys$i")->getPreviousGate()->getPreviousGate();
            inport->getDisplayString().setTagArg("ls",0,"red");


            if (this->port_status[port_idx].getForwardTimer()->isScheduled())
            {
                EV << "  Canceling fwd timer" << endl;
                cancelEvent(this->port_status[port_idx].getForwardTimer());
            }
            if (this->port_status[port_idx].isPortEdgeTimerActive())
            {
                EV << "  Canceling port edge timer" << endl;
                cancelEvent(this->port_status[port_idx].getPortEdgeTimer());
                this->port_status[port_idx].clearPortEdgeTimer();
            }
        }
        else if (status.state == LISTENING)
        {
            this->gate("lowerLayerOut",port_idx)->getDisplayString().setTagArg("ls",0,"yellow");
            // schedule the port edge timer
            if (this->port_status[port_idx].getPortEdgeTimer()->isScheduled())
            {
                EV << "  Canceling port edge timer" << endl;
                cancelEvent(this->port_status[port_idx].getPortEdgeTimer());
            }
            this->scheduleAt(simTime()+this->edge_delay,this->port_status[port_idx].getPortEdgeTimer());
            // schedule the forward timer
            if (this->port_status[port_idx].getForwardTimer()->isScheduled())
            {
                EV << "  Canceling fwd timer" << endl;
                cancelEvent(this->port_status[port_idx].getForwardTimer());
            }
            EV << "  restarting the forward timer" << endl;
            this->scheduleAt(simTime()+this->forward_delay,this->port_status[port_idx].getForwardTimer());

        }
        else if (status.state == LEARNING)
        {
            this->gate("lowerLayerOut",port_idx)->getDisplayString().setTagArg("ls",0,"blue");

            // check the edge timer and if it is active, canceling it since
            if (this->port_status[port_idx].isPortEdgeTimerActive())
            {
                EV << "  Canceling port edge timer" << endl;
                cancelEvent(this->port_status[port_idx].getPortEdgeTimer());
                this->port_status[port_idx].clearPortEdgeTimer();
            }
            if (this->port_status[port_idx].getForwardTimer()->isScheduled())
            {
                EV << "  Canceling fwd timer" << endl;
                cancelEvent(this->port_status[port_idx].getForwardTimer());
            }
            EV << "  restarting the forward timer" << endl;
            this->scheduleAt(simTime()+this->forward_delay,this->port_status[port_idx].getForwardTimer());

            // flush entries for this port to start the learning process
            this->flushMACAddressesOnPort(port_idx);

        }
        else if (status.state == FORWARDING)
        {
            this->gate("lowerLayerOut",port_idx)->getDisplayString().setTagArg("ls",0,"green");
            if (this->port_status[port_idx].getForwardTimer()->isScheduled())
            {
                EV << "  Canceling fwd timer" << endl;
                cancelEvent(this->port_status[port_idx].getForwardTimer());
            }

            if (this->port_status[port_idx].isPortEdgeTimerActive())
            {
                EV << "  Canceling port edge timer" << endl;
                cancelEvent(this->port_status[port_idx].getPortEdgeTimer());
                this->port_status[port_idx].clearPortEdgeTimer();
            }
            this->port_status[port_idx].clearForwardTimer();
        }


        if (status.role == ROOT_PORT)
        {
            this->gate("lowerLayerOut",port_idx)->getDisplayString().setTagArg("t",0,"R");
        }
        else if (status.role == DESIGNATED_PORT)
        {
            this->gate("lowerLayerOut",port_idx)->getDisplayString().setTagArg("t",0,"D");
        }
        else if (status.role == ALTERNATE_PORT)
        {
            this->gate("lowerLayerOut",port_idx)->getDisplayString().setTagArg("t",0,"A");
        }
        else if (status.role == BACKUP_PORT)
        {
            this->gate("lowerLayerOut",port_idx)->getDisplayString().setTagArg("t",0,"B");
        }
        else if (status.role == NONDESIGNATED_PORT)
        {
            this->gate("lowerLayerOut",port_idx)->getDisplayString().setTagArg("t",0,"ND");
        }
        else if (status.role == EDGE_PORT)
        {
            this->gate("lowerLayerOut",port_idx)->getDisplayString().setTagArg("t",0,"E");
        }
    }
    else
    {
        error("trying to change the status to a port that is not registered into the portStatusList into this switch");
    }

    // check for allSynced flag
    this->allSynced = true;
    for (int i=0; i<this->gateSize("lowerLayerOut"); i++)
    {
        if (i!=this->getRootPort())
        {
            if (!this->port_status[i].synced)
            {
                // there are still ports to be synced.FORWARDING
                this->allSynced = false;
            }
        }
    }

    // check root port agreement for non-root bridges only
    if (this->getRootPort()>-1)
    {
        // check if all ports are synced when the root port is not yet agreed.
        if (this->allSynced)
        {
            if (!this->port_status[this->getRootPort()].agree)
            {
                // agree the root port and set the root port in forward mode immediately
                EV << "all ports synced, so, we agree with the root port selection" << endl;
                this->port_status[this->getRootPort()].agree = true;
                this->setPortStatus(this->getRootPort(),PortStatus(FORWARDING,ROOT_PORT));
                this->sendConfigurationBPDU(this->getRootPort());
            }
        }
    }

}
void MACRelayUnit1Q::sendPauseFrame(int portno, int pauseUnits)
{
    EV << "Creating and sending PAUSE frame on port " << portno << " with duration=" << pauseUnits << " units\n";

    cGate* gate = this->gate("lowerLayerOut", portno); //Original
    //EtherMACBase *destModule = check_and_cast<EtherMACBase*>(gate->getPathEndGate()->getOwnerModule()); //Original
    cModule* sublayer1q = this->gate("lowerLayerOut",portno)->getPathEndGate()->getOwnerModule(); //DLAM
    cModule* classifier = sublayer1q->gate("lowerLayerOut")->getPathEndGate()->getOwnerModule(); //DLAM
    cModule* queueCoS = classifier->gate("p1")->getPathEndGate()->getOwnerModule(); //DLAM
    cModule* scheduler = queueCoS->gate("out")->getPathEndGate()->getOwnerModule(); //DLAM
    cModule* mac = scheduler->gate("out")->getPathEndGate()->getOwnerModule(); //DLAM
    EtherMACBase* destModule = check_and_cast<EtherMACBase*>(mac); //DLAM

    if (destModule->isActive())
    {
        // create Ethernet frame
        char framename[40];
        sprintf(framename, "pause-%d-%d", getId(), seqNum++);
        EtherPauseFrame *frame = new EtherPauseFrame(framename);
        frame->setDest(MACAddress::MULTICAST_PAUSE_ADDRESS);
        frame->setPauseTime(pauseUnits);

        frame->setByteLength(ETHER_PAUSE_COMMAND_PADDED_BYTES);

        send(frame, gate);
        pauseFinished[portno] = simTime() + ((double)PAUSE_UNIT_BITS) * pauseUnits / destModule->getTxRate();
    }
    else //disconnected or disabled
    {
        pauseFinished[portno] = SIMTIME_ZERO;
    }
}
