#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "Soldier.h"
using namespace std;

class Player {
    static int counter;
public:
    int id;
    vector<Soldier> army;
    int armySize;
    int color;

    Player(int);
    string str();
};

//enum class Color { Green = 10, Yellow = 14, Magenta = 13 }; TODO REVIEW