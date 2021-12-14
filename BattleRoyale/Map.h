#pragma once

#include <iostream>
#include <string>
#include <array>

using namespace std;

class GameObject;

class Map {
public:
    int rows, cols;
    GameObject*** matrix;

    Map(int, int);

    array<int, 2> translatePosition(array<int, 2>);
    GameObject* get(array<int, 2>);
    bool add(GameObject* go);
    void destroy();
    void print(bool grid);
};