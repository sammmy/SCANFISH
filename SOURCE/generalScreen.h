#ifndef GENERALSCREEN_H
#define	GENERALSCREEN_H

#include "canlistener.h"
#include "gsConnect.h"
#include "gsMessageEditor.h"
#include "gsReceive.h"
#include "gsTransmit.h"

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

