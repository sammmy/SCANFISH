#include <stdio.h>
#include "gsTransmit.h"
#include "controller.h"


GSTransmit::GSTransmit()
{
}


void GSTransmit::haveSent(Msg *msg)
{
    notify(msg);
}

TransmitTable::TransmitTable(GSTransmit *gsT)
{
    gsTrans = gsT;
    gsT->attach(this);
}

void TransmitTable::update (TransmitSub *theChangedSubject,Msg *msg)
{
    if (theChangedSubject == gsTrans)
    {
        addmsg(msg);
    }
}

void TransmitTable::addmsg(Msg *mess)
{
    transTab.insert(std::pair<int,Msg*>(Controller::getController()->contrNum,mess));
    printf("\n\nadd msg in transTable =) \n\n");
}