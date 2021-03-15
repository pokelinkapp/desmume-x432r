#include "RPCServer.h"
#include "rpc/server.h"
#include "RPCData.h"

rpc::server* server;

__declspec(dllexport) void Rpc::StartRpc(const int port, void(*handler)(unsigned int, unsigned int, unsigned char*), void(*romHandler)(unsigned int&, unsigned char*), const char* (*serialHandler)()) {

	if (server != nullptr) {
		server->close_sessions();
		server->stop();
	}

	server = new rpc::server(port);

	server->bind("readMemory", [handler](unsigned int address, unsigned int size) {
		auto* data = new unsigned char[size];
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

	server->bind("readRom", [romHandler]() {
		auto pass = mMemory();

		unsigned int size = 0;

        const auto buff = new unsigned char[256 * 1024 * 1024];

        romHandler(size, buff);

		pass.size = size;
		pass.bytes.resize(pass.size);

		for (auto i = 0u; i < size; i++) {
			pass.bytes[i] = buff[i];
		}

		delete[] buff;

		return pass;
	});

	server->bind("getSerial", [serialHandler]() {
		return std::string(serialHandler());
	});

	vprintf("Server started\n", nullptr);

	server->async_run();
}
