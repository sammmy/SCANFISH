#ifndef GSCONNECT_H
#define	GSCONNECT_H

#include <stdio.h>
#include "controller.h"
#include "canlistener.h"

class GSConnect
{
public:
    GSConnect();
    int gsConnection(const char *interface, CanListener *canl);
    int gsDisconnection();
};

#endif	/* GSCONNECT_H */

