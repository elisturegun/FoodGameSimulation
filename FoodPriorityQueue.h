/**
* Author : OYKU ELIS TUREGUN
* ID: 21902976
* Section : 1
* Homework : 3
* Description : PRIORITY QUEUE CLASS
*/


#ifndef HW3_21_38_FOODPRIORITYQUEUE_H
#define HW3_21_38_FOODPRIORITYQUEUE_H
#include "Heap.h"// ADT heap operations
typedef Food PQItemType;

class FoodPriorityQueue {
public:
    // default constructor, copy constructor, and destructor
    // are supplied by the compiler

    // priority-queue operations:
    bool pqIsEmpty() const;
    void pqInsert(const PQItemType& newItem);
    void pqDelete(PQItemType& priorityItem);
    PQItemType getHighest();

private:
    Heap h;
};

#endif //HW3_21_38_FOODPRIORITYQUEUE_H
