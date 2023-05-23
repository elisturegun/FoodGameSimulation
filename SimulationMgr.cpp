/**
* Author : OYKU ELIS TUREGUN
* ID: 21902976
* Section : 1
* Homework : 3
* Description : SIMULATION CLASS
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Creature.h"
#include "Food.h"
#include "FoodPriorityQueue.h"
#include <cmath>
#include <algorithm>
#include <iomanip>

using namespace std;

/**
 * method to calculate euclidean distance of two coordinates.
 * @param x1
 * @param y1
 * @param x2
 * @param y2
 * @return
 */
double distance(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

int main(int argc, char* argv[]) {

    // INPUT FILE PARSING
    if (argc < 2) {
        cerr << " usage of file " << argv[0] << " input_file.txt" << endl;
        return 1;
    }

    string inputFile = argv[1];
    ifstream input_file(inputFile);

    if (!input_file.is_open()) {
        cerr << " cannot use file : " << inputFile << endl;
        return 1;
    }

    int numOfCreatures;
    vector<Creature> creatures;

    input_file >> numOfCreatures;

    for (int i = 0; i < numOfCreatures; i++) {
        char comma;
        Creature creature;
        creature.isDead = false;
        input_file >> creature.id >> comma >> creature.x >> comma >> creature.y >> comma >> creature.health;
        creatures.push_back(creature);
    }

    // selection sort creatures according to their id's
    for (int i = 0; i < creatures.size() - 1; i++) {
        int loc = i;
        for (int j = i + 1; j < creatures.size(); j++) {
            if (creatures[j].id < creatures[loc].id) {
                loc = j;
            }
        }
        if (loc != i) {
            swap(creatures[i], creatures[loc]);
        }
    }

    // creating queues
    FoodPriorityQueue availableFoods;
    FoodPriorityQueue processedFoods;

    while (!input_file.eof()) {
        char comma;
        Food food;
        input_file >> food.id >> comma >> food.x >> comma >> food.y >> comma >> food.quality >> comma >> food.spawnTime;
        food.isConsumed = false;
        food.isSpawned = false;
        availableFoods.pqInsert(food);
    }

    input_file.close();

    int timeTick = 0;

    Food bestFood;


    while( numOfCreatures > 0 ) {

        // print locations of creatures

        for (auto &creature: creatures) {
            if(creatures.size() >= 0) {
                //cout << "Creature : " << creature.id << "   " << (double) creature.x
                 //    << setprecision(3) << " ,  "
                 //    << (double) creature.y << setprecision(3) << endl;
                cout << "Creature " << creature.id << ": " << fixed << setprecision(2)
                     << (creature.x) << ", "
                     << (creature.y) << endl;

            }

        }

        // spawn foods
        Food foodTo;
        while (!availableFoods.pqIsEmpty() && availableFoods.getHighest().spawnTime == timeTick) {
            foodTo = availableFoods.getHighest();
            foodTo.isSpawned = true;

            processedFoods.pqInsert(foodTo);
            availableFoods.pqDelete(foodTo);

            if (availableFoods.pqIsEmpty()) {
                break;
            }
        }


        // fights
        for (auto &creature1: creatures) {
            if (creature1.health == 0)
                continue;

            for (auto &creature2: creatures) {
                if (creature2.health == 0 || creature1.id == creature2.id )
                    continue;

                double distanceTo = distance(creature1.x, creature1.y, creature2.x, creature2.y);
                if (distanceTo < 2 && creature1.health >= creature2.health) {
                    creature2.health = 0;
                    creature2.isDead = true;

                    numOfCreatures += -1;
                }
            }
        }


        // consume food

        bestFood = processedFoods.getHighest();

        for (int i = 0; i < creatures.size() && !processedFoods.pqIsEmpty(); i++) {
            if (creatures[i].isDead)
                continue;
            double distanceToFood = distance(creatures[i].x, creatures[i].y, bestFood.x, bestFood.y);
            if (distanceToFood < 1.0) {
                creatures[i].health = creatures[i].health + bestFood.quality;
                processedFoods.pqDelete(bestFood);
                bestFood = processedFoods.getHighest();
            }
        }

        // to not move if there is no food
        if(availableFoods.pqIsEmpty()){
            bestFood.id = 888;
        }

        // move creatures
        bestFood= processedFoods.getHighest();

        for (int i = 0; i < creatures.size() && !processedFoods.pqIsEmpty() && bestFood.id != 888; i++) {

            if (creatures[i].isDead){
                continue;
            }
            double coefficient;
            if (creatures[i].health > 10) {
                coefficient = 10.0 / creatures[i].health;
            }
            else {
                coefficient = 1.0;
            }
            double d = distance(bestFood.x, bestFood.y, creatures[i].x, creatures[i].y);
            creatures[i].x += ((bestFood.x - creatures[i].x) / d) * coefficient;
            creatures[i].y += ((bestFood.y - creatures[i].y) / d) * coefficient;
        }

        // decrease the health of creatures
        for (int i = 0; i < creatures.size(); i++) {
            if (creatures[i].isDead)
                continue;
            int health = creatures[i].health;
            creatures[i].health = (health - 1);
            if (creatures[i].health == 0) {
                creatures[i].isDead = true;
                numOfCreatures--;
            }
        }
        // update time tick
        timeTick += 1;
    }

    return 0;
}