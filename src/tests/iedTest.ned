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

package iec61850model.tests;

import iec61850model.devices.Ied;
import iec61850model.devices.Switch;
import inet.networklayer.autorouting.ipv4.IPv4NetworkConfigurator;
import inet.nodes.ethernet.EtherSwitch;
import inet.nodes.inet.Router;
import inet.nodes.inet.StandardHost;


//
// TODO auto-generated type
//
network StarStar
{
    @display("bgb=658,330");
    submodules:
        iPv4NetworkConfigurator: IPv4NetworkConfigurator {
            @display("p=90,52");
            config = xmldoc("config.xml");
        }
        ied1: Ied {
            @display("p=176,248");
        }
        s1: EtherSwitch {
            @display("p=306,99");
        }
        s2: EtherSwitch {
            @display("p=232,174");
        }
        s3: EtherSwitch {
            @display("p=386,174");
        }
        ied3: Ied {
            @display("p=353,248");
        }
        ied2: Ied {
            @display("p=267,248");
        }
        ied4: Ied {
            @display("p=437,248");
        }
        host1: StandardHost {
            parameters:
                numPingApps = default(1);
                @display("p=518,181");
        }
        router: Router {
            @display("p=518,52");
        }
    connections:
        s1.ethg++ <--> eth100MbpsChannel <--> s2.ethg++;
        s1.ethg++ <--> eth100MbpsChannel <--> s3.ethg++;
        s2.ethg++ <--> eth100MbpsChannel <--> ied1.ethg;
        s3.ethg++ <--> eth100MbpsChannel <--> ied3.ethg;
        s2.ethg++ <--> eth100MbpsChannel <--> ied2.ethg;
        s3.ethg++ <--> eth100MbpsChannel <--> ied4.ethg;
        s3.ethg++ <--> eth100MbpsChannel <--> host1.ethg++;
        router.ethg++ <--> eth100MbpsChannel <--> s1.ethg++;
}
//
// TODO documentation
//
network RingStar
{
    @display("bgb=658,261");
    submodules:
        s1: Switch {
            @display("p=329,55");
        }
        s2: Switch {
            @display("p=233,123");
        }
        s3: Switch {
            @display("p=417,123");
        }
        ied1: Ied {
            @display("p=177,196");
        }
        ied2: Ied {
            @display("p=273,196");
        }
        ied3: Ied {
            @display("p=370,196");
        }
        ied4: Ied {
            @display("p=435,196");
        }
        iPv4NetworkConfigurator: IPv4NetworkConfigurator {
            @display("p=85,53");
        }
    connections:
        s1.ethg++ <--> s2.ethg++;
        s1.ethg++ <--> s3.ethg++;
        s2.ethg++ <--> s3.ethg++;
        s2.ethg++ <--> ied1.ethg;
        s2.ethg++ <--> ied2.ethg;
        s3.ethg++ <--> ied3.ethg;
        s3.ethg++ <--> ied4.ethg;
}

