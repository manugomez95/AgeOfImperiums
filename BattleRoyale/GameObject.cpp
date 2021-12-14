#include "GameObject.h"
#include "Utils.h"
#include "Map.h"

const array<array<int, 2>, 4> GameObject::DIRECTIONS = { {{1,0},{0,1},{-1,0},{0,-1}} };

GameObject::GameObject(Map* map, array<int,2> pos) { // TODO remove pos argument?
	this->map = map;
	this->pos = pos;
	color = WHITE;
}

string GameObject::str() {
	return name;
}