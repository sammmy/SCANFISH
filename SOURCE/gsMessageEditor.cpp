#include "gsMessageEditor.h"

int GSMessageEditor::gssend(unsigned long msgId, unsigned int msgDlc, unsigned char msgData[8])
{
    int i;
    GSTransmit *gsTrans;
    cnt=Controller::getController();
    msg=cnt->allocMsg();
    msg->setID(msgId);
    msg->setDlc(msgDlc);
    for(i=0;i<msg->getDlc();i++)
    {
        msg->setData(i,msgData[i]);
    }
    msg->fixTime();
    gsTrans->notify(msg);
    if((cnt->send(msg,cnt->contrNum)==0))
        return 0;
    return -1;
}
