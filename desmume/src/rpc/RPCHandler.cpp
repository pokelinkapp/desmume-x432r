#include "RPCHandler.h"

SafeQueue<MemoryRequest> RPCHandler::RpcRequests;
ThreadSafeMap<unsigned int, bool> RPCHandler::RpcResults;