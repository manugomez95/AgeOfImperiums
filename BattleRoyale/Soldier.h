#pragma once

#include <string>
#include <vector>
#include "GameObject.h"
using namespace std;

class Map;
class Player;
class HealthPotion;

class Soldier : public GameObject {
private:
    vector<Soldier*> getEnemiesAround();
    Soldier* getNearestEnemy();
    HealthPotion* getNearestPotion();
    bool isEnemy(Soldier* s);
    void receiveAttack(int receivedDamage);

public:
    Soldier(Player* player, Map* map, array<int, 2> pos);

    Player* player;
    string name;
    int health;
    int damage;
    float dodgeChance;
    int velocity;
    int sightRange = 3;
    bool dead;

    void combat();
    void move(array<int, 2> dir);
    void move();
    string str() override;
};