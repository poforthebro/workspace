/*****************************************************************************
 * TNG033: lecture 3                                                          *
 * Header file defining a List of nodes                                       *
 * Each node stores an int and a pointer to the next node                     *
 * Pointers and dynamic memory allocation are used!!                          *
 * Dummy nodes are used in the implementation of the lists                    *
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
    Node* head = new Node;  // head points to a dummy node
    int number_of_values = 0;  // number of values stored in the list
};

bool is_empty(const List& L);

// Remove all values of the list
void make_empty(List& L);

// Return the number of values stored in list L
int size(const List& L);

// Insert n at the start of list L
void insert_first(List& L, int n);

/*
* Remove the node storing n from list L
* If n is not in the list L then L is not modified
* Note: if there are several nodes storing n
* then this function deletes only the first node
*/
void remove(List& L, int n);

/*
 * Search for a value n in the list
 * Return true, if n is found in list L
 * Otherwise, return false
 */
bool search(const List& L, int n);

void display_list(const List& L);
