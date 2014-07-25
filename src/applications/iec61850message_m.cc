//
// Generated file, do not edit! Created by opp_msgc 4.3 from applications/iec61850message.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "iec61850message_m.h"

// Template rule which fires if a struct or class doesn't have operator<<
template<typename T>
std::ostream& operator<<(std::ostream& out,const T&) {return out;}

// Another default rule (prevents compiler from choosing base class' doPacking())
template<typename T>
void doPacking(cCommBuffer *, T& t) {
    throw cRuntimeError("Parsim error: no doPacking() function for type %s or its base class (check .msg and _m.cc/h files!)",opp_typename(typeid(t)));
}

template<typename T>
void doUnpacking(cCommBuffer *, T& t) {
    throw cRuntimeError("Parsim error: no doUnpacking() function for type %s or its base class (check .msg and _m.cc/h files!)",opp_typename(typeid(t)));
}




Register_Class(Iec61850message);

Iec61850message::Iec61850message(const char *name, int kind) : cPacket(name,kind)
{
    this->vid_var = 0;
    this->priority_var = 0;
    this->eType_var = 0;
    this->tci_var = 0;
    this->timeStamp_var = 0;
    content_arraysize = 0;
    this->content_var = 0;
}

Iec61850message::Iec61850message(const Iec61850message& other) : cPacket(other)
{
    content_arraysize = 0;
    this->content_var = 0;
    copy(other);
}

Iec61850message::~Iec61850message()
{
    delete [] content_var;
}

Iec61850message& Iec61850message::operator=(const Iec61850message& other)
{
    if (this==&other) return *this;
    cPacket::operator=(other);
    copy(other);
    return *this;
}

void Iec61850message::copy(const Iec61850message& other)
{
    this->vid_var = other.vid_var;
    this->priority_var = other.priority_var;
    this->eType_var = other.eType_var;
    this->tci_var = other.tci_var;
    this->timeStamp_var = other.timeStamp_var;
    delete [] this->content_var;
    this->content_var = (other.content_arraysize==0) ? NULL : new unsigned char[other.content_arraysize];
    content_arraysize = other.content_arraysize;
    for (unsigned int i=0; i<content_arraysize; i++)
        this->content_var[i] = other.content_var[i];
}

void Iec61850message::parsimPack(cCommBuffer *b)
{
    cPacket::parsimPack(b);
    doPacking(b,this->vid_var);
    doPacking(b,this->priority_var);
    doPacking(b,this->eType_var);
    doPacking(b,this->tci_var);
    doPacking(b,this->timeStamp_var);
    b->pack(content_arraysize);
    doPacking(b,this->content_var,content_arraysize);
}

void Iec61850message::parsimUnpack(cCommBuffer *b)
{
    cPacket::parsimUnpack(b);
    doUnpacking(b,this->vid_var);
    doUnpacking(b,this->priority_var);
    doUnpacking(b,this->eType_var);
    doUnpacking(b,this->tci_var);
    doUnpacking(b,this->timeStamp_var);
    delete [] this->content_var;
    b->unpack(content_arraysize);
    if (content_arraysize==0) {
        this->content_var = 0;
    } else {
        this->content_var = new unsigned char[content_arraysize];
        doUnpacking(b,this->content_var,content_arraysize);
    }
}

int Iec61850message::getVid() const
{
    return vid_var;
}

void Iec61850message::setVid(int vid)
{
    this->vid_var = vid;
}

int Iec61850message::getPriority() const
{
    return priority_var;
}

void Iec61850message::setPriority(int priority)
{
    this->priority_var = priority;
}

int Iec61850message::getEType() const
{
    return eType_var;
}

void Iec61850message::setEType(int eType)
{
    this->eType_var = eType;
}

int Iec61850message::getTci() const
{
    return tci_var;
}

void Iec61850message::setTci(int tci)
{
    this->tci_var = tci;
}

double Iec61850message::getTimeStamp() const
{
    return timeStamp_var;
}

void Iec61850message::setTimeStamp(double timeStamp)
{
    this->timeStamp_var = timeStamp;
}

