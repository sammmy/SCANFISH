#include "gsReceiveSL.h"

ReceiveLstn::ReceiveLstn() {}
ReceiveSub::ReceiveSub() {}

void ReceiveSub :: attach(ReceiveLstn *Rlstn)
{
    recLstnList::iterator it;
    it=lstnList.end();
    lstnList.insert(it,Rlstn);
}

void ReceiveSub :: detach(ReceiveLstn *Rlstn)
{
    lstnList.remove(Rlstn);
}

void ReceiveSub :: notify(Msg *msg)
{
    recLstnList::iterator it;
    ReceiveLstn *CurrentTL;

    for (it = lstnList.begin();it != lstnList.end();it++)
    {
        CurrentTL = *it;
        CurrentTL->update(this,msg);
    }
}
