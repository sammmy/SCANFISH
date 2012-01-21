#ifndef GSMESSAGEEDITOR_H
#define GSMESSAGEEDITOR_H

#include "controller.h"
#include "msg.h"
#include "gsTransmit.h"
#include "sys/time.h"

class GSMessageEditor
{
public:
    GSMessageEditor();
    int gsSend(unsigned long msgId, unsigned int msgDlc, unsigned char msgData[8]);
    int gsStart();
    time_t getTimestampSec();
    int    getTimestampMS();
private:
    time_t msgSec;
    int msgMs;
};

#endif /* GSMESSAGEEDITOR_H */