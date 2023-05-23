/**
* Author : OYKU ELIS TUREGUN
* ID: 21902976
* Section : 1
* Homework : 3
* Description : HEAP CLASS
*/

#ifndef HW3_21_38_HEAP_H
#define HW3_21_38_HEAP_H
#include "Food.h"
const int MAX_HEAP = 30;


class Heap {
public:
    Heap();				// default constructor
    // copy constructor and destructor are supplied by the compiler

    bool heapIsEmpty() const;
    void heapInsert(const Food& newItem);
    void heapDelete(Food& rootItem);
    Food getMax();


protected:
    void heapRebuild(int root);		// Converts the semiheap rooted at
    // index root into a heap
private:
    // array of heap items
    Food items[MAX_HEAP];
    int          size;            	// number of heap items
};

#endif //HW3_21_38_HEAP_H
