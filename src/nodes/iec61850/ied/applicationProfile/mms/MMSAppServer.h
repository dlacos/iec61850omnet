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

#ifndef __IEC61850MODEL_MMSAPPSERVER_H_
#define __IEC61850MODEL_MMSAPPSERVER_H_


#include <omnetpp.h>
#include "INETDefs.h"
/**
 * TODO - Generated class
 */
class INET_API MMSAppServer : public cSimpleModule
{
protected:
  simtime_t delay;
  simtime_t maxMsgDelay;

  long msgsRcvd;
  long msgsSent;
  long bytesRcvd;
  long bytesSent;

  //statistics:
  static simsignal_t rcvdPkSignal;
  static simsignal_t sentPkSignal;

protected:
  virtual void sendBack(cMessage *msg);
  virtual void sendOrSchedule(cMessage *msg, simtime_t delay);

protected:
  virtual void initialize();
  virtual void handleMessage(cMessage *msg);
  virtual void finish();
};

#endif
