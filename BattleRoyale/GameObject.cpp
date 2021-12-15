#include "GameObject.h"
#include "Utils.h"
#include "Map.h"

GameObject::GameObject(Map* map, array<int,2> pos) {
	this->map = map;
	this->pos = pos;
	color = WHITE;
}

GameObject::GameObject(Map* map) : GameObject(map, map->add(this)) {}

string GameObject::str() {
	return name;
}

string GameObject::getIcon() {
	return icon;
}

int GameObject::getColor() {
	return color;
}

array<int, 2> GameObject::getPosition() {
	return pos;
}

void GameObject::setPosition(array<int, 2> pos) {
	this->pos = pos;
}