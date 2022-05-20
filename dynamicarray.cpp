/**
 * Purpose : COMP90077 Adv Algs & DS (2022) - Assignment 2
 * @author Zhen Cai (1049487) <zhcai@student.unimelb.edu.au>
 */

#include "dynamicarray.h"

inline void DynamicArray::resize(const double factor)
{
    Data **tmp = new Data*[(size_max*=factor)];
    memcpy(tmp, _arr, sizeof(Data*)*size);    // copy elements
    delete [] _arr;
    _arr = tmp;
}

void DynamicArray::insert(Data *x)
{
    if (size == size_max) {
        resize(2.0);
    }
    _arr[size++] = x;
}

void DynamicArray::remove(const int key)
{
    for (int i = 0; i < size; i++)
    {
        if (_arr[i]->key == key) {
            swap(_arr[i], _arr[size-1]);
            delete _arr[(size--)-1];
            // If the current number of elements is smaller than 1/4 length of the current array,
            // shrink the length of the array into half
            if (size < size_max / 4) {
                resize(0.5);
            }
            break;
        }
    }
}

Data *DynamicArray::search(const int key) const
{
    for (int i = 0; i < size; i++) {
        if (_arr[i]->key == key) {
            return _arr[i];
        }
    }
    return NULL;    // not found
}

DynamicArray::~DynamicArray()
{
    for (int i = 0; i < size; i++) {
        delete _arr[i];
    }
    delete [] _arr;
}
