/***********************************************************************
 * TNG033: lecture 3  -- similar to lecture 2                          *
 * Header file defining a List of nodes                                *
 * Each node stores an int and a pointer to the next node              *
 * Pointers and dynamic memory allocation are used!!                   *
 * No dummy used is used                                               *
 * ******************************************************************** */

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

// Insert n at the start of list L
void insert_first(List& L, int n);

// Remove first value in the list
void remove_first(List& L);

/*
 * Search for a value n in the list
 * Return true, if n is found in list L
 * Otherwise, return false
 */
bool search(const List& L, int n);

void display_list(const List& L);
