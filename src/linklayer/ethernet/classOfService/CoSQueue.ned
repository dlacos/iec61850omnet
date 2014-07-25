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

package iec61850model.linklayer.ethernet.classOfService;

import inet.linklayer.IOutputQueue;
import inet.linklayer.queue.PriorityScheduler;
import inet.linklayer.queue.FIFOQueue;


module CoSQueue like IOutputQueue
{
    parameters:
        //bool enablePriority = default(true);
        string dataQueueType = default("DropTailQueue");  // class that inherits from IOutputQueue (~DropTailQueue, ~EtherQoSQueue, ~DiffservQueue etc.)
        //string dataQueueType = default("FIFOQueue");
        @display("bgb=484,348;i=block/queue");
    gates:
        input in;
        output out;
    submodules:
        scheduler: PriorityScheduler {
            @display("p=239,301");
        }
        p7: <dataQueueType> like IOutputQueue {            
            @display("p=43,204");
        }
        p6: <dataQueueType> like IOutputQueue {
            @display("p=100,205");
        }
        p5: <dataQueueType> like IOutputQueue {
            @display("p=154,205");
        }
        p4: <dataQueueType> like IOutputQueue {
            @display("p=207,205");
        }
        p3: <dataQueueType> like IOutputQueue {
            @display("p=276,203");
        }
        p2: <dataQueueType> like IOutputQueue {
            @display("p=328,201");
        }
        p1: <dataQueueType> like IOutputQueue {
            @display("p=381,202");
        }
        p0: <dataQueueType> like IOutputQueue {
            @display("p=432,203");
        }
        frameClassifier: EthFrameClassifier {
            @display("p=234,77");
        }
    connections:
        p7.out --> scheduler.in++;
        p6.out --> scheduler.in++;
        p5.out --> scheduler.in++;
        p4.out --> scheduler.in++;
        p3.out --> scheduler.in++;
        p2.out --> scheduler.in++;
        p1.out --> scheduler.in++;
        p0.out --> scheduler.in++;
        frameClassifier.p7 --> p7.in;
        frameClassifier.p6 --> p6.in;
        frameClassifier.p5 --> p5.in;
        frameClassifier.p4 --> p4.in;
        frameClassifier.p3 --> p3.in;
        frameClassifier.p2 --> p2.in;
        frameClassifier.p1 --> p1.in;
        frameClassifier.p0 --> p0.in;
        in --> frameClassifier.in;
        scheduler.out --> out;
}
