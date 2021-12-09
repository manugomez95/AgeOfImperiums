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