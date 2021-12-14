#include "Consumable.h"
#include "Soldier.h"
#include <iostream>
#include "Player.h"
using namespace std;

HealthPotion::HealthPotion(Map* map, array<int, 2> pos) : Consumable(map, pos) {
	name = "health potion";
	icon = string(1, char(3));
	color = 13;
}

void HealthPotion::consume(Soldier* consumer) {
	int oldHealth = consumer->health;
	consumer->health += effect;
	if (consumer->player->debug) cout << consumer->str() << " drinked " << this->name << ". Health goes from " << oldHealth << " to " << consumer->health;
}