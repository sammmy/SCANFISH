#ifndef GSRECEIVE_H
#define	GSRECEIVE_H

class ReceiveLstn
{
public:
    virtual ~ReceiveLstn();
    virtual void update(ReceiveSub *changed)=0;
protected:
    ReceiveLstn();
};

class ReceiveSub
{
public:
    virtual ~ReceiveSub();
    virtual void attach(ReceiveLstn *R);
    virtual void detach(ReceiveLstn *R);
    virtual void notify();
protected:
    ReceiveSub();
private:
    std::list<ReceiveLstn *> *_recLstn;
};

class GSReceive:public ReceiveSub
{
public:
    GSReceive();
    virtual Msg getMsg();
};

class ReceiveTable:public ReceiveLstn
{
public:
    ReceiveTable(GSReceive*);
    virtual ~ReceiveTable();
    virtual void update(ReceiveSub*);
    void addmsg();
private:
    GSReceive *_gsRec;
};

#endif	/* GSRECEIVE_H */

