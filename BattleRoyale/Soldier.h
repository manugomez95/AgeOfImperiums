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
    Player* player;
    string name;
    int health;
    int damage;
    float dodgeChance;
    int velocity;
    int sightRange = 3;
    bool dead;

    vector<Soldier*> getEnemiesAround();
    Soldier* getNearestEnemy();
    HealthPotion* getNearestPotion();
    bool isEnemy(Soldier* s);
    void receiveAttack(int receivedDamage);
    void move(array<int, 2> dir);

public:
    Soldier(Player* player, Map* map);

    void combat();
    void move();
    string str() override;
    int getHealth();
    void setHealth(int health);
    Player* getPlayer();
    bool isDead();
};