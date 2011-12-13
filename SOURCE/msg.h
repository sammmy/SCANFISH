#ifndef MSG_H
#define MSG_H


#include <vector>
#include <pthread.h>
#include "sferror.h"
#include "sys/time.h" /* Linux only (Posix functions) */

#define STATUS_OK 0
/* controller area network (CAN) kernel definitions */

/* special address description flags for the CAN_ID */
#define CAN_EFF_FLAG 0x80000000U /* EFF/SFF is set in the MSB */
#define CAN_RTR_FLAG 0x40000000U /* remote transmission request */
#define CAN_ERR_FLAG 0x20000000U /* error frame */

/* valid bits in CAN ID for frame formats */
#define CAN_SFF_MASK 0x000007FFU /* standard frame format (SFF) */
#define CAN_EFF_MASK 0x1FFFFFFFU /* extended frame format (EFF) */
#define CAN_ERR_MASK 0x1FFFFFFFU /* omit EFF, RTR, ERR flags */


class MsgSuperviser;


class Msg
{

private:
    unsigned long id; // should be 32 bit
    unsigned int dlc;
    unsigned char data[8];
    int status; // any errors in frames? for the future use
    int ExtendedFlag; // frame 1-Yes, 0 - No
    int ErrorFlag;
    int RtrFlag;
    MsgSuperviser *sv; // looks for the Msg resources
struct timeval timestamp;
public:
     Msg(MsgSuperviser *msv);

    // accessors
    int setID(unsigned long mid);
    unsigned long getID();
    unsigned long getRealID();
    int setDlc(unsigned int mdlc);
    unsigned int getDlc();
    int setData(unsigned int num,unsigned char mdata);
    unsigned char getData(unsigned int num);
    int getStatus();
    void setStatus(int st);

    int setRtrFlag(int vFlag);
    int setErrorFlag(int vFlag);
    int setExtendedFlag(int vFlag);

    int getRtrFlag();
    int getErrorFlag();
    int getExtendedFlag();

    
    // set this Msg container free
    void setMsgFree();
void fixTime();
time_t getTimestampSec();
int getTimestampMS();
};



class MsgSuperviser
{
    // mutex
    pthread_mutex_t mutex;
    // vector of free resources
    std::vector<Msg *> vfree;
    // vector of allocated resources
    std::vector<Msg *> valloc;
public:
    MsgSuperviser();
    ~MsgSuperviser();
    Msg *allocMsgContainer();
    void setFree(Msg *msg);

};



#endif /* MSG_H */



