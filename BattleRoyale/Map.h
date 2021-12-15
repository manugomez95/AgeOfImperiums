#pragma once

#include <string>
#include <array>

using namespace std;

class GameObject;

class Map {
private:
    int rows, cols;
    GameObject*** matrix;
public:
    Map(int, int);

    array<int, 2> translatePosition(array<int, 2>);
    GameObject* get(array<int, 2>);

    // adds gameObject to random position in map and avoids collisions
    array<int, 2> add(GameObject* go);
    void setPos(array<int, 2> pos, GameObject* go);

    void print(bool grid);
    void destroy();
};