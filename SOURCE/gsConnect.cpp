#include "gsConnect.h"

int GSConnect::gsConnection(const char *interface)
{
    CanListener *canl;
    if (Controller::getController()->connect(1000,interface,canl)>0)
        return 0;
    return -1;
}

int GSConnect::gsDisconnection()
{
    Controller::getController()->disconnect(Controller::getController()->contrNum);
    return 0;
}
