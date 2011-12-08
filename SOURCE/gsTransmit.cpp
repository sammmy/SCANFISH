#include "gsTransmit.h"

TransmitTable::TransmitTable(GSTransmit *gsT)
{
    _gsTrans = gsT;
    _gsTrans->attach(this);
}

void TransmitTable::update (TransmitSub *theChangedSubject, Msg *mess)
{
    if (theChangedSubject==_gsTrans)
    {
        addmsg(mess);
    }
}

void TransmitTable::addmsg(Msg *mess)
{
    transTable.push_front(mess);
}
