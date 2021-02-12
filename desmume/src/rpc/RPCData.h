#ifndef RPCDATA_H
#define RPCDATA_H
#include "rpc/msgpack.hpp"
struct mMemory {
	unsigned int size;
	std::string bytes;
	MSGPACK_DEFINE_ARRAY(size, bytes);
};
#endif // RPCDATA_H
