#pragma once

#include <iostream>
#include <string>
#include "Player.h"
#include "Map.h"
using namespace std;

class BattleRoyale {
    BattleRoyale(int n);
    static BattleRoyale* instance;
public:
    int nPlayers;
    Player** players;
    Map* map;

    static BattleRoyale* create(int n); // support multiple players
    static BattleRoyale* getInstance();
    void destroy();
    //void start();
};