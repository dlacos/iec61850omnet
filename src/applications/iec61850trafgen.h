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

#ifndef __IEC61860MODEL_IEC61850TRAFGEN_H_
#define __IEC61860MODEL_IEC61850TRAFGEN_H_

#include <omnetpp.h>
#include "INETDefs.h"
#include "MACAddress.h"

/**
 * TODO - Generated class
 */
class Iec61850trafgen : public cSimpleModule
{
    protected:
      long seqNum;

      // send parameters
      cPar *sendInterval;
      cPar *numPacketsPerBurst;
      cPar *packetLength;
      int etherType;
      int vid;
      MACAddress destMACAddress;
      MACAddress srcMACAddress;

      // self messages
      cMessage *timerMsg;
      simtime_t stopTime;

      // receive statistics
      long packetsSent;
      long packetsReceived;
      static simsignal_t sentPkSignal;
      static simsignal_t rcvdPkSignal;
      static simsignal_t rcvdTrip1ASignal;

    public:
      Iec61850trafgen();
      ~Iec61850trafgen();

    protected:
      virtual void initialize(int stage);
      virtual void handleMessage(cMessage *msg);

      virtual int numInitStages() const {return 2;}
      virtual void finish();

      virtual MACAddress resolveDestMACAddress();

      virtual void sendBurstPackets();
      virtual void receivePacket(cPacket *msg);
};

#endif
