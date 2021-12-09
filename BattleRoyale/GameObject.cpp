#include "GameObject.h"
#include "Utils.h"
#include "Map.h"

const array<array<int, 2>, 4> GameObject::DIRECTIONS = { {{1,0},{0,1},{-1,0},{0,-1}} };

GameObject::GameObject(Map* map, array<int,2> pos) {
	this->map = map;
	this->pos = pos;
	color = LOG_COLOR_WHITE;
	icon = NULL;
}

string GameObject::str() {
	return string(1, char(icon));
}

// allows unit to continue on the other side of the map when it reaches the limit
void GameObject::move(array<int, 2> dir) {
	array<int, 2> new_pos;
	GameObject* tmp = map->matrix[pos[0]][pos[1]];

	new_pos = map->translatePosition(
		array<int, 2> {pos[0] + dir[0], pos[1] + dir[1]});

	// to avoid collisions
	if (map->matrix[new_pos[0]][new_pos[1]] != NULL) return;
	else {
		map->matrix[pos[0]][pos[1]] = NULL;
		map->matrix[new_pos[0]][new_pos[1]] = tmp;

		pos[0] = new_pos[0];
		pos[1] = new_pos[1];
	}
}