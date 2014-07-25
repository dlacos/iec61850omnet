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

package iec61850model.tests.substationTest;

import iec61850model.electricSubstation.ISubstationTopology;


network Substation
{
    parameters:
        string stationTopology =  default(firstAvailable("Star","Ring")); 
        string processTopology = default(firstAvailable("Star","Ring"));
    	@display("bgb=247,177");
    submodules:
        iSubstationTopology: <stationTopology> like ISubstationTopology {
            parameters:
                nF=2;
                nT=2;
            	@display("p=125,75");
        }
}
