/*****************************************************************************
 * TNG033: lecture 2                                                          *
 * Header file defining a List of nodes                                       *
 * Each node stores an int and a pointer to the next node                     *
 * Pointers and dynamic memory allocation are used!!                          *
 * ****************************************************************************/

/*
 * A header file only contains
 * - the definition of new types: Node and List
 * - function declarations (no function implementations)
 */

#pragma once

#include <iostream>

struct Node {
    int value = 0;
    Node* next = nullptr;  // points to the next node in the list
};

struct List {
    Node* head = nullptr;  // to point to first node of the list
                           // nullptr represents an empty list

    int number_of_values = 0;  // number of values stored in the list
};

// Return the number of values stored in list L
int size(const List& L);

bool is_empty(const List& L);

// Insert n in the beginning of the list L
void insert_first(List& L, int n);

// Remove first value in the list
void remove_first(List& L);

void display_list(const List& L);
