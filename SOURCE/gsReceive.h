#ifndef GSRECEIVE_H
#define	GSRECEIVE_H

class GSReceive : public Observer
{
    public:
        GSReceive();
        int gsreceive(Msg *msg,int netid);
        void updateRec(GeneralScreen *GenScr);
};

#endif	/* GSRECEIVE_H */

