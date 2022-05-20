/**
 * Purpose : COMP90077 Adv Algs & DS (2022) - Assignment 2
 * @author Zhen Cai (1049487) <zhcai@student.unimelb.edu.au>
 */

#ifndef ARRAY_H
#define ARRAY_H

#include <algorithm>
#include <cstring>

#include "data.h"
#include "dynamicarray.h"

using namespace std;

#define INIT_LENGTH 1

class DynamicArray
{
private:
    int size = 0;
    int size_max = INIT_LENGTH;
    Data **_arr = new Data*[INIT_LENGTH];
    void resize(const double factor);

public:
    ~DynamicArray();
    void insert(Data *x);
    void remove(const int key);
    Data *search(const int key) const;
};

#endif
