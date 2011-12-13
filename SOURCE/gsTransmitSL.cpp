#include <stdlib.h>
#include <list>
#include <map>
#include <algorithm>


#include "gsTransmitSL.h"

void TransmitSub :: attach(TransmitLstn *Tlstn)
{
    transLstnList->insert(transLstnList->end(),Tlstn);
}

void TransmitSub :: detach(TransmitLstn *Tlstn)
{
    transLstnList->remove(Tlstn);
}

void TransmitSub :: notify(Msg *msg)
{
    std::list<TransmitLstn*>::iterator it;
    TransmitLstn *CurrentTL;
   
    for (it=transLstnList->begin();it!=transLstnList->end();it++)
    {
        CurrentTL=*it;
        CurrentTL->update(this,msg);
    }
}
