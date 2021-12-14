#pragma once

#include <array>
#include <string>

using namespace std;

class Map;

// Represents anything that can be placed in the map
// TODO make abstract
class GameObject {
public:
	static const array<array<int, 2>, 4> DIRECTIONS;

	GameObject(Map* map, array<int,2> pos);

	Map* map;
	array<int,2> pos;
	int color;
	string icon;

	virtual string str();
	virtual void move(array<int, 2>);
};