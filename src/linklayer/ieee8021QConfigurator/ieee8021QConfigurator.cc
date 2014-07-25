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

#include "ieee8021QConfigurator.h"

Define_Module(Ieee8021QConfigurator);

Ieee8021QConfigurator::Ieee8021QConfigurator()
{
}
Ieee8021QConfigurator::~Ieee8021QConfigurator()
{
}

void Ieee8021QConfigurator::initialize(int stage)
{
    // TODO - Generated method body
    if (stage == 0) {
        //L2Entry macVidMcast;
        /*Table8021QEntry tableEntry;
        tableEntry.MAC = MACAddress("0aaa00000006");//testing
        tableEntry.MCGroup = MACAddress("0aaa00000006");
        tableEntry.Vid = 1;
        tableEntry.inserted = 0;
        Table1Q.push_back(tableEntry);

        tableEntry.MAC = MACAddress("0aaa00000011");//testing
        tableEntry.MCGroup = MACAddress("0aaa00000011");
        tableEntry.Vid = 1;
        tableEntry.inserted = 0;
        Table1Q.push_back(tableEntry);

        tableEntry.MAC = MACAddress("ffffffffffff");//testing
        tableEntry.MCGroup = MACAddress("ffffffffffff");
        tableEntry.Vid = 1;
        tableEntry.inserted = 0;
        Table1Q.push_back(tableEntry);*/

        // VLANs "manually"
        //Getting the information of IEDs and MUs
        //Updating the map VLAN/MCast/{node1, node2,...}

        //Configuring L2 Multicast Groups "manually"
        const char *tableFileName = par("tableFileName");
        if (tableFileName && *tableFileName)
            loadTable(tableFileName);
        printState();
        //search each ied, mu or stationpc and asign the VID if used
    }
}

void Ieee8021QConfigurator::handleMessage(cMessage *msg)
{
    // TODO - Generated method body
    opp_error("This module does not process messages");
}

void Ieee8021QConfigurator::printState()
{
    ev<<endl<<"Table 802.1Q (MAC Vid Multicast)"<<endl;
    ev<<"MAC    Vid    Multicast"<<endl;
    for(unsigned int i=0;i<Table1Q.size();i++)
    {
        ev<<Table1Q[i].MAC<<"   "<<Table1Q[i].Vid << "   " << Table1Q[i].MCGroup <<endl;
    }
}

bool Ieee8021QConfigurator::resolveMACwithVID(unsigned int vid,MACAddress mac)
{
    ev<<"------- Looking for MAC VID -----"<<endl;
    for(unsigned int i=0; i<Table1Q.size(); i++)
    {
        if(mac == Table1Q[i].MAC)
        {
            if(vid == Table1Q[i].Vid)
            {
                return true;
            }
        }
    }
    return false;
}
void Ieee8021QConfigurator::loadTable(const char* fileName)
{
    FILE *fp = fopen(fileName, "r");
    if (fp == NULL)
        error("cannot open address table file `%s'", fileName);

    //  Syntax of the file goes as:
    //  Address in hexadecimal representation, Portno
    //  ffffffff    1
    //  ffffeed1    2
    //  aabcdeff    3
    //
    //  etc...
    //
    //  Each iteration of the loop reads in an entire line i.e. up to '\n' or EOF characters
    //  and uses strtok to extract tokens from the resulting string
    char *line;
    int lineno = 0;
    while ((line = fgetline(fp)) != NULL)
    {
        lineno++;

        // lines beginning with '#' are treated as comments
        if (line[0]=='#')
            continue;

        // scan in hexaddress
        char *hexaddress = strtok(line, " \t");
        // scan in port number
        char *vidlan = strtok(NULL, " \t");
        // scan in hexaddress
        char *hexmcaddress = strtok(line, " \t");

        // empty line?
        if (!hexaddress)
            continue;

        // broken line?
        if (!vidlan)
            error("line %d invalid in address table file `%s'", lineno, fileName);

        // Create an entry with MAC-vid and insert  it
        Table8021QEntry tableEntry;
        //tableEntry.inserted = 0;
        tableEntry.Vid = atoi(vidlan);
        tableEntry.MAC = MACAddress(hexaddress);
        tableEntry.MCGroup = MACAddress(hexmcaddress);
        Table1Q.push_back(tableEntry);
        //this->TableMacVid[MACAddress(hexaddress)] = tableEntry;
        ev <<"Vid: "<< tableEntry.Vid << endl;
        ev <<"MAC: "<< tableEntry.MAC << endl;
        ev <<"Table1Q: "<< Table1Q.size()<< endl;

        // Garbage collection before next iteration
        delete [] line;
    }
    fclose(fp);
}
void Ieee8021QConfigurator::writeEntry(MACAddress mac, int vid)
{
    Table8021QEntry tableEntry;
    tableEntry.Vid = vid;
    tableEntry.MAC = mac;
    tableEntry.MCGroup = mac;
    Table1Q.push_back(tableEntry);
}
