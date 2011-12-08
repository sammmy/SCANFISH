#ifndef GSMESSAGEEDITOR_H
#define	GSMESSAGEEDITOR_H

#include "controller.h"
#include "msg.h"
#include "gsTransmit.h"

class GSMessageEditor
{
public:
    GSMessageEditor();
    int gssend(unsigned int msgId, unsigned int msgDlc, unsigned char msgData[8]);
private:
    Controller *cnt;
    Msg *msg;
};

#endif	/* GSMESSAGEEDITOR_H */

