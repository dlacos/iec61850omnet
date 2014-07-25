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

package iec61850model.linklayer.ethernet;

//import enhancedswitch.linklayer.ethernet.classOfService.CoSQueue;
import iec61850model.linklayer.ethernet.switch1Qsublayer.Ieee1QLayer;
import inet.linklayer.IEtherMAC;
import inet.linklayer.IWiredNic;
import inet.linklayer.IOutputQueue;


module Ethernet1QInterface like IWiredNic
{
    parameters:
        bool csmacdSupport = default(false);  // by default CSMA/CD is turned off, so only point-to-point duplex links are supported.
        bool useSNAP = default(false);  // use EtherFrameWithSNAP instead EthernetIIFrame
        string macType = default(csmacdSupport ? "EtherMAC" : "EtherMACFullDuplex"); // ~EtherMAC or ~EtherMACFullDuplex
        string queueType = default("CoSQueue"); // ~DropTailQueue, or a Diffserv queue; set to "" for use of an internal queue
        @display("bgb=224,249;i=block/ifcard");
    gates:
        input upperLayerIn;
        output upperLayerOut;
        inout phys @labels(EtherFrame);
    submodules:
        queue: <queueType> like IOutputQueue {
            @display("p=67,135");
        }
        mac: <macType> like IEtherMAC {
            parameters:
                promiscuous = default(true);
                queueModule = default("queue");
                @display("p=133,188");
        }
        ieee1QLayer: Ieee1QLayer {
            @display("p=134,62");
        }
    connections:
        ieee1QLayer.lowerLayerOut --> queue.in;
        mac.upperLayerOut --> ieee1QLayer.lowerLayerIn;
        queue.out --> mac.upperLayerIn;
        mac.phys <--> { @display("m=s"); } <--> phys;
        upperLayerIn --> { @display("m=n"); } --> ieee1QLayer.upperLayerIn;
        ieee1QLayer.upperLayerOut --> upperLayerOut;
}
