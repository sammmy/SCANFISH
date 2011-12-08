#ifndef GSRECEIVE_H
#define	GSRECEIVE_H

#include "gsReceiveSL.h"
#include "msg.h"

class GSReceive:public ReceiveSub
{
public:
    GSReceive();
    
};

class ReceiveTable:public ReceiveLstn
{
public:
    ReceiveTable(GSReceive*);
    virtual ~ReceiveTable();
    virtual void update(ReceiveSub*,Msg*);
    void addmsg(Msg*);
private:
    GSReceive *_gsRec;
    std::list <Msg*> recTable;
    
};

#endif	/* GSRECEIVE_H */

