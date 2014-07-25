//
// Generated file, do not edit! Created by opp_msgc 4.3 from linklayer/Ieee8021QFrame.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "Ieee8021QFrame_m.h"

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




Register_Class(Ieee8021QFrame);

Ieee8021QFrame::Ieee8021QFrame(const char *name, int kind) : cPacket(name,kind)
{
    this->tpid_var = 0x8100;
    this->priority_var = 0;
    this->cfi_var = 0;
    this->vid_var = 0;
    this->etherType_var = 0;
    this->frameByteLength_var = 0;
}

Ieee8021QFrame::Ieee8021QFrame(const Ieee8021QFrame& other) : cPacket(other)
{
    copy(other);
}

Ieee8021QFrame::~Ieee8021QFrame()
{
}

Ieee8021QFrame& Ieee8021QFrame::operator=(const Ieee8021QFrame& other)
{
    if (this==&other) return *this;
    cPacket::operator=(other);
    copy(other);
    return *this;
}

void Ieee8021QFrame::copy(const Ieee8021QFrame& other)
{
    this->dest_var = other.dest_var;
    this->src_var = other.src_var;
    this->tpid_var = other.tpid_var;
    this->priority_var = other.priority_var;
    this->cfi_var = other.cfi_var;
    this->vid_var = other.vid_var;
    this->etherType_var = other.etherType_var;
    this->frameByteLength_var = other.frameByteLength_var;
}

void Ieee8021QFrame::parsimPack(cCommBuffer *b)
{
    cPacket::parsimPack(b);
    doPacking(b,this->dest_var);
    doPacking(b,this->src_var);
    doPacking(b,this->tpid_var);
    doPacking(b,this->priority_var);
    doPacking(b,this->cfi_var);
    doPacking(b,this->vid_var);
    doPacking(b,this->etherType_var);
    doPacking(b,this->frameByteLength_var);
}

void Ieee8021QFrame::parsimUnpack(cCommBuffer *b)
{
    cPacket::parsimUnpack(b);
    doUnpacking(b,this->dest_var);
    doUnpacking(b,this->src_var);
    doUnpacking(b,this->tpid_var);
    doUnpacking(b,this->priority_var);
    doUnpacking(b,this->cfi_var);
    doUnpacking(b,this->vid_var);
    doUnpacking(b,this->etherType_var);
    doUnpacking(b,this->frameByteLength_var);
}

MACAddress& Ieee8021QFrame::getDest()
{
    return dest_var;
}

void Ieee8021QFrame::setDest(const MACAddress& dest)
{
    this->dest_var = dest;
}

MACAddress& Ieee8021QFrame::getSrc()
{
    return src_var;
}

void Ieee8021QFrame::setSrc(const MACAddress& src)
{
    this->src_var = src;
}

unsigned int Ieee8021QFrame::getTpid() const
{
    return tpid_var;
}

void Ieee8021QFrame::setTpid(unsigned int tpid)
{
    this->tpid_var = tpid;
}

unsigned int Ieee8021QFrame::getPriority() const
{
    return priority_var;
}

void Ieee8021QFrame::setPriority(unsigned int priority)
{
    this->priority_var = priority;
}

unsigned int Ieee8021QFrame::getCfi() const
{
    return cfi_var;
}

void Ieee8021QFrame::setCfi(unsigned int cfi)
{
    this->cfi_var = cfi;
}

unsigned int Ieee8021QFrame::getVid() const
{
    return vid_var;
}

void Ieee8021QFrame::setVid(unsigned int vid)
{
    this->vid_var = vid;
}

unsigned int Ieee8021QFrame::getEtherType() const
{
    return etherType_var;
}

void Ieee8021QFrame::setEtherType(unsigned int etherType)
{
    this->etherType_var = etherType;
}

unsigned int Ieee8021QFrame::getFrameByteLength() const
{
    return frameByteLength_var;
}

void Ieee8021QFrame::setFrameByteLength(unsigned int frameByteLength)
{
    this->frameByteLength_var = frameByteLength;
}

