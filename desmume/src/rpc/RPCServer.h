#ifndef RPCSERVER_H
#define RPCSERVER_H

#include "functional";
#include "RPCData.h"

__declspec(dllexport) void StartRpc(const int port, mMemory(*handler)(unsigned int, unsigned int));
#endif
