//
// Generated file, do not edit! Created by opp_msgc 4.3 from nodes/iec61850/ied/applicationProfile/sampledValues/sampledValue.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "sampledValue_m.h"

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




Register_Class(SampledValue);

SampledValue::SampledValue(const char *name, int kind) : cPacket(name,kind)
{
    this->appid_var = 0;
    this->length_var = 0;
    this->reserved1_var = 0;
    this->reserved2_var = 0;
    this->tpid_var = 0;
    this->vid_var = 0;
    this->priority_var = 0;
    this->etherType_var = 0;
    this->cfi_var = 0;
    this->timeStamp_var = 0;
    content_arraysize = 0;
    this->content_var = 0;
}

SampledValue::SampledValue(const SampledValue& other) : cPacket(other)
{
    content_arraysize = 0;
    this->content_var = 0;
    copy(other);
}

SampledValue::~SampledValue()
{
    delete [] content_var;
}

SampledValue& SampledValue::operator=(const SampledValue& other)
{
    if (this==&other) return *this;
    cPacket::operator=(other);
    copy(other);
    return *this;
}

void SampledValue::copy(const SampledValue& other)
{
    this->appid_var = other.appid_var;
    this->length_var = other.length_var;
    this->reserved1_var = other.reserved1_var;
    this->reserved2_var = other.reserved2_var;
    this->tpid_var = other.tpid_var;
    this->vid_var = other.vid_var;
    this->priority_var = other.priority_var;
    this->etherType_var = other.etherType_var;
    this->cfi_var = other.cfi_var;
    this->timeStamp_var = other.timeStamp_var;
    delete [] this->content_var;
    this->content_var = (other.content_arraysize==0) ? NULL : new unsigned char[other.content_arraysize];
    content_arraysize = other.content_arraysize;
    for (unsigned int i=0; i<content_arraysize; i++)
        this->content_var[i] = other.content_var[i];
}

void SampledValue::parsimPack(cCommBuffer *b)
{
    cPacket::parsimPack(b);
    doPacking(b,this->appid_var);
    doPacking(b,this->length_var);
    doPacking(b,this->reserved1_var);
    doPacking(b,this->reserved2_var);
    doPacking(b,this->tpid_var);
    doPacking(b,this->vid_var);
    doPacking(b,this->priority_var);
    doPacking(b,this->etherType_var);
    doPacking(b,this->cfi_var);
    doPacking(b,this->timeStamp_var);
    b->pack(content_arraysize);
    doPacking(b,this->content_var,content_arraysize);
}

void SampledValue::parsimUnpack(cCommBuffer *b)
{
    cPacket::parsimUnpack(b);
    doUnpacking(b,this->appid_var);
    doUnpacking(b,this->length_var);
    doUnpacking(b,this->reserved1_var);
    doUnpacking(b,this->reserved2_var);
    doUnpacking(b,this->tpid_var);
    doUnpacking(b,this->vid_var);
    doUnpacking(b,this->priority_var);
    doUnpacking(b,this->etherType_var);
    doUnpacking(b,this->cfi_var);
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

int SampledValue::getAppid() const
{
    return appid_var;
}

void SampledValue::setAppid(int appid)
{
    this->appid_var = appid;
}

int SampledValue::getLength() const
{
    return length_var;
}

void SampledValue::setLength(int length)
{
    this->length_var = length;
}

int SampledValue::getReserved1() const
{
    return reserved1_var;
}

void SampledValue::setReserved1(int reserved1)
{
    this->reserved1_var = reserved1;
}

int SampledValue::getReserved2() const
{
    return reserved2_var;
}

void SampledValue::setReserved2(int reserved2)
{
    this->reserved2_var = reserved2;
}

int SampledValue::getTpid() const
{
    return tpid_var;
}

void SampledValue::setTpid(int tpid)
{
    this->tpid_var = tpid;
}

int SampledValue::getVid() const
{
    return vid_var;
}

void SampledValue::setVid(int vid)
{
    this->vid_var = vid;
}

int SampledValue::getPriority() const
{
    return priority_var;
}

void SampledValue::setPriority(int priority)
{
    this->priority_var = priority;
}

int SampledValue::getEtherType() const
{
    return etherType_var;
}

void SampledValue::setEtherType(int etherType)
{
    this->etherType_var = etherType;
}

int SampledValue::getCfi() const
{
    return cfi_var;
}

void SampledValue::setCfi(int cfi)
{
    this->cfi_var = cfi;
}

double SampledValue::getTimeStamp() const
{
    return timeStamp_var;
}

void SampledValue::setTimeStamp(double timeStamp)
{
    this->timeStamp_var = timeStamp;
}

void SampledValue::setContentArraySize(unsigned int size)
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

unsigned int SampledValue::getContentArraySize() const
{
    return content_arraysize;
}

unsigned char SampledValue::getContent(unsigned int k) const
{
    if (k>=content_arraysize) throw cRuntimeError("Array of size %d indexed by %d", content_arraysize, k);
    return content_var[k];
}

void SampledValue::setContent(unsigned int k, unsigned char content)
{
    if (k>=content_arraysize) throw cRuntimeError("Array of size %d indexed by %d", content_arraysize, k);
    this->content_var[k] = content;
}

class SampledValueDescriptor : public cClassDescriptor
{
  public:
    SampledValueDescriptor();
    virtual ~SampledValueDescriptor();

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

Register_ClassDescriptor(SampledValueDescriptor);

SampledValueDescriptor::SampledValueDescriptor() : cClassDescriptor("SampledValue", "cPacket")
{
}

SampledValueDescriptor::~SampledValueDescriptor()
{
}

bool SampledValueDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<SampledValue *>(obj)!=NULL;
}

const char *SampledValueDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int SampledValueDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 11+basedesc->getFieldCount(object) : 11;
}

