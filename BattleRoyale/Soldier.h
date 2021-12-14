#pragma once

#include <string>
#include <vector>
#include "GameObject.h"
using namespace std;

class Map;
class Player;

class Soldier : public GameObject {
private:
    vector<Soldier*> getEnemiesAround();

public:
    Soldier(Player* player, Map* map, array<int, 2> pos);

    Player* player;
    string name;
    int health;
    int damage;
    float dodgeChance;
    int velocity;
    bool dead;

    void combat();
    void receiveAttack(int receivedDamage);
    string str() override;
};