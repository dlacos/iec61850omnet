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

package iec61850model.prp;

import iec61850model.applications.Iec61850trafgen;
import iec61850model.linklayer.Layer8021Q;
import iec61850model.util.Pcapper;
import inet.base.NotificationBoard;
import inet.linklayer.IEtherMAC;
import inet.linklayer.ethernet.EtherQoSQueue;
import inet.linklayer.ethernet.IEtherEncap;
import inet.networklayer.common.InterfaceTable;
import inet.networklayer.ipv4.IPv4;
import inet.networklayer.ipv4.RoutingTable;
import inet.nodes.inet.NetworkLayer;
import inet.transport.ITCP;


//
// TODO auto-generated type
//
// Trip1A_a: Constant traffic generator of GOOSE messages
// Trip1A_b: GOOSE traffic generator for fault simulations. Burst GOOSE messages.
module DANP
{
    parameters:
        bool csmacdSupport = default(true);  // by default use CSMA/CD
        string macType = default(csmacdSupport ? "EtherMAC" : "EtherMACFullDuplex"); // ~EtherMAC or ~EtherMACFullDuplex
        //string macType = default(csmacdSupport ? "EtherMACDANP" : "EtherMACFullDuplex"); // ~EtherMAC or ~EtherMACFullDuplex
        string tcpType = default(firstAvailable("TCP", "TCP_lwIP", "TCP_NSC", "TCP_None"));  // tcp implementation (e.g. ~TCP, ~TCP_lwIP, ~TCP_NSC) or ~TCPSpoof
        string queueType = default("DropTailQueue"); // DropTailQueue, DiffServQueue, or "" to use the internal queue
        @display("bgb=364,585");
    gates:
        inout ethgL1 @labels(EtherFrame-conn);
        inout ethgL2 @labels(EtherFrame-conn);
    submodules:
        interfaceTable: InterfaceTable {
            @display("p=57,169");
        }
        routingTable: RoutingTable {
            @display("p=58,243");
        }
        notificationBoard: NotificationBoard {
            @display("p=56,106");
        }
        mac: <macType> like IEtherMAC {
            @display("p=107,534");
        }
        pcapper: Pcapper {
            @display("p=108,458");
        }
        encap: <default("EtherEncap")> like IEtherEncap {
            @display("p=108,361");
        }
        queue: EtherQoSQueue {
            @display("p=46,409");
        }
        lre: LinkRedundancyEntity {
            @display("p=184,293");
        }
        layer8021Q: Layer8021Q {
            @display("p=185,226");
        }
        networkLayer: NetworkLayer {
            @display("p=283,173");
        }
        tcp: <tcpType> like ITCP {
            @display("p=283,105");
        }

        trip1A_a: Iec61850trafgen {
            @display("p=152,47");
        }
        pcapper2: Pcapper {
            @display("p=261,463");
        }
        mac2: <macType> like IEtherMAC {
            @display("p=260,541");
        }
        queue2: EtherQoSQueue {
            @display("p=206,417");
        }
        encap2: <default("EtherEncap")> like IEtherEncap {
            @display("p=262,363");
        }
        trip1A_b: Iec61850trafgen {
            @display("p=218,47");
        }
    connections allowunconnected:
        mac.phys <--> ethgL1;
        mac2.phys <--> ethgL2;
        pcapper.lowerOut --> mac.upperLayerIn;
        mac.upperLayerOut --> pcapper.lowerIn;
        pcapper.upperOut --> encap.lowerLayerIn;
        encap.lowerLayerOut --> pcapper.upperIn if queueType == "";
        encap.lowerLayerOut --> queue.in if queueType != "";
        queue.out --> pcapper.upperIn if queueType != "";
        layer8021Q.toNetLayer --> networkLayer.ifIn++;
        tcp.ipOut --> networkLayer.tcpIn;
        networkLayer.tcpOut --> tcp.ipIn;
        networkLayer.ifOut++ --> layer8021Q.fromNetLayer;
        lre.toLan1 --> encap.upperLayerIn;
        encap.upperLayerOut --> lre.fromLan1;
        layer8021Q.toEncapLayer --> lre.fromUpperLayer;
        lre.toLowerLayer --> layer8021Q.fromEncapLayer;
        layer8021Q.toEthApp_a --> trip1A_a.in;
        trip1A_a.out --> layer8021Q.fromEthApp_a;
        pcapper2.lowerOut --> mac2.upperLayerIn;
        mac2.upperLayerOut --> pcapper2.lowerIn;
        pcapper2.upperOut --> encap2.lowerLayerIn;
        lre.toLan2 --> encap2.upperLayerIn;
        encap2.upperLayerOut --> lre.fromLan2;
        encap2.lowerLayerOut --> pcapper2.upperIn if queueType == "";
        encap2.lowerLayerOut --> queue2.in if queueType != "";
        queue2.out --> pcapper2.upperIn if queueType != "";
        trip1A_b.out --> layer8021Q.fromEthApp_b;
        layer8021Q.toEthApp_b --> trip1A_b.in;
}
