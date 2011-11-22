#ifndef GENERALSCREEN_H
#define	GENERALSCREEN_H

#include "canlistener.h"

class GeneralScreen:public CanListener
{
public:
    GeneralScreen();
    GSConnect *GSCon;
    GSMessageEditor *GSMesEdit;
    GSReceive *GSRec;
    GSTransmit *GSTrans;
};

#endif	/* GENERALSCREEN_H */

