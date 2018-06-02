//
// Created by romain on 02/06/18.
//

#ifndef CPP_INDIE_STUDIO_GAMESERVER_H
#define CPP_INDIE_STUDIO_GAMESERVER_H

#include "shared/ANetworkAsyncServer.h"
#include "GameClient.h"
#include "GameClientHandler.h"

using game_clients_t = std::unordered_map<size_t, std::unique_ptr<GameClient>>;

class GameServer: public ANetworkAsyncServer {
public:

    GameServer(std::string const &ip, uint16_t port) : ANetworkAsyncServer(ip ,port), _handler(this), _clients() {}

    GameClient *findClient(size_t clientId);
    game_clients_t &getClients();

protected:

    std::unique_ptr<ANetworkClientAdapter> defineClientAdapter() override;

    void onServerClosed() override;

private:

    GameClientHandler _handler;
    game_clients_t _clients;
};


#endif //CPP_INDIE_STUDIO_GAMESERVER_H
