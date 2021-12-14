#include "Soldier.h"
#include "Utils.h"
#include "GameObject.h"
#include "Map.h"
#include "Player.h"
#include "Consumable.h"
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
    sightRange = 3;
}

// allows unit to continue on the other side of the map when it reaches the limit
void Soldier::move(array<int, 2> dir) {
    array<int, 2> new_pos;
    GameObject* tmp = map->matrix[pos[0]][pos[1]];

    new_pos = map->translatePosition(
        array<int, 2> {pos[0] + dir[0], pos[1] + dir[1]});

    GameObject* go = map->matrix[new_pos[0]][new_pos[1]];

    // If object in new position is consumable...
    if (Consumable* c = dynamic_cast<Consumable*> (go)) {
        c->consume(this);
    }
    // If object in new position is a soldier...
    else if (Soldier* s = dynamic_cast<Soldier*> (go)) {
        // to avoid collisions
        if (!isEnemy(s)) move(GameObject::DIRECTIONS[Utils::randomRange(0, 3)]);
        return;
    }
    
    // actual movement
    map->matrix[pos[0]][pos[1]] = NULL;
    map->matrix[new_pos[0]][new_pos[1]] = tmp;

    pos[0] = new_pos[0];
    pos[1] = new_pos[1];
}

void Soldier::move() {
    GameObject* target = NULL; // = getNearestEnemy();
    if (health < 30) target = getNearestPotion();
    if (!target) target = getNearestEnemy();

    bool pickRandomly = false;
    int moveVertical = Utils::randomRange(0, 1);
    if (!target) move(GameObject::DIRECTIONS[Utils::randomRange(0, 3)]);
    else {
        int dir_x = target->pos[0] - pos[0];
        int dir_y = target->pos[1] - pos[1];
        while (true) {
            if (dir_x == 0 || (pickRandomly && moveVertical)) {
                move({ 0, (dir_y < 0) ? -1 : 1 });
                return;
            }
            else if (dir_y == 0 || (pickRandomly && !moveVertical)) {
                move({ (dir_x < 0) ? -1 : 1, 0 });
                return;
            }
            else {
                pickRandomly = true;
            }
        }
    }
}

void Soldier::combat() {
    // Attack if enemy near
    vector<Soldier*> enemies = getEnemiesAround();
    if (enemies.empty()) return;

    int randomIndex = Utils::randomRange(0, enemies.size() - 1);
    Soldier* luckyGuy = enemies[randomIndex];
    
    if (player->debug) cout << this->str() << " attacks " << luckyGuy->str() << endl;
    
    luckyGuy->receiveAttack(damage);
}

// Dead don't count
vector<Soldier*> Soldier::getEnemiesAround() {
    vector<Soldier*> soldiers;
    for (auto d : GameObject::DIRECTIONS) {
        Soldier* s = dynamic_cast<Soldier*> (map->get({ pos[0] + d[0], pos[1] + d[1] }));
        if (isEnemy(s)) soldiers.push_back(s);
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
    return player->str() + ":" + name + " (HP: " + to_string(health) + ")";
}

Soldier* Soldier::getNearestEnemy() {
    int minDistance = 10000;
    Soldier* nearestEnemy = NULL;
    for (int i = pos[0] - sightRange; i <= pos[0] + sightRange; i++) {
        for (int j = pos[1] - sightRange; j <= pos[1] + sightRange; j++) {
            Soldier* s = dynamic_cast<Soldier*> (map->get({ i,j }));
            if (isEnemy(s)) {
                int distance = abs(s->pos[0] - pos[0]) + abs(s->pos[1] - pos[1]);
                if (distance < minDistance) {
                    minDistance = distance;
                    nearestEnemy = s;
                }
            }
        }
    }

    return nearestEnemy;
}

HealthPotion* Soldier::getNearestPotion() {
    int minDistance = 10000;
    HealthPotion* nearestPotion = NULL;
    for (int i = pos[0] - sightRange; i <= pos[0] + sightRange; i++) {
        for (int j = pos[1] - sightRange; j <= pos[1] + sightRange; j++) {
            HealthPotion* p = dynamic_cast<HealthPotion*> (map->get({ i,j }));
            if (p) {
                int distance = abs(p->pos[0] - pos[0]) + abs(p->pos[1] - pos[1]);
                if (distance < minDistance) {
                    minDistance = distance;
                    nearestPotion = p;
                }
            }
        }
    }

    return nearestPotion;
}

bool Soldier::isEnemy(Soldier* s) {
    return s && s != this && s->player != this->player && !s->dead;
}