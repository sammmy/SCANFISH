#ifndef GSCONNECT_H
#define	GSCONNECT_H

class GSConnect
{
public:
    GSConnect();
    int gsconnection(const char *interface);
    int gsdisconnection();
};

#endif	/* GSCONNECT_H */

