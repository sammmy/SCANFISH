#include <stdlib.h>
#include <list>
#include <map>
#include <algorithm>
#include <stdio.h>


#include "gsTransmitSL.h"

TransmitLstn::TransmitLstn() {}
TransmitSub::TransmitSub() {}

void TransmitSub :: attach(TransmitLstn *Tlstn)
{
    transLstnList::iterator it;
    it=lstnList.end();
    lstnList.insert(it,Tlstn);
}

void TransmitSub :: detach(TransmitLstn *Tlstn)
{
    lstnList.remove(Tlstn);
}

void TransmitSub :: notify(Msg *msg)
{
    transLstnList::iterator it;
    TransmitLstn *CurrentTL;

    for (it = lstnList.begin();it != lstnList.end();it++)
    {
        CurrentTL = *it;
        CurrentTL->update(this,msg);
    }

}

