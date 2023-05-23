/**
* Author : OYKU ELIS TUREGUN
* ID: 21902976
* Section : 1
* Homework : 3
* Description : CREATURE CLASS
*/

#ifndef HW3_21_38_CREATURE_H
#define HW3_21_38_CREATURE_H
class Creature {
public:
    Creature();
    Creature(int id, int health, double x, double y, bool isDead);
    int getID() const;
    int getHealth() const;
    double getX() const;
    double getY() const;

    int id;
    double x;
    double y;
    int health;
    bool isDead;
};
#endif //HW3_21_38_CREATURE_H
