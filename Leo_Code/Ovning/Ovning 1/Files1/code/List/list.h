/*****************************************************************************
 * TNG033: övning 1 / exercise 1                                               *
 * Review lecture 3                                                           *
 * Header file defining a List of nodes                                       *
 * Each node stores an int and a pointer to the next node                     *
 * Pointers and dynamic memory allocation are used!!                          *
 * ****************************************************************************/

#pragma once

#include <iostream>

/*
 * Dummy nodes are used in the implementation of the lists
 */

struct Node {
    int value = 0;
    Node* next = nullptr;  // points to the next node in the list
};

struct List {
    Node* head = new Node;               // head points to a dummy node
    bool is_sorted_increasingly = true;  // whether the list is sorted increasingly
};

// Test whether list L is sorted
bool is_sorted(const List& L);

// Test if list L is empty
bool is_empty(const List& L);

// Make list L empty
void make_empty(List& L);

// Insert n at the start of the list L
void insert_first(List& L, int n);

void display_list(const List& L);

/* ************* TODO **************** */

// Return the number of occurrences of value in list L
int frequency(const List& L, int value);

// Insert n at the end of list L
void insert_last(List& L, int n);

// Return a copy of list L
List copy(const List& L);