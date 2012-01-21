#include "gsConnect.h"

GSConnect::GSConnect()
{
}

int GSConnect::gsConnection(const char *interface, CanListener *canl)
{
    int nettabid;
 //   CanListener *canl=mcanl;
    if (nettabid=Controller::getController()->connect(1000,interface,canl)>0)
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