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

#include "EthFrameClassifier.h"

Define_Module(EthFrameClassifier);

void EthFrameClassifier::initialize()
{
    // TODO - Generated method body
    enablePriority=par("enablePriority");
}

void EthFrameClassifier::handleMessage(cMessage *msg)
{
    // TODO - Generated method body
    if(msg->arrivedOn("in"))
    {
        //PAUSEFRAMES are high priority
        if (dynamic_cast<EtherPauseFrame*>(msg) != NULL)
        {
            send(msg, "p7");
        }
        else if(dynamic_cast<EthernetIIFrame *> (msg) != NULL)
        {
            //ev << "Ethernet II Frame"<< endl;
            EthernetIIFrame *frame = check_and_cast<EthernetIIFrame *>(msg);
            //Ieee8021QFrame *eth2Frame = check_and_cast<Ieee8021QFrame *>(frame->getEncapsulatedPacket());
            //eth2Frame = check_and_cast<Ieee8021QFrame *>(frame->getEncapsulatedPacket());
            if(dynamic_cast<Ieee8021QFrame *> (frame->getEncapsulatedPacket()) != NULL)
            {
                if(enablePriority)
                {
                    ev << "Ethernet 1Q Frame"<< endl;
                    Ieee8021QFrame *frame1q= check_and_cast<Ieee8021QFrame *>(frame->getEncapsulatedPacket());
                    //eth2Frame = check_and_cast<Ieee8021QFrame *>(frame->getEncapsulatedPacket());
                    int priority = frame1q->getPriority();
                    //ev << "Ethernet 1Q Frame Priority: "<< priority << endl;
                    switch (priority){
                    case 7:
                        send(msg,"p7");
                        break;
                    case 6:
                        send(msg,"p6");
                        break;
                    case 5:
                        send(msg,"p5");
                        break;
                    case 4:
                        send(msg,"p4");
                        break;
                    case 3:
                        send(msg,"p3");
                        break;
                    case 2:
                        send(msg,"p2");
                        break;
                    case 1:
                        send(msg,"p1");
                        break;
                    case 0:
                        send(msg,"p0");
                    default:
                        return;
                    }
                }
                else
                {
                    //ev << "----- Priority using is disabled"<< endl;
                    send(msg,"p1");
                }
            }
            else {
                //ev << "Ethernet Frame without Tag"<< endl;
                send(msg,"p1");
            }
        }
        else if(dynamic_cast<EtherFrame *> (msg) != NULL)
        {
            //ev << "Ethernet Frame"<< endl;
            send(msg,"p1");
        }
        else
        {
            ev << "Non Ethernet Frame"<< endl;
            delete(msg);
        }
    }
}
