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

#endif	/* GENERALSCREEN_H */

