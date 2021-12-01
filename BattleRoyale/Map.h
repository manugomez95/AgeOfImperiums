#pragma once

#include <iostream>
#include <string>
#include <windows.h> // WinApi header
#include "Soldier.h"

#define LOG_COLOR_WHITE 7

using namespace std;

class Map {
public:
    int rows, cols;
    Soldier*** matrix;

    Map(int, int);
    void destroy();
    void print();
};