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
//Based on TCPBasicClientApp
#ifndef __IEC61850MODEL_MMSAPPCLIENT_H_
#define __IEC61850MODEL_MMSAPPCLIENT_H_

#include <omnetpp.h>
#include "INETDefs.h"
#include "TCPGenericCliAppBase.h"
#include "IPvXAddressResolver.h"
/**
 * TODO - Generated class
 */
class INET_API MMSAppClient : public TCPGenericCliAppBase
{
protected:
  cMessage *timeoutMsg;
  bool earlySend;  // if true, don't wait with sendRequest() until established()
  int numRequestsToSend; // requests to send in this session
  simtime_t stopTime;

  //Servers addresses
  std::vector<IPvXAddress> destAddresses;

  /** Utility: sends a request to the server */
  virtual void sendRequest();

  /** Utility: cancel msgTimer and if d is smaller than stopTime, then schedule it to d,
   * otherwise delete msgTimer */
  virtual void rescheduleOrDeleteTimer(simtime_t d, short int msgKind);

public:
  MMSAppClient();
  virtual ~MMSAppClient();

protected:
  /** Redefined . */
  virtual void initialize(int stage);

  /** Redefined. */
  virtual void handleTimer(cMessage *msg);

  /** Redefined. */
  virtual void socketEstablished(int connId, void *yourPtr);

  /** Redefined. */
  virtual void socketDataArrived(int connId, void *yourPtr, cPacket *msg, bool urgent);

  /** Redefined to start another session after a delay. */
  virtual void socketClosed(int connId, void *yourPtr);

  /** Redefined to reconnect after a delay. */
  virtual void socketFailure(int connId, void *yourPtr, int code);
};

#endif
