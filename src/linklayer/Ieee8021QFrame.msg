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

//
// TODO generated message class
//
cplusplus {{
#include "MACAddress.h"
}}
class noncobject MACAddress;

packet Ieee8021QFrame{
    //@customize(true);
	MACAddress dest;
    MACAddress src;    
    unsigned int tpid = 0x8100; //0x8100 to identify the 802.1Q 
    unsigned int priority;
    unsigned int cfi;
    unsigned int vid;
    unsigned int etherType;
    unsigned int frameByteLength;  // frame length without physical layer overhead (preamble, SFD, carrier extension); used by MAC layer   
}
