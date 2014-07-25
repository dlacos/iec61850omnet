// Copyright (C) 2013 David L. Acosta M.
// Copyright (C) Universidade Federal Fluminense
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

package iec61850model.linklayer;

// Partial implementation of IEEE802.1Q layer for Intelligent Electronic Devices (IEC), used in Substation Automation System.
// Functions: Handles frames with IEEE802.1Q format.
// Frame received from upper layers
// - If a 1Q frame is received, it will be encapsulated in a compatible OMNET++ EtherIIframe.
// - If a non 1Q frame is received it will be send without modification to the corresponting gate.
//
// Frame received from lower layers
// - If a 1Q frame is received, it will be decapsulated in a compatible OMNET++ upper layer message.
// - If a non 1Q frame is received it will be send without modification to the corresponting gate.
//
simple Layer8021Q
{
    parameters:
        bool enabled = default(false);        
        int vid = default(1); //
        @display("i=block/classifier2");
    gates:
        input fromEthApp_a @labels(Ieee802Ctrl/up);
        output toEthApp_a @labels(Ieee802Ctrl/down);
        input fromEthApp_b @labels(Ieee802Ctrl/up) @loose; //Future implementations
        output toEthApp_b @labels(Ieee802Ctrl/down) @loose; //Future implementations
        input fromNetLayer @labels(IPv4Datagram);
        output toNetLayer @labels(IPv4Datagram);
        input fromEncapLayer @labels(Ieee802Ctrl/up);
        output toEncapLayer @labels(Ieee802Ctrl/down);
}
