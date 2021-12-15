#include "Consumable.h"
#include "Soldier.h"
#include <iostream>
#include "Player.h"
#include "Utils.h"
using namespace std;

HealthPotion::HealthPotion(Map* map) : Consumable(map) {
	name = "health potion";
	icon = string(1, char(3));
	color = LIGHTRED;
}

void HealthPotion::consume(Soldier* consumer) {
	if (consumer->getPlayer()->isDebugged()) cout << consumer->str() << " drinked " << this->name << ". +" << effect << "HP!" << endl;
	consumer->setHealth(consumer->getHealth() + effect);
	delete this;
}