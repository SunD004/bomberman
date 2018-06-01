//
// Created by romain on 02/06/18.
//

#include <GameClientHandler.h>
#include "GameServer.h"

std::unique_ptr<ANetworkClientAdapter> GameServer::defineClientAdapter() {
    std::make_unique<GameClientHandler>(this);
}

GameClient *GameServer::findClient(size_t clientId) {
    for (auto &keyset: _clients) {
        auto &client = keyset.second;

        if (client->getId() == clientId)
            return client.get();
    }
    return nullptr;
}

game_clients_t &GameServer::getClients() {
    return _clients;
}

void GameServer::shutdown() {
    for (auto &keyset: _clients) {
        auto &client = keyset.second;
        client->kick(true);
    }
}