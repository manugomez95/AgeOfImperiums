#pragma once

#include <string>
#include <vector>

using namespace std;

class Soldier;
class Map;

class Player {
    static int counter;

private:
    bool eliminated;
    unsigned int id;
    int armySize;
    vector<Soldier*> army;
    Map* map;
    int color;
    bool debug;

public:
    Player(Map* map, int armySize, bool debug);
    string str();

    vector<Soldier*> getArmy();
    int getArmySize();
    void decreaseArmySize();
    int getColor();
    bool getEliminated();
    void setEliminated(bool eliminated);
    bool isDebugged();
    void destroy();
};