unsigned int SampledValueDescriptor::getFieldTypeFlags(void *object, int field) const
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
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISARRAY | FD_ISEDITABLE,
    };
    return (field>=0 && field<11) ? fieldTypeFlags[field] : 0;
}

const char *SampledValueDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "appid",
        "length",
        "reserved1",
        "reserved2",
        "tpid",
        "vid",
        "priority",
        "etherType",
        "cfi",
        "timeStamp",
        "content",
    };
    return (field>=0 && field<11) ? fieldNames[field] : NULL;
}

int SampledValueDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='a' && strcmp(fieldName, "appid")==0) return base+0;
    if (fieldName[0]=='l' && strcmp(fieldName, "length")==0) return base+1;
    if (fieldName[0]=='r' && strcmp(fieldName, "reserved1")==0) return base+2;
    if (fieldName[0]=='r' && strcmp(fieldName, "reserved2")==0) return base+3;
    if (fieldName[0]=='t' && strcmp(fieldName, "tpid")==0) return base+4;
    if (fieldName[0]=='v' && strcmp(fieldName, "vid")==0) return base+5;
    if (fieldName[0]=='p' && strcmp(fieldName, "priority")==0) return base+6;
    if (fieldName[0]=='e' && strcmp(fieldName, "etherType")==0) return base+7;
    if (fieldName[0]=='c' && strcmp(fieldName, "cfi")==0) return base+8;
    if (fieldName[0]=='t' && strcmp(fieldName, "timeStamp")==0) return base+9;
    if (fieldName[0]=='c' && strcmp(fieldName, "content")==0) return base+10;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *SampledValueDescriptor::getFieldTypeString(void *object, int field) const
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
        "int",
        "int",
        "int",
        "int",
        "int",
        "double",
        "unsigned char",
    };
    return (field>=0 && field<11) ? fieldTypeStrings[field] : NULL;
}

const char *SampledValueDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int SampledValueDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    SampledValue *pp = (SampledValue *)object; (void)pp;
    switch (field) {
        case 10: return pp->getContentArraySize();
        default: return 0;
    }
}

std::string SampledValueDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    SampledValue *pp = (SampledValue *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getAppid());
        case 1: return long2string(pp->getLength());
        case 2: return long2string(pp->getReserved1());
        case 3: return long2string(pp->getReserved2());
        case 4: return long2string(pp->getTpid());
        case 5: return long2string(pp->getVid());
        case 6: return long2string(pp->getPriority());
        case 7: return long2string(pp->getEtherType());
        case 8: return long2string(pp->getCfi());
        case 9: return double2string(pp->getTimeStamp());
        case 10: return ulong2string(pp->getContent(i));
        default: return "";
    }
}

bool SampledValueDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    SampledValue *pp = (SampledValue *)object; (void)pp;
    switch (field) {
        case 0: pp->setAppid(string2long(value)); return true;
        case 1: pp->setLength(string2long(value)); return true;
        case 2: pp->setReserved1(string2long(value)); return true;
        case 3: pp->setReserved2(string2long(value)); return true;
        case 4: pp->setTpid(string2long(value)); return true;
        case 5: pp->setVid(string2long(value)); return true;
        case 6: pp->setPriority(string2long(value)); return true;
        case 7: pp->setEtherType(string2long(value)); return true;
        case 8: pp->setCfi(string2long(value)); return true;
        case 9: pp->setTimeStamp(string2double(value)); return true;
        case 10: pp->setContent(i,string2ulong(value)); return true;
        default: return false;
    }
}

const char *SampledValueDescriptor::getFieldStructName(void *object, int field) const
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
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
    };
    return (field>=0 && field<11) ? fieldStructNames[field] : NULL;
}

void *SampledValueDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    SampledValue *pp = (SampledValue *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}


