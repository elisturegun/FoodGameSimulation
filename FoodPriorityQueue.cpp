/**
* Author : OYKU ELIS TUREGUN
* ID: 21902976
* Section : 1
* Homework : 3
* Description : PRIORITY QUEUE CLASS
*/


#include "FoodPriorityQueue.h"
bool FoodPriorityQueue::pqIsEmpty() const {
    return h.heapIsEmpty();
}

void FoodPriorityQueue::pqInsert(const PQItemType& newItem){


        h.heapInsert(newItem);


}

void FoodPriorityQueue::pqDelete(PQItemType& priorityItem){


        h.heapDelete(priorityItem);


}

PQItemType FoodPriorityQueue::getHighest() {

        return h.getMax();

}
