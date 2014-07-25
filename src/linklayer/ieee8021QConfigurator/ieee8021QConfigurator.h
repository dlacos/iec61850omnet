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

#ifndef __IEC61850MODEL_IEEE8021QCONFIGURATOR_H_
#define __IEC61850MODEL_IEEE8021QCONFIGURATOR_H_

#include <omnetpp.h>
#include "MACAddress.h"
//#include "Table1Q.h"

#define MAX_LINE 100

/**
 * TODO - Generated class
 */
class Ieee8021QConfigurator : public cSimpleModule
{
public:
    typedef struct MacVidGroup{
            unsigned int Vid;
            MACAddress MAC;
            MACAddress MCGroup;
            simtime_t inserted;
        } Table8021QEntry;        /// Table 802.1Q entry
public:
    Ieee8021QConfigurator();
    ~Ieee8021QConfigurator();
    std::vector <Table8021QEntry> Table1Q;
    //const std::vector<Table8021QEntry>& getResults() {return TableMacVid;}
    static char *fgetline(FILE *fp)
        {
            // alloc buffer and read a line
            char *line = new char[MAX_LINE];
            if (fgets(line, MAX_LINE, fp)==NULL)
            {
                delete [] line;
                return NULL;
            }

            // chop CR/LF
            line[MAX_LINE-1] = '\0';
            int len = strlen(line);
            while (len>0 && (line[len-1]=='\n' || line[len-1]=='\r'))
                line[--len] = '\0';

            return line;
        }
protected:
    virtual void initialize(int stage);
    virtual void handleMessage(cMessage *msg);

public:
    virtual void printState();
    virtual void writeEntry(MACAddress mac, int vid);
    virtual bool resolveMACwithVID(unsigned int vid,MACAddress mac);
    virtual void loadTable(const char* fileName);
    //virtual bool resolveMACwithMcast(unsigned int vid,MACAddress mac);
};

#endif