class Ieee8021QFrameDescriptor : public cClassDescriptor
{
  public:
    Ieee8021QFrameDescriptor();
    virtual ~Ieee8021QFrameDescriptor();

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

Register_ClassDescriptor(Ieee8021QFrameDescriptor);

Ieee8021QFrameDescriptor::Ieee8021QFrameDescriptor() : cClassDescriptor("Ieee8021QFrame", "cPacket")
{
}

Ieee8021QFrameDescriptor::~Ieee8021QFrameDescriptor()
{
}

bool Ieee8021QFrameDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<Ieee8021QFrame *>(obj)!=NULL;
}

const char *Ieee8021QFrameDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int Ieee8021QFrameDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 8+basedesc->getFieldCount(object) : 8;
}

unsigned int Ieee8021QFrameDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISCOMPOUND,
        FD_ISCOMPOUND,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<8) ? fieldTypeFlags[field] : 0;
}

const char *Ieee8021QFrameDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "dest",
        "src",
        "tpid",
        "priority",
        "cfi",
        "vid",
        "etherType",
        "frameByteLength",
    };
    return (field>=0 && field<8) ? fieldNames[field] : NULL;
}

int Ieee8021QFrameDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='d' && strcmp(fieldName, "dest")==0) return base+0;
    if (fieldName[0]=='s' && strcmp(fieldName, "src")==0) return base+1;
    if (fieldName[0]=='t' && strcmp(fieldName, "tpid")==0) return base+2;
    if (fieldName[0]=='p' && strcmp(fieldName, "priority")==0) return base+3;
    if (fieldName[0]=='c' && strcmp(fieldName, "cfi")==0) return base+4;
    if (fieldName[0]=='v' && strcmp(fieldName, "vid")==0) return base+5;
    if (fieldName[0]=='e' && strcmp(fieldName, "etherType")==0) return base+6;
    if (fieldName[0]=='f' && strcmp(fieldName, "frameByteLength")==0) return base+7;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *Ieee8021QFrameDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "MACAddress",
        "MACAddress",
        "unsigned int",
        "unsigned int",
        "unsigned int",
        "unsigned int",
        "unsigned int",
        "unsigned int",
    };
    return (field>=0 && field<8) ? fieldTypeStrings[field] : NULL;
}

const char *Ieee8021QFrameDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int Ieee8021QFrameDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    Ieee8021QFrame *pp = (Ieee8021QFrame *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string Ieee8021QFrameDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    Ieee8021QFrame *pp = (Ieee8021QFrame *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->getDest(); return out.str();}
        case 1: {std::stringstream out; out << pp->getSrc(); return out.str();}
        case 2: return ulong2string(pp->getTpid());
        case 3: return ulong2string(pp->getPriority());
        case 4: return ulong2string(pp->getCfi());
        case 5: return ulong2string(pp->getVid());
        case 6: return ulong2string(pp->getEtherType());
        case 7: return ulong2string(pp->getFrameByteLength());
        default: return "";
    }
}

bool Ieee8021QFrameDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    Ieee8021QFrame *pp = (Ieee8021QFrame *)object; (void)pp;
    switch (field) {
        case 2: pp->setTpid(string2ulong(value)); return true;
        case 3: pp->setPriority(string2ulong(value)); return true;
        case 4: pp->setCfi(string2ulong(value)); return true;
        case 5: pp->setVid(string2ulong(value)); return true;
        case 6: pp->setEtherType(string2ulong(value)); return true;
        case 7: pp->setFrameByteLength(string2ulong(value)); return true;
        default: return false;
    }
}

const char *Ieee8021QFrameDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldStructNames[] = {
        "MACAddress",
        "MACAddress",
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
    };
    return (field>=0 && field<8) ? fieldStructNames[field] : NULL;
}

void *Ieee8021QFrameDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    Ieee8021QFrame *pp = (Ieee8021QFrame *)object; (void)pp;
    switch (field) {
        case 0: return (void *)(&pp->getDest()); break;
        case 1: return (void *)(&pp->getSrc()); break;
        default: return NULL;
    }
}


