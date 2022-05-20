# Purpose : COMP90077 Adv Algs & DS (2022) - Assignment 2
# @author Zhen Cai (1049487) <zhcai@student.unimelb.edu.au>

CC=g++
CFLAGS=-Wall -Wpedantic -Wno-reorder -std=c++11 -g

experiment: *.o
	$(CC) -o experiment main.o generator.o treap.o dynamicarray.o $(CFLAGS)

%.o: %.cpp %.h
	$(CC) -c $< $(CFLAGS)

format:
	clang-format -i *.cpp *.h

clean:
	rm -f experiment *.o
