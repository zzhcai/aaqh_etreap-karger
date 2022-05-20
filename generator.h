/**
 * Purpose : COMP90077 Adv Algs & DS (2022) - Assignment 2
 * @author Zhen Cai (1049487) <zhcai@student.unimelb.edu.au>
 */

#ifndef GEN_H
#define GEN_H

#include <map>
#include <random>

#include "data.h"

using namespace std;

enum Op {
    INSERTION, DELETION, SEARCH
};

/**
 * Job definition, output of generator.
 */
struct Job {
    short op;
    Data *_e;    // NULL for DELETION and SEARCH op
    int key;
    Job(short op, Data *_e, int key) : op(op), _e(_e), key(key) {}
};

/**
 * Data generator for the experiment.
 */
class Generator
{
private:
    static int id_next;
    /** (id, key), deleted items should have key -1 */
    map<int, int> els;
    Data *gen_element();

public:
    Job gen_insertion();
    Job gen_deletion();
    Job gen_search() const;
};

#endif
