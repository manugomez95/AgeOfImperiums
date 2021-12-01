#pragma once

#include "Map.h"

class Transform {
public:
	Map* map;
	int pos[2];

	Transform(Map*, int[2]);
	void move(int, int);
};