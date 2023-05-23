/**
* Author : OYKU ELIS TUREGUN
* ID: 21902976
* Section : 1
* Homework : 3
* Description : FOOD  CLASS
*/


#ifndef HW3_21_38_FOOD_H
#define HW3_21_38_FOOD_H
class Food {
public:
    Food();
    Food(double x, double y, int id, int quality, int spawnTime, bool isSpawned, bool isConsumed);
    double getX() const;
    double getY() const;
    int getID() const;
    int getQuality() const;
    int getSpawnTime() const;
    void setID(int newID);
    void setX(double newX);
    void setY(double newY);
    void setQuality(int newQuality);
    void setSpawnTime(int newSpawnTime);
    bool operator>(const Food& oper);
    bool operator<(const Food& oper);


    int quality;
    double y;
    double x;
    int id;
    int spawnTime;
    bool isSpawned;
    bool isConsumed;


};

#endif //HW3_21_38_FOOD_H
