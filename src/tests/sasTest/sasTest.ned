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

package iec61850model.tests.sasTest;

import iec61850model.linklayer.ieee8021QConfigurator.Ieee8021QConfigurator;
import iec61850model.nodes.Server;
import iec61850model.nodes.ethernet.EnhancedSwitch;
import iec61850model.sas.StarZone;
import iec61850model.sas.C;
import inet.networklayer.autorouting.ipv4.IPv4NetworkConfigurator;


//
// TODO auto-generated type
//
network SasTest
{
    @display("bgb=591,262");
    submodules:
        starZone: StarZone {
            @display("p=91,73");
        }
        switch: EnhancedSwitch {
            @display("p=278,63");
        }
        iPv4NetworkConfigurator: IPv4NetworkConfigurator {
            @display("p=529,57");
        }
        ieee8021QConfigurator: Ieee8021QConfigurator {
            @display("p=525,129");
        }
        server: Server {
            @display("p=390,47");
        }
    connections:
        switch.ethg++ <--> C <--> starZone.eth;
        switch.ethg++ <--> C <--> server.ethg;
}
