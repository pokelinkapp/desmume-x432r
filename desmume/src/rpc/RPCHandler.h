#ifndef RPC_HANDLER_H
#define RPC_HANDLER_H

#include "SafeQueue.h"
#include "SafeMap.h"
#include "RPCData.h"

class RPCHandler {
public:
    static SafeQueue<MemoryRequest> RpcRequests;
    static ThreadSafeMap<unsigned int, bool> RpcResults;
};
#endif