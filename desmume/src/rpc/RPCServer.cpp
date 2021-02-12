#include "RPCServer.h"
#include "rpc/server.h"
#include "RPCData.h"

rpc::server* server;

__declspec(dllexport) void StartRpc(const int port, mMemory(*handler)(unsigned int, unsigned int)) {

	if (server != nullptr) {
		server->close_sessions();
		server->stop();
	}

	server = new rpc::server(port);

	server->bind("readMemory", handler);

	vprintf("Server started\n", nullptr);

	server->async_run();

	server->async_run();
}
