#include "gsReceive.h"

GSReceive::GSReceive()
{
}

void GSReceive::haveReceived()
{
    notify(msg);
}

void GSReceive::setMsg()
{
    Controller::getController()->receive(&msg,Controller::getController()->contrNum);
}

int GSReceive::getMsgId()
{
    return msg->getID();
}

int GSReceive::getMsgDlc()
{
    return msg->getDlc();
}

char GSReceive::getMsgData(int i)
{
    return msg->getData(i);
}

time_t GSReceive::getMsgTimestampSec()
{
    return msg->getTimestampSec();
}

int GSReceive::getMsgTimestampMS()
{
    return msg->getTimestampMS();
}

void GSReceive::setMsgFree()
{
    msg->setMsgFree();
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
