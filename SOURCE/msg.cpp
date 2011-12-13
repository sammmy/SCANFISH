#include "msg.h"
#include <stdio.h>

/*******************************************************************************
*                          class MsgSuperviser
*******************************************************************************/

MsgSuperviser::MsgSuperviser()
{
    pthread_mutex_init(&mutex,NULL);
}

MsgSuperviser::~MsgSuperviser()
{
    // free all allocated resources
    unsigned int i;

    for(i=0;i<valloc.size();i++)
        delete valloc[i];

    pthread_mutex_destroy(&mutex);
}

Msg *MsgSuperviser::allocMsgContainer()
{
    Msg *ptr;
    int size;
    // mutex down
    pthread_mutex_lock(&mutex);
    size=vfree.size();
    if(size>0)
    {
        // we can take one of free containers
        ptr=vfree[size-1];
        vfree.pop_back();
    }
    else
    {
        // we should allocate new container
        ptr= new Msg(this);
        // add container to the allocated resources
        valloc.push_back(ptr);
    }
    // mutex up
    pthread_mutex_unlock(&mutex);


    return ptr;
}

void MsgSuperviser::setFree(Msg *msg)
{
    Msg *ptr=msg;
    // mutex down
    pthread_mutex_lock(&mutex);
    vfree.push_back(ptr);
    // mutex up
    pthread_mutex_unlock(&mutex);
}




/*******************************************************************************
*                                class Msg
*******************************************************************************/



Msg::Msg(MsgSuperviser *msv)
{
    // Msg knows its superviser
    sv=msv;
}


int Msg::setID(unsigned long mid)
{
    if(mid>0xFFFFFFFF)
    {
        return WRONG_ID;
    }

    if(mid&CAN_RTR_FLAG) setRtrFlag(1);
    else setRtrFlag(0);

    if(mid&CAN_ERR_FLAG) setErrorFlag(1);
    else setErrorFlag(0);

    if(mid&CAN_EFF_FLAG) setExtendedFlag(1);
    else setExtendedFlag(0);
   
    id=mid;
    return 0;
}


unsigned long Msg::getID()
{
    if(getRtrFlag()) id=id|CAN_RTR_FLAG;
    if(getErrorFlag()) id=id|CAN_ERR_FLAG;
    if(getExtendedFlag()) id=id|CAN_EFF_FLAG;
    return id;
}

unsigned long Msg::getRealID()
{
    if(id&CAN_EFF_FLAG)
    {
        return id&CAN_EFF_MASK;
    }
    else
    {
        return id&CAN_SFF_MASK;
    }
}

int Msg::setDlc(unsigned int mdlc)
{
    if(mdlc>8)
    {
        return WRONG_DLC;
    }
    dlc=mdlc;
    return 0;
}

unsigned int Msg::getDlc()
{
    return dlc;
}

int Msg::setData(unsigned int num,unsigned char mdata)
{
    if(num>7)
    {
        return -1;
    }

    data[num]=mdata;
    return 0;
}

unsigned char Msg::getData(unsigned int num)
{
    if(num>7)
    {
        return -1;
    }

    return data[num];
}

int Msg::getStatus()
{
    return status;
}

void Msg::setStatus(int st)
{
    status=st;
}

int Msg::setRtrFlag(int vFlag)
{
    RtrFlag=vFlag;
    return 0;
}

int Msg::setErrorFlag(int vFlag)
{
    ErrorFlag=vFlag;
    return 0;
}

int Msg::setExtendedFlag(int vFlag)
{
    ExtendedFlag=vFlag;
    return 0;
}

int Msg::getRtrFlag()
{
    return RtrFlag;
}

int Msg::getErrorFlag()
{
    return ErrorFlag;
}

int Msg::getExtendedFlag()
{
    return ExtendedFlag;
}

void Msg::setMsgFree()
{
    sv->setFree(this);
}


void Msg::fixTime()
{
    // we don't need time zone
    gettimeofday(&timestamp,NULL);
}

time_t Msg::getTimestampSec()
{
    return timestamp.tv_sec;
}

int Msg::getTimestampMS()
{
    return timestamp.tv_usec;
}


