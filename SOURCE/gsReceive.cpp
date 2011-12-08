#include "gsReceive.h"

ReceiveTable::ReceiveTable(GSReceive *gsR)
{
    _gsRec = gsR;
    _gsRec->attach(this);
}

void ReceiveTable::update (ReceiveSub *theChangedSubject, Msg *mess)
{
    if (theChangedSubject==_gsRec)
    {
        addmsg(mess);
    }
}

void ReceiveTable::addmsg(Msg *mess)
{
    recTable.push_front(mess);
}
