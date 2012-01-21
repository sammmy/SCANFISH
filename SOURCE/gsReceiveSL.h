#ifndef GSRECEIVESL_H
#define GSRECEIVESL_H

#include <list>
#include <stdlib.h>
#include <list>
#include <map>
#include <algorithm>
#include "msg.h"

class ReceiveSub;

class ReceiveLstn
{
public:
//    virtual ~ReceiveLstn();
    virtual void update(ReceiveSub *changed,Msg*)=0;
protected:
    ReceiveLstn();
};

class ReceiveSub
{
public:
//    virtual ~ReceiveSub();
    virtual void attach(ReceiveLstn *R);
    virtual void detach(ReceiveLstn *R);
    virtual void notify(Msg*);
protected:
    ReceiveSub();
private:
    typedef std::list<ReceiveLstn *> recLstnList;
    recLstnList lstnList;
};

#endif /* GSRECEIVESL */