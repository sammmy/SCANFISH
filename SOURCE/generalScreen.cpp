#include "generalScreen.h"

GeneralScreen *GeneralScreen::singleton = NULL;

GeneralScreen :: GeneralScreen() : CanListener()
{
    GSTrans=new GSTransmit;
    TransmitTable *GStab = new TransmitTable(GSTrans);
    GSRec=new GSReceive;
    ReceiveTable *GSrec = new ReceiveTable(GSRec);
}

GeneralScreen *GeneralScreen::getGS()
{
	if(singleton == NULL)
	{
		singleton = new GeneralScreen();
	}
	return singleton;
}

int GeneralScreen::notify() {}
int GeneralScreen::errorInNet(const char *str) {}

