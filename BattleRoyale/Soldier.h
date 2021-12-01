#pragma once

#include <string>
using namespace std;

class Soldier {
public:
    int playerId;
    int health;
    int attack;
    int defense;
    int velocity;

    string str();
};

string Soldier::str() {
    return string(1, char(2));
}