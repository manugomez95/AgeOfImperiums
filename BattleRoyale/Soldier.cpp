#include "Soldier.h"
#include "Utils.h"
#include "GameObject.h"
#include "Map.h"
#include "Player.h"
using namespace std;

Soldier::Soldier(Player* player, Map* map, array<int,2> pos) : GameObject(map, pos) {
    this->player = player;
    name = Utils::SILLY_NAMES[Utils::randomRange(0, Utils::SILLY_NAMES->size() - 1)];
    velocity = 1;
    icon = string(1, char(2));
    color = player->color;
    dead = false;
    health = 50;
    damage = 10;
    dodgeChance = 0.3f;
}

void Soldier::combat() {
    // Attack if enemy near
    vector<Soldier*> enemies = getEnemiesAround();
    if (enemies.empty()) return;

    int randomIndex = Utils::randomRange(0, enemies.size() - 1);
    Soldier* luckyGuy = enemies[randomIndex];
    
    if (player->debug) cout << this->str() << " attacks " << luckyGuy->str() 
        << " (health: " << luckyGuy->health << ")" << endl;
    
    luckyGuy->receiveAttack(damage);

    /*for (Soldier*& s : enemies) {
        s->color = 13;
        s->dead = true;
    }*/
}

// Dead don't count
vector<Soldier*> Soldier::getEnemiesAround() {
    vector<Soldier*> soldiers;
    for (auto d : GameObject::DIRECTIONS) {
        Soldier* go = dynamic_cast<Soldier*> (map->get({ pos[0] + d[0], pos[1] + d[1] }));
        if (go && go != this && go->player != this->player && !go->dead) soldiers.push_back(go);
    }
    return soldiers;
}

void Soldier::receiveAttack(int receivedDamage) {
    if (Utils::randomRange(0, 10) / 10.0f < dodgeChance) {
        if (player->debug) cout << this->str() << " dodges the sword!" << endl;
        return;
    }
    health -= receivedDamage;
    if (health <= 0) {
        dead = true;
        player->armySize--;
        color = 13;

        if (player->debug) cout << this->str() << " dies :(" << endl;
    }
}

string Soldier::str() {
    return name + "[" + player->str() + "] ";
}