void Iec61850message::setContentArraySize(unsigned int size)
{
    unsigned char *content_var2 = (size==0) ? NULL : new unsigned char[size];
    unsigned int sz = content_arraysize < size ? content_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        content_var2[i] = this->content_var[i];
    for (unsigned int i=sz; i<size; i++)
        content_var2[i] = 0;
    content_arraysize = size;
    delete [] this->content_var;
    this->content_var = content_var2;
}

unsigned int Iec61850message::getContentArraySize() const
{
    return content_arraysize;
}

unsigned char Iec61850message::getContent(unsigned int k) const
{
    if (k>=content_arraysize) throw cRuntimeError("Array of size %d indexed by %d", content_arraysize, k);
    return content_var[k];
}

void Iec61850message::setContent(unsigned int k, unsigned char content)
{
    if (k>=content_arraysize) throw cRuntimeError("Array of size %d indexed by %d", content_arraysize, k);
    this->content_var[k] = content;
}

class Iec61850messageDescriptor : public cClassDescriptor
{
  public:
    Iec61850messageDescriptor();
    virtual ~Iec61850messageDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(Iec61850messageDescriptor);

Iec61850messageDescriptor::Iec61850messageDescriptor() : cClassDescriptor("Iec61850message", "cPacket")
{
}

Iec61850messageDescriptor::~Iec61850messageDescriptor()
{
}

bool Iec61850messageDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<Iec61850message *>(obj)!=NULL;
}

const char *Iec61850messageDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int Iec61850messageDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 6+basedesc->getFieldCount(object) : 6;
}

unsigned int Iec61850messageDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISARRAY | FD_ISEDITABLE,
    };
    return (field>=0 && field<6) ? fieldTypeFlags[field] : 0;
}

const char *Iec61850messageDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "vid",
        "priority",
        "eType",
        "tci",
        "timeStamp",
        "content",
    };
    return (field>=0 && field<6) ? fieldNames[field] : NULL;
}

int Iec61850messageDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='v' && strcmp(fieldName, "vid")==0) return base+0;
    if (fieldName[0]=='p' && strcmp(fieldName, "priority")==0) return base+1;
    if (fieldName[0]=='e' && strcmp(fieldName, "eType")==0) return base+2;
    if (fieldName[0]=='t' && strcmp(fieldName, "tci")==0) return base+3;
    if (fieldName[0]=='t' && strcmp(fieldName, "timeStamp")==0) return base+4;
    if (fieldName[0]=='c' && strcmp(fieldName, "content")==0) return base+5;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *Iec61850messageDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "int",
        "int",
        "int",
        "double",
        "unsigned char",
    };
    return (field>=0 && field<6) ? fieldTypeStrings[field] : NULL;
}

const char *Iec61850messageDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

int Iec61850messageDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    Iec61850message *pp = (Iec61850message *)object; (void)pp;
    switch (field) {
        case 5: return pp->getContentArraySize();
        default: return 0;
    }
}

std::string Iec61850messageDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    Iec61850message *pp = (Iec61850message *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getVid());
        case 1: return long2string(pp->getPriority());
        case 2: return long2string(pp->getEType());
        case 3: return long2string(pp->getTci());
        case 4: return double2string(pp->getTimeStamp());
        case 5: return ulong2string(pp->getContent(i));
        default: return "";
    }
}

bool Iec61850messageDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    Iec61850message *pp = (Iec61850message *)object; (void)pp;
    switch (field) {
        case 0: pp->setVid(string2long(value)); return true;
        case 1: pp->setPriority(string2long(value)); return true;
        case 2: pp->setEType(string2long(value)); return true;
        case 3: pp->setTci(string2long(value)); return true;
        case 4: pp->setTimeStamp(string2double(value)); return true;
        case 5: pp->setContent(i,string2ulong(value)); return true;
        default: return false;
    }
}

const char *Iec61850messageDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldStructNames[] = {
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
    };
    return (field>=0 && field<6) ? fieldStructNames[field] : NULL;
}

void *Iec61850messageDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    Iec61850message *pp = (Iec61850message *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}


