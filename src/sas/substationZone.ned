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

package iec61850model.sas;

import iec61850model.devices.Mu;
import iec61850model.nodes.ethernet.EnhancedSwitch;
import iec61850model.nodes.iec61850.ied.GenericIED;
import iec61850model.nodes.iec61850.ied.MergingUnit;
import iec61850model.nodes.iec61850.ied.SwitchingIED;


module StarZone
{
    parameters:
        int numPCIED = default(2); // number of Protection & Control IEDs on the substation
        int numBkIED = default(1); // number of Breaker Bays in the substation
        int numMU = default(1);		// Number of Merging Units            
        //int ieee8021QMode = default(0); //Desactivated, normal switch
        @display("bgb=331,201;i=device/mainframe");
    gates:
        inout eth @labels(EtherFrame-conn);
        inout eth2 @labels(EtherFrame-conn) @loose; //Depends of the topology
    submodules:
        breaker[numBkIED]: GenericIED {
            @display("p=64,51,c");
        }
        control[numPCIED]: GenericIED {
            @display("p=124,166,r");
        }
        switch: EnhancedSwitch {
            @display("p=168,64");
        }
        mu[numMU]: MergingUnit {
            @display("p=260,86,c");
        }
    connections allowunconnected:
        for i=0..numPCIED-1 {
            switch.ethg++ <--> C <--> control[i].ethg;
        }
        for i=0..numBkIED-1 {
            switch.ethg++ <--> C <--> breaker[i].ethg;
        }
        for i=0..numMU-1 {
            switch.ethg++ <--> C <--> mu[i].ethg;
        }
        switch.ethg++ <--> eth;
        switch.ethg++ <--> eth2;

}
//
// TODO documentation
//
module RingZone
{
    parameters:
        int numPCIED = default(2); 	// Number of Protection & Control IEDs on the substation
        int numBkIED = default(1); 	// Number of Breaker Bays in the substation
        int numMU = default(1);		// Number of Merging Units    
        @display("bgb=372,203;i=device/mainframe");
    gates:
        inout eth @labels(EtherFrame-conn);
        inout eth2 @labels(EtherFrame-conn) @loose; //Depends of the topology
    submodules:
        switch: EnhancedSwitch {
            @display("p=221,89");
        }
        breaker[numBkIED]: SwitchingIED {
            @display("p=74,46,r");
        }
        control[numPCIED]: SwitchingIED {
            @display("p=174,161,c");
        }
        mu[numMU]: MergingUnit {
            @display("p=302,36,c");
        }
    connections allowunconnected:
        //If there is at least 1 breaker
        switch.ethg++ <--> C <--> breaker[0].ethg[0] if numBkIED>0;
        breaker[numBkIED-1].ethg[1] <--> C <--> control[0].ethg[0] if numBkIED>0 && numPCIED>0;
        control[numPCIED-1].ethg[1] <--> C <--> switch.ethg++ if numBkIED>0 && numPCIED>0;

        //Merging Units connection. Direct to the switch (Star topology)
        for i=0..numMU-1 {
            switch.ethg++ <--> C <--> mu[i].ethg;
        }
        switch.ethg++ <--> eth;
        switch.ethg++ <--> eth2;
}

