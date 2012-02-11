#ifndef GSCONNECT_H
#define GSCONNECT_H

#include "controller.h"
#include "canlistener.h"
#include <stdio.h>

class GSConnect
{
public:
    GSConnect();
    int gsConnection(const char *interface,CanListener *canl);
    int gsDisconnection();
    int currentNet();

    int setCurrentNum();
};
#endif /* GSCONNECT_H */
