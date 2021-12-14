#pragma once

#include <string>
#include <vector>
#include <chrono>
#include "Player.h"
#include "Map.h"

using namespace std;
using namespace chrono;

enum class ViewMode { Cinematic, Debug };

class BattleRoyale {
    static BattleRoyale* instance;
    duration<long long, milli> refreshRate;

    Map* map;
    vector<Player*> players;
    
    BattleRoyale(ViewMode viewMode);
public:
    int nPlayers;
    ViewMode viewMode;

    static BattleRoyale* create(ViewMode viewMode);
    static BattleRoyale* getInstance();
    
    void addPlayer(Player* player);
    void initPlayers(int n_players, int army_size);


    void setMap(Map* map);
    Map* getMap();
    

    void destroy();
    
    
    void update();
    void play();
};