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
// @author David L. Acosta M. dlacos@gteccom.uff.br

package iec61850model.simulations.SAS;

import iec61850model.linklayer.ieee8021QConfigurator.Ieee8021QConfigurator;
import iec61850model.nodes.Server;
import iec61850model.nodes.ethernet.EnhancedSwitch;
import iec61850model.sas.RingZone;
import iec61850model.sas.StarZone;
import inet.networklayer.autorouting.ipv4.IPv4NetworkConfigurator;
import iec61850model.sas.C;

import ned.DatarateChannel;

//
// TODO auto-generated type
//
network StarStar
{
    parameters:
        int numStarZones = default(1); 	// Each zone will have 1 switch connected to the main switch. 
        								// Inside the zone the IEDs will be connected using STAR topology       

        int nBkIEDZone = default(2);  	// Number of Breaker IEDs per zone
        int nCtrlIEDZone = default(2); 	// Number of Protection and Control IED per zone
        int nMUZone = default(1); 		// Number of Merging Unit per zone        
    submodules:
        iPv4NetworkConfigurator: IPv4NetworkConfigurator {
            @display("p=82,31");
        }
        zone[numStarZones]: StarZone {
            parameters:
                numPCIED = nCtrlIEDZone;
                numBkIED = nBkIEDZone;
                numMU = nMUZone;
                @display("p=255,66,c");
        }
        ieee8021QConfigurator: Ieee8021QConfigurator {
            @display("p=78,88;is=s");
        }
        switch: EnhancedSwitch {
            @display("p=387,71");
        }
        server: Server {
            @display("p=491,40");
        }
    connections:
        for i=0..numStarZones-1 {
            switch.ethg++ <--> C <--> zone[i].eth;
        }

        server.ethg <--> C <--> switch.ethg++;
}
//
// TODO documentation
//
network RingStar
{
    parameters:
        int numStarZones = default(1); 	// Each zone will have 1 switch connected to the main switch. 
        								// Inside the zone the IEDs will be connected using STAR topology

        int nBkIEDZone = default(2);  	// Number of Breaker IEDs per zone
        int nCtrlIEDZone = default(2); 	// Number of Protection and Control IED per zone
        int nMUZone = default(1); 		// Number of Merging Unit per zone        
    submodules:
        iPv4NetworkConfigurator: IPv4NetworkConfigurator {
            @display("p=82,31");
        }
        zone[numStarZones]: StarZone {
            parameters:
                numPCIED = nCtrlIEDZone;
                numBkIED = nBkIEDZone;
                numMU = nMUZone;
                @display("p=255,66,c");
        }
        ieee8021QConfigurator: Ieee8021QConfigurator {
            @display("p=78,88;is=s");
        }
        switch: EnhancedSwitch {
            @display("p=387,71");
        }
        server: Server {
            @display("p=491,40");
        }
    connections:
        switch.ethg++ <--> C <--> zone[0].eth if numStarZones>0;
        //starZone[0].eth2 <--> eth100MbpsChannel <--> 
        server.ethg <--> C <--> switch.ethg++;

        //StarZone switches connections to backbone ring
        for i=0..numStarZones-2 {
            zone[i].eth2 <--> C <--> zone[i+1].eth if numStarZones>0;
        }
        zone[numStarZones-1].eth2 <--> C <--> switch.ethg++ if numStarZones>0;
}

//
// TODO documentation
//
network StarRing
{
    parameters:
        int numRingZones = default(1); 	// Each zone will have 1 switch connected to the main switch. 
        								// Inside the zone the IEDs will be connected using RING topology

        int nBkIEDZone = default(2);  	// Number of Breaker IEDs per zone
        int nCtrlIEDZone = default(2); 	// Number of Protection and Control IED per zone
        int nMUZone = default(1); 		// Number of Merging Unit per zone        
    submodules:
        iPv4NetworkConfigurator: IPv4NetworkConfigurator {
            @display("p=82,31");
        }
        ieee8021QConfigurator: Ieee8021QConfigurator {
            @display("p=78,88;is=s");
        }
        switch: EnhancedSwitch {
            @display("p=387,71");
        }
        server: Server {
            @display("p=491,40");
        }
        zone[numRingZones]: RingZone {
            @display("p=255,44");
        }
    connections:
        for i=0..numRingZones-1 {
            switch.ethg++ <--> C <--> zone[i].eth;
        }
        server.ethg <--> C <--> switch.ethg++;
}

network HybridStar
{
    parameters:
        int numStarZones = default(1); 	// Each zone will have 1 switch connected to the main switch. 
        								// Inside the zone the IEDs will be connected using STAR topology

        int nBkIEDZone = default(2);  	// Number of Breaker IEDs per zone
        int nCtrlIEDZone = default(2); 	// Number of Protection and Control IED per zone
        int nMUZone = default(1); 		// Number of Merging Unit per zone        
        @display("bgb=410,236");
    submodules:
        iPv4NetworkConfigurator: IPv4NetworkConfigurator {
            @display("p=82,31");
        }
        ieee8021QConfigurator: Ieee8021QConfigurator {
            @display("p=78,88;is=s");
        }
        switch: EnhancedSwitch {
            @display("p=216,104");
        }
        server: Server {
            @display("p=315,44");
        }
        zone[numStarZones]: StarZone {
            numPCIED = nCtrlIEDZone;
            numBkIED = nBkIEDZone;
            numMU = nMUZone;
            @display("p=135,193,r");
        }
        switch_S: EnhancedSwitch {
            @display("p=325,104");
        }
    connections:
        for i=0..numStarZones-1 {
            switch.ethg++ <--> C <--> zone[i].eth;
            switch_S.ethg++ <--> C <--> zone[i].eth2;
        }
        server.ethg <--> C <--> switch.ethg++;
        switch_S.ethg++ <--> C <--> switch.ethg++;
}
