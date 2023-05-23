/**
* Author : OYKU ELIS TUREGUN
* ID: 21902976
* Section : 1
* Homework : 3
* Description : FOOD CLASS
*/

#include "Food.h"

Food::Food() {
    this->x = 0;
    this->y = 0;
    this->id = 0;
    this->quality = 0;
    this->spawnTime = 0;
    this->isSpawned = false;
    this->isConsumed = false;
}
    Food::Food(double x, double y, int id, int quality, int spawnTime, bool isSpawned, bool isConsumed) {
        this->x = x;
        this->y = y;
        this->id = id;
        this->quality = quality;
        this->spawnTime = spawnTime;
        this->isConsumed = isConsumed;
        this->isSpawned = isSpawned;
    }

    double Food::getX() const {
        return x;
    }

    double Food::getY() const {
        return y;
    }

    int Food::getID() const {
        return id;
    }

    int Food::getQuality() const {
        return quality;
    }

bool Food::operator>(const Food& oper){
    if(isSpawned) return quality> oper.quality;
    return spawnTime < oper.spawnTime;
}

bool Food::operator<(const Food& oper){
    if(isSpawned) return quality < oper.quality;
    return spawnTime > oper.spawnTime;
}

int Food::getSpawnTime() const {
    return spawnTime;
}



