#include "RPCHandler.h"

SafeQueue<MemoryRequest> RPCHandler::RpcRequests;
ThreadSafeMap<unsigned int, mMemory> RPCHandler::RpcResults;