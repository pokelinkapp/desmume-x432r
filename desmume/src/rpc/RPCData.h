#ifndef RPCDATA_H
#define RPCDATA_H
#include "rpc/msgpack.hpp"
#include <vector>
struct MemoryRequest {
    unsigned int Id;
    unsigned int Address;
    unsigned int Size;
    unsigned char* Data;
};

struct mMemory {
	unsigned int size;
	std::vector<unsigned char> bytes;
	MSGPACK_DEFINE_ARRAY(size, bytes);
};
#endif // RPCDATA_H
