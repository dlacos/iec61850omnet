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

package iec61850model.linklayer.ethernet.relayUnit;
//import inet.linklayer.IMACRelayUnit;
//
// TODO auto-generated module
//
simple MACRelayUnitHost extends MACRelayUnit1Q
{
    parameters:
        @class(MACRelayUnitHost); //If not explicited, the module will use the parent class (MACRelayUnit1Q) 
    gates:
//        input lowerLayerIn[] @labels(EtherFrame); 
//        output lowerLayerOut[] @labels(EtherFrame); 
        input upperLayerIn @labels(EtherFrame);
        output upperLayerOut @labels(EtherFrame);      
}
