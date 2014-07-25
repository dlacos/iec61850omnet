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

package iec61850model.tests.enhancedSwitchTest;

import iec61850model.nodes.ethernet.EnhancedSwitch;
import inet.linklayer.ethernet.EtherQoSQueue;
import inet.networklayer.autorouting.ipv4.IPv4NetworkConfigurator;
import inet.nodes.inet.StandardHost;
import ned.DatarateChannel;

channel C extends DatarateChannel
{
    datarate = 10Mbps;
}
//
// TODO auto-generated type
//
network TwoSwitchesFourHosts
{
    submodules:
        eS1: EnhancedSwitch {
            @display("p=275,109");
        }
        eS2: EnhancedSwitch {
            @display("p=402,107");
        }
        host1: StandardHost {
            @display("p=157,208");
        }
        host2: StandardHost {
            @display("p=244,237");
        }
        host3: StandardHost {
            @display("p=418,259");
        }
        host4: StandardHost {
            @display("p=511,233");
        }
        iPv4NetworkConfigurator: IPv4NetworkConfigurator {
            @display("p=87,54");
        }
    connections:
        eS1.ethg++ <--> C <--> eS2.ethg++;
        eS1.ethg++ <--> C <--> host1.ethg++;
        eS2.ethg++ <--> C <--> host4.ethg++;
        eS1.ethg++ <--> C <--> host2.ethg++;
        eS2.ethg++ <--> C <--> host3.ethg++;
}
