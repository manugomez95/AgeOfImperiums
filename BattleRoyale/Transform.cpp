#include "Transform.h"

Transform::Transform(Map* map, int p[2]) {
	this->map = map;
	pos[0] = p[0];
	pos[1] = p[1];
}

// allows unit to continue on the other side of the map when it reaches the limit
void Transform::move(int x, int y) {
	int new_pos[2];
	Soldier* tmp = map->matrix[pos[0]][pos[1]];

	if (pos[0] + x < 0) new_pos[0] = map->rows + x;
	else new_pos[0] = (pos[0] + x) % map->rows;
	
	if (pos[1] + y < 0) new_pos[1] = map->cols + y;
	else new_pos[1] = (pos[1] + y) % map->cols;
	
	// to avoid collisions
	if (map->matrix[new_pos[0]][new_pos[1]] != NULL) return;
	else {
		map->matrix[pos[0]][pos[1]] = NULL;
		map->matrix[new_pos[0]][new_pos[1]] = tmp;

		pos[0] = new_pos[0];
		pos[1] = new_pos[1];
	}
}