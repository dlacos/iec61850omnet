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

#ifndef __IEC61850MODEL_LAYER8021Q_H_
#define __IEC61850MODEL_LAYER8021Q_H_

#include <omnetpp.h>
#include "iec61850message_m.h"
#include "Ieee802Ctrl_m.h"
#include "IPv4Datagram.h"
#include "ARPPacket_m.h"
#include "IGMPMessage_m.h"
#include "Ieee8021QFrame_m.h"
#include "EtherFrame_m.h"
#include "goose_m.h"
#include "sampledValue_m.h"
#include "ieee8021QConfigurator.h"
#include "EtherMAC.h"

/**
 * TODO - Generated class
 * Implementation of IEEE802.1Q layer for Intelligent Electronic Devices (IEC), used in Substation Automation Systems.
 */
class Layer8021Q : public cSimpleModule
{
  protected:
    bool enabled;
    int vid;
    virtual void initialize(int stage);
    virtual void handleMessage(cMessage *msg);
    virtual void processMessageFromEthApp(cPacket *msg);
    virtual void processMessageFromNetwork(cPacket *msg);
    virtual void processMessageFromEncap(cPacket *msg);
};

#endif
