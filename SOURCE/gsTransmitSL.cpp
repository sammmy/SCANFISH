#include <stdlib.h>
#include <list>
#include <map>
#include <algorithm>


#include "gsTransmitSL.h"

void TransmitSub :: attach(TransmitLstn *Tlstn)
{
    _transLstn->insert(_transLstn->end(),Tlstn);
}

void TransmitSub :: detach(TransmitLstn *Tlstn)
{
    _transLstn->remove(Tlstn);
}

void TransmitSub :: notify(Msg *msg)
{
  // ListIterator <TransmitLstn*> i(_transLstn);
  // for (i.First();!i.IsDone();i.Next())
  //  {
  //      i.CurrentItem->update(this,msg);
  //  }
}
