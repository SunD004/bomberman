//
// Created by romain on 31/05/18.
//

#ifndef CPP_INDIE_STUDIO_DATAREADER_H
#define CPP_INDIE_STUDIO_DATAREADER_H


#include <cstdint>
#include <string>
#include "shared/BasicNetworkBuffer.h"
#include "NetworkProtocol.h"

class NetworkDataReader: public BasicNetworkBuffer {
public:

    explicit NetworkDataReader(size_t maxSize): BasicNetworkBuffer(maxSize) {}

    NetworkDataReader(): BasicNetworkBuffer(NetworkProtocol::PACKET_MAX_SIZE) {}

    template<typename T>
    void readBytes(T &to_fill);

    std::vector<char> readBytes();
    bool readBool();
    int32_t readInt();
    std::string readUtf();
};


#endif //CPP_INDIE_STUDIO_DATAREADER_H
