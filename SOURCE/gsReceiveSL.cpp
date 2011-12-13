#include "gsReceiveSL.h"

void ReceiveSub :: attach(ReceiveLstn *Rlstn)
{
    recLstnList->insert(recLstnList->end(),Rlstn);
}

void ReceiveSub :: detach(ReceiveLstn *Rlstn)
{
    recLstnList->remove(Rlstn);
}

void ReceiveSub :: notify(Msg *msg)
{
    std::list<ReceiveLstn*>::iterator it;
    ReceiveLstn *CurrentRL;
   
    for (it=recLstnList->begin();it!=recLstnList->end();it++)
    {
        CurrentRL=*it;
        CurrentRL->update(this,msg);
    }
}
