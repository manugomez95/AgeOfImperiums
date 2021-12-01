#pragma once

#include <iostream>
#include <string>
#include "Soldier.h"
using namespace std;

class Player {
    static int counter;
public:
    int id;
    Soldier* army;
    int armySize;
    int color;

    Player(int);
    void destroy();
    string str();
};

//enum class Color { Green = 10, Yellow = 14, Magenta = 13 }; TODO REVIEW

int Player::counter = 0;

string Player::str() {
    string res = "";
    for (int i = 0; i < armySize; i++) {
        res = res + army[i].str();
    }
    return res;
}

void Player::destroy() {
    delete[] army;
}

Player::Player(int size) {
    int colors[] = { 10, 14, 13 }; // TODO change
    id = counter;
    counter++;
    color = colors[id];
    armySize = size;
    army = new Soldier[armySize];
}