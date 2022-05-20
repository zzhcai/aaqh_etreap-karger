#!/bin/bash

# Purpose : COMP90077 Adv Algs & DS (2022) - Assignment 2
# @author Zhen Cai (1049487) <zhcai@student.unimelb.edu.au>

make

echo -e '''
==================================================================

\t\t\t\t\t   Treap\t   Array
'''

./experiment 1 100000
./experiment 1 200000
./experiment 1 500000
./experiment 1 800000
./experiment 1 1000000

echo ''

./experiment 2 0.1
./experiment 2 0.5
./experiment 2 1
./experiment 2 5
./experiment 2 10

echo ''

./experiment 3 0.1
./experiment 3 0.5
./experiment 3 1
./experiment 3 5
./experiment 3 10

echo ''

./experiment 4 100000
./experiment 4 200000
./experiment 4 500000
./experiment 4 800000
./experiment 4 1000000

echo ''
