#pragma once

#include <array>
#include <string>

using namespace std;

class Map;

// Represents anything that can be placed in the map
class GameObject {
protected:
	string name;
	Map* map;
	array<int, 2> pos;
	int color;
	string icon; // use the ones here: https://en.wikipedia.org/wiki/Code_page_437
public:
	GameObject(Map* map, array<int,2> pos);
	GameObject(Map* map);

	virtual string str();
	string getIcon();
	int getColor();
	array<int, 2> getPosition();
	void setPosition(array<int,2> pos);
};