/**
 * Purpose : COMP90077 Adv Algs & DS (2022) - Assignment 2
 * @author Zhen Cai (1049487) <zhcai@student.unimelb.edu.au>
 */

#ifndef TREAP_H
#define TREAP_H

#include <climits>
#include <cstdlib>

#include "data.h"
#include "treap.h"

using namespace std;

enum Direction {
    LEFT, RIGHT
};

struct Node {
    Data *data;      // (id, key), element
    int priority;    // uniformly and independently drawn
    Node *left, *right;
    Node(Data *data) : data(data), left(NULL), right(NULL), priority(rand()) {}
};

class Treap
{
private:
    Node *root = NULL;
    void rotate(Node * &p, const Direction d) const;
    void insert(Node * &p, Data *x) const;
    void remove(Node * &p, const int key) const;
    void free(Node *subroot) const;

public:
    ~Treap();
    void insert(Data *x);
    void remove(const int key);
    Data *search(const int key) const;
};

#endif
