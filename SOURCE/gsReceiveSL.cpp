#include "gsReceiveSL.h"

void ReceiveSub :: attach(ReceiveLstn *Rlstn)
{
    _recLstn->insert(_recLstn->end(),Rlstn);
}

void ReceiveSub :: detach(ReceiveLstn *Rlstn)
{
    _recLstn->remove(Rlstn);
}

void ReceiveSub :: notify(Msg *msg)
{
  // ListIterator <ReceiveLstn*> i(_recLstn);
  // for (i.First();!i.IsDone();i.Next())
  //  {
  //      i.CurrentItem->update(this,msg);
  //  }
}
