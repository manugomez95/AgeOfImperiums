#pragma once

#include "GameObject.h"
using namespace std;

class Soldier;

class Consumable : public GameObject {
public:
    Consumable(Map* map) : GameObject(map) {};
    virtual void consume(Soldier* consumer) = 0;
};

class HealthPotion : public Consumable {
private:
    int effect = +10;
public:
    HealthPotion(Map* map);
    void consume(Soldier* consumer) override;
};