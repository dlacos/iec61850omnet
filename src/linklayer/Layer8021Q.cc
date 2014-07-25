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

#include "Layer8021Q.h"

Define_Module(Layer8021Q);

void Layer8021Q::initialize(int stage)
{
    // TODO - Generated method body
    vid = par("vid");
    enabled = par("enabled");

    //Send VID to the IEEE802.1QConfigurator. All switches relay will use.

    // First, obtain own mac address(es)
    cModule *macModule = this->getParentModule()->getSubmodule("mac");
    EtherMAC *mac = check_and_cast<EtherMAC *>(macModule);

    //Find the IEEE802.1QConfigurator
    cModule *ieee1q_module = simulation.getModuleByPath("ieee8021QConfigurator"); //New
    Ieee8021QConfigurator *ieee1q = check_and_cast<Ieee8021QConfigurator *>(ieee1q_module);
    EV << "----------------------Adding MAC: "<< mac->getMACAddress()<<" with VID: "<< vid << endl;
    ieee1q->writeEntry(mac->getMACAddress(),vid);
}

void Layer8021Q::handleMessage(cMessage *msg)
{
    // TODO - Generated method body
    if(msg->arrivedOn("fromEthApp_a"))
    {
        if(dynamic_cast<Iec61850message *> (msg) != NULL)
        {
            processMessageFromEthApp(PK(msg));
            //send(msg,"toEncapLayer");
            //EV << "----------------From ETHApp to MAC (GOOSE Message)------------------" ;
        }
        else if (dynamic_cast<Goose *> (msg) != NULL)
        {
            processMessageFromEthApp(PK(msg));
        }
        else if (dynamic_cast<SampledValue *> (msg) != NULL)
        {
            processMessageFromEthApp(PK(msg));
        }
        else{
            delete(msg);
        }
    }
    if(msg->arrivedOn("fromEthApp_b"))
    {
        if(dynamic_cast<Iec61850message *> (msg) != NULL)
        {
            processMessageFromEthApp(PK(msg));
            //send(msg,"toEncapLayer");
            //EV << "----------------From ETHApp to MAC (GOOSE Message)------------------" ;
        }
        else{
            delete(msg);
        }
    }
    if(msg->arrivedOn("fromNetLayer"))
    {
        send(msg,"toEncapLayer"); //ERROR? it is not  ipv4data
    }
    if(msg->arrivedOn("fromEncapLayer"))
    {
        processMessageFromEncap(PK(msg));
    }
}
void Layer8021Q::processMessageFromEthApp(cPacket *msg)
{
    // TODO - Generated method body
    Ieee802Ctrl *etherctrl = check_and_cast<Ieee802Ctrl*>(msg->removeControlInfo());
    Ieee8021QFrame *frame1q= new Ieee8021QFrame(msg->getName(), IEEE802CTRL_DATA);

    if(dynamic_cast<Iec61850message *> (msg) != NULL)
    {
        Iec61850message *frameteste = check_and_cast<Iec61850message *>(msg);
        frame1q->setVid(frameteste->getVid());
    }
    if(dynamic_cast<Goose *> (msg) != NULL)
    {
        Goose *frameteste = check_and_cast<Goose *>(msg);
        //frame1q->setVid(frameteste->getVid());
        frame1q->setVid(vid);//Use VID of this module
        frame1q->setPriority(frameteste->getPriority());
        frame1q->setCfi(frameteste->getCfi());
        frame1q->setTpid(frameteste->getTpid());
    }
    if(dynamic_cast<SampledValue *> (msg) != NULL)
    {
        SampledValue *frameteste = check_and_cast<SampledValue *>(msg);
        //frame1q->setVid(frameteste->getVid());
        frame1q->setVid(vid);//Use VID of this module
        frame1q->setPriority(frameteste->getPriority());
        frame1q->setCfi(frameteste->getCfi());
        frame1q->setTpid(frameteste->getTpid());
        //EV << "----------------From ETHApp to MAC (Sampled Value Message). Encapsulating (802.1Q)------------------" ;
    }
    frame1q->setDest(etherctrl->getDest());
    frame1q->setSrc(etherctrl->getSrc());

    frame1q->setEtherType(etherctrl->getEtherType());
    frame1q->encapsulate(msg);
    frame1q->setControlInfo(etherctrl);
    //EV << "----------------From ETHApp to MAC (GOOSE Message). Encapsulating (802.1Q)------------------" ;
    send(frame1q,"toEncapLayer");

}
void Layer8021Q::processMessageFromNetwork(cPacket *msg)
{
    // TODO - Generated method body
}
void Layer8021Q::processMessageFromEncap(cPacket *msg)
{
    // TODO - Generated method body
    //if (par("enabled")){

    //EtherFrame *frame = check_and_cast<EtherFrame *>(msg);
        if(dynamic_cast<Ieee8021QFrame *> (msg) != NULL)
        {
            send(msg,"toEthApp_a");
            //EV << "----------------From Encap to ETHApp (GOOSE Message)----------------" ;
        }
        if(dynamic_cast<IPv4Datagram *> (msg) != NULL)
        {
            send(msg,"toNetLayer");
            //EV << "----------------From Encap to Network (IPv4Datagram)----------------" ;
        }
        if(dynamic_cast<ARPPacket *> (msg) != NULL)
        {
            send(msg,"toNetLayer");
            //EV << "----------------From Encap to Network (ARPPacket)----------------" ;
        }
        if(dynamic_cast<IGMPMessage *> (msg) != NULL)
        {
            send(msg,"toNetLayer");
            //EV << "----------------From Encap to Network (ARPPacket)----------------" ;
        }
    //}
}
