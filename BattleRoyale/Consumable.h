#pragma once

#include "GameObject.h"
using namespace std;

class Soldier;

class Consumable : public GameObject {
public:
    Consumable(Map* map, array<int, 2> pos) : GameObject(map, pos) {};
    virtual void consume(Soldier* consumer) = 0;
};

class HealthPotion : public Consumable {
public:
    HealthPotion(Map* map, array<int, 2> pos);
    int effect = +10;

    void consume(Soldier* consumer) override;
};