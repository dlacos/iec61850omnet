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

package iec61850model.tests.prp;

import iec61850model.devices.Switch;
import iec61850model.prp.DANP;
import inet.nodes.ethernet.EtherSwitch;


//
// TODO documentation
//
network prpTesteEtherSwitch
{
    @display("bgb=519,331");
    submodules:
        danp: DANP {
            @display("p=262,50");
        }
        danp1: DANP {
            @display("p=248,281");
        }
        etherSwitch: EtherSwitch {
            @display("p=117,105");
        }
        etherSwitch1: EtherSwitch {
            @display("p=359,107");
        }
        etherSwitch2: EtherSwitch {
            @display("p=293,192");
        }
        etherSwitch3: EtherSwitch {
            @display("p=440,198");
        }
        etherSwitch4: EtherSwitch {
            @display("p=59,185");
        }
        etherSwitch5: EtherSwitch {
            @display("p=164,182");
        }
    connections:
        danp.ethgL1 <--> etherSwitch.ethg++;
        danp.ethgL2 <--> etherSwitch1.ethg++;
        etherSwitch.ethg++ <--> etherSwitch4.ethg++;
        etherSwitch.ethg++ <--> etherSwitch5.ethg++;
        etherSwitch5.ethg++ <--> danp1.ethgL1;
        etherSwitch1.ethg++ <--> etherSwitch2.ethg++;
        etherSwitch1.ethg++ <--> etherSwitch3.ethg++;
        etherSwitch2.ethg++ <--> danp1.ethgL2;
        etherSwitch2.ethg++ <--> etherSwitch3.ethg++;
}

//
// TODO auto-generated type
//
network prpTesteIecSwitch
{
    @display("bgb=691,327");
    submodules:
        danp: DANP {
            @display("p=294,76");
        }
        switch: Switch {
            @display("p=147,162");
        }
        switch1: Switch {
            @display("p=461,153");
        }
        switch2: Switch {
            @display("p=391,221");
        }
        switch3: Switch {
            @display("p=533,219");
        }
        switch4: Switch {
            @display("p=66,235");
        }
        switch5: Switch {
            @display("p=213,235");
        }
        danp1: DANP {
            @display("p=311,299");
        }
    connections:
        danp.ethgL1 <--> switch.ethg++;
        danp.ethgL2 <--> switch1.ethg++;
        switch1.ethg++ <--> switch2.ethg++;
        switch1.ethg++ <--> switch3.ethg++;
        switch2.ethg++ <--> switch3.ethg++;
        switch.ethg++ <--> switch4.ethg++;
        switch.ethg++ <--> switch5.ethg++;
        switch2.ethg++ <--> danp1.ethgL2;
        switch5.ethg++ <--> danp1.ethgL1;
}
