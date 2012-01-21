#include "gsMessageEditor.h"
#include "generalScreen.h"
#include <stdio.h>


int GSMessageEditor::gsStart()
{
    Controller::getController()->allocMsg();
}

int GSMessageEditor::gsSend(unsigned long msgId, unsigned int msgDlc, unsigned char msgData[8])
{
    int i;
    Controller *mcnt = Controller::getController();
    Msg *gsMsg = mcnt->allocMsg();
    gsMsg->setID(msgId);
    gsMsg->setDlc(msgDlc);
    for(i=0; i<msgDlc; i++)
    {
        gsMsg->setData(i,msgData[i]);
    }
    gsMsg->fixTime();
    
    GeneralScreen::getGS()->GSTrans->haveSent(gsMsg);
    if((mcnt->send(gsMsg,mcnt->contrNum) == 0))
        return 0;
    return -1;
}

time_t GSMessageEditor::getTimestampSec()
{
    struct timeval timestamp;
    gettimeofday(&timestamp,NULL);
    return timestamp.tv_sec;
}
int GSMessageEditor::getTimestampMS()
{
    struct timeval timestamp;
    gettimeofday(&timestamp,NULL);
    return timestamp.tv_usec;
}
