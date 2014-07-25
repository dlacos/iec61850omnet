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

package iec61850model.nodes.iec61850.ied;

import iec61850model.applications.Iec61850trafgen;
import iec61850model.linklayer.Layer8021Q;
import iec61850model.linklayer.ethernet.Ethernet1QInterface;
import iec61850model.linklayer.ethernet.relayUnit.MACRelayUnitHost;
import iec61850model.nodes.iec61850.ied.applicationProfile.goose.GOOSEApp;
import inet.applications.ITCPApp;
import inet.applications.ethernet.EtherTrafGen;
import inet.applications.generic.IIPvXTrafficGenerator;
import inet.base.NotificationBoard;
import inet.linklayer.IMACRelayUnit;
import inet.linklayer.ethernet.IEtherEncap;
import inet.networklayer.common.InterfaceTable;
import inet.networklayer.ipv4.RoutingTable;
import inet.nodes.inet.NetworkLayer;
import inet.transport.ITCP;


module SwitchingIED
{
    parameters:
        string relayUnitType = default("MACRelayUnitHost"); // type of the ~IMACRelayUnit; currently possible
                                                          // values are ~MACRelayUnitNP and ~MACRelayUnitPP
        string tcpType = default(firstAvailable("TCP", "TCP_lwIP", "TCP_NSC", "TCP_None"));  // tcp implementation (e.g. ~TCP, ~TCP_lwIP, ~TCP_NSC) or ~TCPSpoof
        string ipBurstType = default("IPvXTrafGen");
        string tcpApp = default("TCPBasicClientApp");
        @node();
        @labels(node,ethernet-node);
        @display("i=device/device;bgb=406,584");
    gates:
        inout ethg[2] @labels(EtherFrame-conn) @loose;
    submodules:
        interfaceTable: InterfaceTable {
            @display("p=306,450");
        }
        routingTable: RoutingTable {
            @display("p=306,363");
        }
        notificationBoard: NotificationBoard {
            @display("p=306,528");
        }
        eth1: Ethernet1QInterface {
            @display("p=121,538");
        }
        eth2: Ethernet1QInterface {
            @display("p=220,535");
        }
        relayUnit: MACRelayUnitHost {
            parameters:
                @display("p=169,460");
            gates:
                lowerLayerIn[sizeof(ethg)];
                lowerLayerOut[sizeof(ethg)];
        }
        encap: <default("EtherEncap")> like IEtherEncap {
            @display("p=171,388");
        }
        layer8021Q: Layer8021Q {
            @display("p=174,321");
        }
        //        iec61850trafgen: Iec61850trafgen {
        //            @display("p=72,179");
        //        }
        networkLayer: NetworkLayer {
            parameters:
                proxyARP = default(false);
                igmpType = default("IGMPv2");
                @display("p=257,240");
        }
        tcp: <tcpType> like ITCP {
            @display("p=243,154");
        }
        //        mms: <default("TCPBasicClientApp")> like ITCPApp {
        //            parameters:
        //                @display("p=259,87");
        //        }
        IPburst: <ipBurstType> like IIPvXTrafficGenerator {
            @display("p=325,66");
        }
        gooseApp: GOOSEApp {
            @display("p=169,59");
        }
        mmsApp: <tcpApp> like ITCPApp {
            @display("p=246,65");
        }
    connections allowunconnected:
        relayUnit.lowerLayerOut[0] --> eth1.upperLayerIn;
        relayUnit.lowerLayerOut[1] --> eth2.upperLayerIn;
        eth1.phys <--> ethg[0];
        eth2.phys <--> ethg[1];
        eth1.upperLayerOut --> relayUnit.lowerLayerIn[0];
        eth2.upperLayerOut --> relayUnit.lowerLayerIn[1];
        encap.upperLayerOut --> layer8021Q.fromEncapLayer;
        layer8021Q.toEncapLayer --> encap.upperLayerIn;
        networkLayer.ifOut++ --> layer8021Q.fromNetLayer;
        layer8021Q.toNetLayer --> networkLayer.ifIn++;
        tcp.ipOut --> networkLayer.tcpIn;
        networkLayer.tcpOut --> tcp.ipIn;
        encap.lowerLayerOut --> relayUnit.upperLayerIn;
        relayUnit.upperLayerOut --> encap.lowerLayerIn;
        //iec61850trafgen.out --> layer8021Q.fromEthApp_a;
        //layer8021Q.toEthApp_a --> iec61850trafgen.in;
        IPburst.ipOut --> networkLayer.udpIn;
        networkLayer.udpOut --> IPburst.ipIn;
        gooseApp.out --> layer8021Q.fromEthApp_a;
        layer8021Q.toEthApp_a --> gooseApp.in;
        mmsApp.tcpOut --> tcp.appIn++;
        tcp.appOut++ --> mmsApp.tcpIn;
}
