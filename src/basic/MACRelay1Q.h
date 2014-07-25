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

#ifndef __IEC61850MODEL_MACRELAY1Q_H_
#define __IEC61850MODEL_MACRELAY1Q_H_

#include <omnetpp.h>
#include "MACRelayUnitSTPNP.h"
#include "EtherFrame_m.h"
#include "Ieee8021QFrame_m.h"
#include "ModuleAccess.h"
//#include "table8021Q.h"
#include "ieee8021QConfigurator.h"

/**
 * TODO - Generated class
 */
class INET_API MACRelay1Q : public MACRelayUnitSTPNP
{
public:
    //Table8021Q table8021q; //Local table... not used now
    //Ieee8021QConfigurator *ieee1q;
protected:
    //Base methods
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);

    // Handling Ethernet frames
    virtual void handleincomming8021QFrame(EtherFrame *msg);
    virtual void handleincommingNon8021QFrame(EtherFrame *msg);
    virtual void broadcastFrame(EtherFrame *frame, int inputport);
};

#endif
