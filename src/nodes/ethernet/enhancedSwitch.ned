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

package iec61850model.nodes.ethernet;

import iec61850model.linklayer.ethernet.Ethernet1QInterface;
import inet.base.NotificationBoard;
import inet.linklayer.IMACRelayUnit;
import inet.linklayer.ethernet.EthernetInterface;
import inet.networklayer.common.InterfaceTable;


module EnhancedSwitch
{
    parameters:
        @node();
        @labels(node,ethernet-node);
        @display("i=old/switch2;bgb=890,341");
        string relayUnitType = default("MACRelayUnit1Q"); // type of the ~IMACRelayUnit; currently possible
                                                          // values are ~MACRelayUnitNP and ~MACRelayUnitPP
    gates:
        inout ethg[] @labels(EtherFrame-conn);
    submodules:
        interfaceTable: InterfaceTable {
            @display("p=137,49");
        }
        notificationBoard: NotificationBoard {
            @display("p=60,117");
        }
        //        etherInterface[sizeof(ethg)]: EthernetInterface {
        //            parameters:
        //                //csmacdSupport = default(true);  // by default use CSMA/CD
        //                //macType = default(csmacdSupport ? "EtherMAC" : "EtherMACFullDuplex"); // ~EtherMAC or ~EtherMACFullDuplex
        //                //queueType = default(""); // ~DropTailQueue, or a Diffserv queue; set to "" for use of an internal queue
        //                //ingressTCType = default(""); // a module type implementing ~ITrafficConditioner for optional traffic conditioning of incoming traffic
        //                //egressTCType = default(""); // a module type implementing ~ITrafficConditioner for optional traffic conditioning of outgoing traffic
        //                //numOutputHooks = default(0);
        //                //numInputHooks = default(0); 
        //                @display("p=98,262,row");
        //        }
        relayUnit: <relayUnitType> like IMACRelayUnit {
            parameters:
                @display("p=437,92");
            gates:
                lowerLayerIn[sizeof(ethg)];
                lowerLayerOut[sizeof(ethg)];
        }
        eth1Q[sizeof(ethg)]: Ethernet1QInterface {
            parameters:
                @display("p=99,267,row");
        }

    connections:
        for i=0..sizeof(ethg)-1 {
            eth1Q[i].upperLayerIn <-- relayUnit.lowerLayerOut[i];
            eth1Q[i].upperLayerOut --> relayUnit.lowerLayerIn[i];
            eth1Q[i].phys <--> ethg[i];
        }
}
