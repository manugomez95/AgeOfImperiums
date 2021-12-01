#pragma once

#include <string>
using namespace std;

class Transform;

class Soldier {
public:
    Transform* transform;
    int playerId;
    int health;
    int attack;
    int defense;
    int velocity;

    string str();
    Soldier(int, Transform*);
};