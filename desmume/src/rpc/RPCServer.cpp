#include "RPCServer.h"
#include "rpc/server.h"
#include "RPCData.h"

rpc::server* server;

__declspec(dllexport) void Rpc::StartRpc(const int port, void(*handler)(unsigned int, unsigned int, char*)) {

	if (server != nullptr) {
		server->close_sessions();
		server->stop();
	}

	server = new rpc::server(port);

	server->bind("readMemory", [handler](unsigned int address, unsigned int size) {
		auto* data = new char[size];
        handler(address, size, data);

		auto pass = mMemory();
		pass.size = size;

		pass.bytes.resize(pass.size);

		for (auto i = 0u; i < size; i++) {
			pass.bytes[i] = data[i];
		}

		delete[] data;

		return pass;
	});

	vprintf("Server started\n", nullptr);

	server->async_run();
}
