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

#include "table8021Q.h"

Define_Module(Table8021Q);

Table8021Q::Table8021Q()
{
}
Table8021Q::~Table8021Q()
{
}
void Table8021Q::initialize()
{
    // TODO - Generated method body
    agingTime=(simtime_t) par("agingTime");
    verbose=(bool) par ("verbose");
    const char *tableFileName = par("tableFileName");
    if (tableFileName && *tableFileName)
        loadTable(tableFileName);
}

void Table8021Q::handleMessage(cMessage *msg)
{
    // TODO - Generated method body
    opp_error("This module does not process messages");
}

void Table8021Q::printState()
{
    ev<<endl<<"Table 802.1Q (MAC Vid)"<<endl;
    ev<<"MAC    Vid"<<endl;
    for(unsigned int i=0;i<TableMacVid.size();i++)
    {
        ev<<TableMacVid[i].MAC<<"   "<<TableMacVid[i].Vid<<endl;
    }
}

bool Table8021Q::resolveMAC(unsigned int vid,MACAddress mac)
{
    ev<<"Looking for MAC VID"<<endl;
    for(unsigned int i=0; i<TableMacVid.size(); i++)
    {
        if(mac == TableMacVid[i].MAC)
        {
            if(vid == TableMacVid[i].Vid)
            {
                return true;
            }
        }
    }
    return false;
}


void Table8021Q::loadTable(const char* fileName)
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

        // empty line?
        if (!hexaddress)
            continue;

        // broken line?
        if (!vidlan)
            error("line %d invalid in address table file `%s'", lineno, fileName);

        // Create an entry with MAC-vid and insert  it
        Table8021QEntry tableEntry;
        tableEntry.inserted = 0;
        tableEntry.Vid = atoi(vidlan);
        tableEntry.MAC = MACAddress(hexaddress);
        TableMacVid.push_back(tableEntry);
        //this->TableMacVid[MACAddress(hexaddress)] = tableEntry;
        ev <<"Vid: "<< tableEntry.Vid << endl;
        ev <<"MAC: "<< tableEntry.MAC << endl;
        ev <<"TableMacVidSize: "<< TableMacVid.size()<< endl;

        // Garbage collection before next iteration
        delete [] line;
    }
    fclose(fp);
}
