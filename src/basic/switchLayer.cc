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

#include "switchLayer.h"
#include "EtherFrame_m.h"

Define_Module(SwitchLayer);

void SwitchLayer::initialize()
{
    // TODO - Generated method body
}

void SwitchLayer::handleMessage(cMessage *msg)
{
    // TODO - Generated method body
    if(msg->arrivedOn("fromLowerLayer")) //Incoming message
        {
            if(dynamic_cast<EthernetIIFrame *> (msg) != NULL)
            {
                EV << "-------------------Incoming message from ETH";
                send(msg,"toRelay");
            }

        }
        if(msg->arrivedOn("fromRelay")) //Queue messages
        {
            if(dynamic_cast<EthernetIIFrame *> (msg) != NULL)
            {
                EV << "-------------------Incoming message from ETH";
                //send(msg,"queueOut"); With queue.
                send(msg,"toLowerLayer");
            }
        }
}
