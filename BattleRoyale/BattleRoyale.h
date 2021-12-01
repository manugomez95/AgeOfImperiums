#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "Player.h"
#include "Map.h"
using namespace std;

class BattleRoyale {
    Map* map;
    static BattleRoyale* instance;
public:
    int nPlayers;
    vector<Player> players;

    static BattleRoyale* create();
    static BattleRoyale* getInstance();
    void setMap(Map* map);
    Map* getMap();
    void initPlayers(int);
    void destroy();
    void update();
};