#ifndef __INET_SDHADM_H
#define __INET_SDHADM_H

#include <omnetpp.h>
#include <queue>
#include "SDHMessages_m.h"

namespace inet {

class SDHADM : public omnetpp::cSimpleModule
{

protected:
    int numTributaries;
    int stmLevel;
    bool allowMixedInsertion;
    std::vector<std::queue<cPacket*>> tributaryBuffers;
    cMessage *frameTimer;

    // Señales
    simsignal_t pdhReceivedSignal;
    simsignal_t pdhTransmittedSignal;
    simsignal_t stmForwardedSignal;

    // Contadores
    int totalPDHReceived;
    int totalPDHTransmitted;
    int totalSTMForwarded;


    virtual void initialize() override;
    virtual void handleMessage(omnetpp::cMessage *msg) override;
    virtual void finish() override;
};

} // namespace inet

#endif
