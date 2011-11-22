#ifndef GSTRANSMIT_H
#define	GSTRANSMIT_H

class TransmitLstn
{
public:
    virtual ~TransmitLstn();
    virtual void update(TransmitSub *changed)=0;
protected:
    TransmitLstn();
};

class TransmitSub
{
public:
    virtual ~TransmitSub();
    virtual void attach(TransmitLstn *T);
    virtual void detach(TransmitLstn *T);
    virtual void notify();
protected:
    TransmitSub();
private:
    std::list<TransmitLstn *> *_transLstn;
};

class GSTransmit:public TransmitSub
{
public:
    GSTransmit();
    virtual Msg getMsg();
};

class TransmitTable:public TransmitLstn
{
public:
    TransmitTable(GSTransmit*);
    virtual ~TransmitTable();
    virtual void update(TransmitSub*);
    void addmsg();
private:
    GSTransmit *_gsTrans;
};

#endif	/* GSTRANSMIT_H */

