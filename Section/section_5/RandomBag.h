/******************************************************
 * File: RandomBag.h
 *
 * A class representing a bag of elements in which
 * values can be added and then removed randomly.
 */
#pragma once
#include "vector.h"

class RandomBag {
public:
    void add(int value);
    int  removeRandom();
    int  size() const;
    bool isEmpty() const;

private:
    Vector<int> elems;
};

