#ifndef GSTRANSMIT_H
#define GSTRANSMIT_H

#include <map>
#include "gsTransmitSL.h"
#include "msg.h"

class GSTransmit:public TransmitSub
{
public:
    GSTransmit();

    void haveSent(Msg *msg);

private:
    Msg *msg;
};

class TransmitTable:public TransmitLstn
{
public:
    TransmitTable(GSTransmit*);
    void update(TransmitSub*,Msg*);
    void addmsg(Msg*);

private:
    GSTransmit *gsTrans;
    typedef std::map <int,Msg*> transTable;
    transTable transTab;
};

#endif /* GSTRANSMIT_H */