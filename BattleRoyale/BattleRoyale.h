#pragma once

#include <string>
#include <vector>
#include <chrono>

using namespace std;
using namespace chrono;

// Define the way the game looks on console
enum class ViewMode {   
    Minimalist,         // Minimal representation of the map and faster refresh rate
    Debug               // Grid representation of the map and logging
};

class Player;
class Map;

// Represents the entire simulation/game
class BattleRoyale {
private:
    duration<long long, milli> refreshRate;
    ViewMode viewMode;

    Map* map;
    vector<Player*> players;

    void update();
    void printBegginingText();
public:
    BattleRoyale(Map* map, ViewMode viewMode);
    static void launchMenu();
    
    void addPlayer(int armySize);
    void play();

    Map* getMap();

    void destroy();
};