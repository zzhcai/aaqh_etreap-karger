/**
 * Purpose : COMP90077 Adv Algs & DS (2022) - Assignment 2
 * @author Zhen Cai (1049487) <zhcai@student.unimelb.edu.au>
 */

#ifndef EXP_H
#define EXP_H

#include <chrono>
#include <iomanip>
#include <iostream>
#include <sstream>

#include "generator.h"
#include "treap.h"
#include "dynamicarray.h"

using namespace std;
using namespace chrono;

void exp_1(int L_ins);
void exp_2(double del_percent);
void exp_3(double sch_percent);
void exp_4(int L_ins);
void run_treap(Job j);
void run_arr(Job j);

#endif
