#ifndef GSCONNECT_H
#define	GSCONNECT_H

#include "controller.h"
#include "canlistener.h"

class GSConnect
{
public:
    GSConnect();
    int gsConnection(const char *interface);
    int gsDisconnection();
};

#endif	/* GSCONNECT_H */

