#ifndef GSTRANSMITSL_H
#define GSTRANSMITSL_H

#include <list>
#include "msg.h"

class TransmitSub;

class TransmitLstn
{
public:
//    virtual ~TransmitLstn();
    virtual void update(TransmitSub *changed,Msg*)=0;
protected:
    TransmitLstn();
};

class TransmitSub
{
public:
//    virtual ~TransmitSub();
    virtual void attach(TransmitLstn *T);
    virtual void detach(TransmitLstn *T);
    virtual void notify(Msg *msg);
protected:
    TransmitSub();
private:
    typedef std::list<TransmitLstn *> transLstnList;
    transLstnList lstnList;
};

#endif /* GSTRANSMITSL_H */
