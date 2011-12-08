#ifndef GSTRANSMIT_H
#define	GSTRANSMIT_H

#include "gsTransmitSL.h"
#include "msg.h"

class GSTransmit:public TransmitSub
{
public:
    GSTransmit();
};

class TransmitTable:public TransmitLstn
{
public:
    TransmitTable(GSTransmit*);
    virtual ~TransmitTable();
    virtual void update(TransmitSub*,Msg*);
    void addmsg(Msg*);
private:
    GSTransmit *_gsTrans;
    std::list <Msg*> transTable;
};

#endif	/* GSTRANSMIT_H */

