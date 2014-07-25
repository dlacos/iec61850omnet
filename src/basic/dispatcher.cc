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

#include "dispatcher.h"
#include "iec61850message_m.h"
#include "EtherFrame_m.h"
#include "IPv4Datagram.h"
#include "ARPPacket_m.h"
#include "Ieee802Ctrl_m.h"
#include "IGMPMessage_m.h"

Define_Module(Dispatcher);

void Dispatcher::initialize()
{
    // TODO - Generated method body
}

void Dispatcher::handleMessage(cMessage *msg)
{
    // TODO - Generated method body
    if(msg->arrivedOn("fromEthApp"))
        {
            if(dynamic_cast<Iec61850message *> (msg) != NULL)
                {
                    //Encapsulate in a 802.1Qframe
                    Ieee802Ctrl *etherctrl = check_and_cast<Ieee802Ctrl*>(msg->removeControlInfo());
                    //Ether8021QFrame *frame1q = NULL;
                    //frame1q->set;
                    send(msg,"toEncapLayer");
                    EV << "----------------From ETHApp to MAC (GOOSE Message)------------------" ;
                }
            else{
                delete(msg);
            }
        }
    if(msg->arrivedOn("fromNetLayer"))
        {
            send(msg,"toEncapLayer"); //ERROR? it is not a ipv4data
        }
    if(msg->arrivedOn("fromEncapLayer"))
        {
            if(dynamic_cast<Iec61850message *> (msg) != NULL)
            {
                send(msg,"toEthApp");
                EV << "----------------From Encap to ETHApp (GOOSE Message)----------------" ;
            }
            if(dynamic_cast<IPv4Datagram *> (msg) != NULL)
            {
                send(msg,"toNetLayer");
                EV << "----------------From Encap to Network (IPv4Datagram)----------------" ;
            }
            if(dynamic_cast<ARPPacket *> (msg) != NULL)
            {
                send(msg,"toNetLayer");
                EV << "----------------From Encap to Network (ARPPacket)----------------" ;
            }
            if(dynamic_cast<IGMPMessage *> (msg) != NULL)
            {
                send(msg,"toNetLayer");
                EV << "----------------From Encap to Network (ARPPacket)----------------" ;
            }
        }
}
void Dispatcher::processMessageFromEthApp(cPacket *msg)
{
    // TODO - Generated method body
}
void Dispatcher::processMessageFromNetwork(cPacket *msg)
{
    // TODO - Generated method body
}
void Dispatcher::processMessageFromEncap(cPacket *msg)
{
    // TODO - Generated method body
}
