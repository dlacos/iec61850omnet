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

package iec61850model.tests.SubstationNetworkTopologies;
import iec61850model.electricSubstation.ISubstationTopology;
import inet.world.scenario.ScenarioManager;


//
// TODO auto-generated type
//
network SubstationTest
{
    parameters:
        string substationTopology;
        int numF; // number of Feeder Bays in the substation
        int numT; // number of Transformer Bays in the substation
        //int numBkIED; // number of Breaker IEDs per bay (default=1) Bay Parameter 
        //int numPCIED; // number of Protection & Control IEDs per bay (default=2) Bay Parameter 
        // channel; Bandwidth. TODO
        @display("bgb=181,159");
    submodules:
        iSubstationTopology: <substationTopology> like ISubstationTopology {
            parameters:
                nT = numT;
                nF = numF;
                @display("p=91,80");
        }
}
