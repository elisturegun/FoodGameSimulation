/**
* Author : OYKU ELIS TUREGUN
* ID: 21902976
* Section : 1
* Homework : 3
* Description : CREATURE CLASS
*/
#include "Creature.h"

Creature::Creature(int id, int health, double x, double y, bool isDead) {
        this->id = id;
        this->health = health;
        this->x = x;
        this->y = y;
        this->isDead = isDead;
}

Creature::Creature() {
    this->id = 0;
    this->health = 0;
    this->x = 0;
    this->y = 0;
    this->isDead = false;
}

    int Creature::getID() const {
        return id;
    }

    int Creature::getHealth() const {
        return health;
    }

    double Creature::getX() const {
        return x;
    }

    double Creature::getY() const {
        return y;
    }


