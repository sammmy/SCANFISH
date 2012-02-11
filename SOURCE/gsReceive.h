#ifndef GSRECEIVE_H
#define GSRECEIVE_H

#include <stdio.h>
#include <map>
#include <time.h>
#include "gsReceiveSL.h"
#include "msg.h"
#include "controller.h"

class GSReceive:public ReceiveSub
{
public:
    GSReceive();

    void haveReceived();
    void setMsg();
    int getMsgId();
    int getMsgDlc();
    char getMsgData(int);
    time_t getMsgTimestampSec();
    int getMsgTimestampMS();
    void setMsgFree();

private:
    Msg *msg;
};

class ReceiveTable:public ReceiveLstn
{
public:
    ReceiveTable(GSReceive*);
    //virtual ~ReceiveTable();
    virtual void update(ReceiveSub*,Msg*);
    void addmsg(Msg*);
private:
    GSReceive *gsRec;
    typedef std::map <int,Msg*> recTable;
    recTable recTab;

};
#endif /* GSRECEIVE_H */