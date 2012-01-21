#include "gsReceive.h"

GSReceive::GSReceive()
{
}

void GSReceive::haveReceived(Msg* msg)
{
    notify(msg);
}

ReceiveTable::ReceiveTable(GSReceive *gsR)
{
    gsRec = gsR;
    gsR->attach(this);
}

void ReceiveTable::update (ReceiveSub *theChangedSubject, Msg *mess)
{
    if (theChangedSubject == gsRec)
    {
        addmsg(mess);
    }
}
void ReceiveTable::addmsg(Msg *mess)
{
    recTab.insert(std::pair<int,Msg*>(Controller::getController()->contrNum,mess));
    printf("\n\nadd msg in recTable =) \n\n");
}
