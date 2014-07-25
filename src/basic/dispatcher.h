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

#ifndef __IEC61860MODEL_DISPATCHER_H_
#define __IEC61860MODEL_DISPATCHER_H_

#include <omnetpp.h>
#include "iec61850message_m.h"
/**
 * TODO - Generated class
 * This module forwards the incoming traffic to its corresponding IEC61850 stack and the outgoing traffic to lower Ethernet layer.
 */
class Dispatcher : public cSimpleModule
{
  protected:
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);
    virtual void processMessageFromEthApp(cPacket *msg);
    virtual void processMessageFromNetwork(cPacket *msg);
    virtual void processMessageFromEncap(cPacket *msg);
};

#endif
