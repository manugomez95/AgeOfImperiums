#include "Soldier.h"
using namespace std;

string Soldier::str() {
    return string(1, char(2));
}

Soldier::Soldier(int id, Transform* t) {
    playerId = id;
    velocity = 1;
    transform = t;
}