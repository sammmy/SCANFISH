#include "gsConnect.h"
#include "generalScreen.h"

GSConnect::GSConnect()
{
}

int GSConnect::gsConnection(const char *interface,CanListener *canl)
{
    int nettabid;
    if (nettabid = Controller::getController()->connect(1000,interface,canl) > 0)
    {
        printf("nettabid: %d; \n",nettabid);
        return 0;
    }
    return -1;
}

int GSConnect::gsDisconnection()
{
    Controller::getController()->disconnect(Controller::getController()->contrNum);
    return 0;
}

int GSConnect::currentNet()
{
    std::map <int,CanNet*>::iterator it;
    it=Controller::getController()->nettab.find(Controller::getController()->netCount);
    return it->first;
}

int GSConnect::setCurrentNum()
{
    Controller::getController()->contrNum = GeneralScreen::getGS()->GSCon->currentNet();
}
