/* 
 * File:   generalScreen.h
 * Author: Ira
 *
 * Created on November 20, 2011, 7:10 PM
 */

#ifndef GENERALSCREEN_H
#define	GENERALSCREEN_H

#include "canlistener.h"


class GeneralScreen:public CanListener
{

public:
    GeneralScreen();
    static void attach(Observer *o);
    static void detach(Observer *o);
    GSConnect *GSCon;
    GSMessageEditor *GSMesEdit;
    GSReceive *GSRec;
    GSTransmit *GSTrans;

private:
    std::vector MyObs;
    void notifyRecObs(Msg *msg);
    void notifyTransObs(Msg *msg);
};

class Observer
{
public:
    Observer();
    void updateRec(GeneralScreen *GenScr)=0;
    void updateTrans(GeneralScreen *GenScr)=0;
};

class GSConnect
{
public:
    GSConnect();
    int gsconnection(const char *interface);
    int gsdisconnection();
};

class GSMessageEditor
{
public:
    GSMessageEditor();
    int gssend(unsigned int msgId, unsigned int msgDlc, unsigned char msgData);
};

class GSReceive : public Observer
{
    public:
        GSReceive();
        int gsreceive(Msg *msg,int netid);
        void updateRec(GeneralScreen *GenScr);
};

class GSTransmit : public Observer
{
public:
    GSTransmit();
    void update(GeneralScreen *GenScr);
};


#endif	/* GENERALSCREEN_H */

