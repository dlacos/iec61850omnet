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

#ifndef __IEC61850MODEL_SVAPP_H_
#define __IEC61850MODEL_SVAPP_H_

#include <omnetpp.h>
#include "INETDefs.h"
#include "MACAddress.h"
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "Ieee802Ctrl_m.h"
#include "sampledValue_m.h"

/**
 * TODO - Generated class
 */
class SVApp : public cSimpleModule
{
protected:
  long seqNum;

  // send parameters
  cPar *sendInterval;
  cPar *numPacketsPerBurst;
  cPar *packetLength;
  int etherType;
  int vid;
  int tpid;
  int cfi;
  int appid;
  int priority;
  //bool reply;
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
  static simsignal_t rcvdSampledValueSignal;

public:
  SVApp();
  ~SVApp();

protected:
  virtual void initialize(int stage);
  virtual void handleMessage(cMessage *msg);

  virtual int numInitStages() const {return 2;}
  virtual void finish();

  virtual MACAddress resolveDestMACAddress();

  virtual void sendBurstPackets(MACAddress destMAC);
  //virtual void sendReply();
  virtual void receivePacket(cPacket *msg);
};

#endif
