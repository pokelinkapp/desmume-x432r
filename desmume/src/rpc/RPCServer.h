#ifndef RPCSERVER_H
#define RPCSERVER_H

#include "RPCData.h"

namespace Rpc {
    __declspec(dllexport) void StartRpc(const int port, void(*handler)(unsigned int, unsigned int, unsigned char*), void(*romHandler)(unsigned int&, unsigned char*), const char*(*serialHandler)());
}
#endif
