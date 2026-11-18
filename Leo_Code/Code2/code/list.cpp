/*************************************************
 * TNG033: lecture 2                              *
 * Definition of functions declared in list.h     *
 * ************************************************/

/*
 * Source file with the implementation of the functions declared in list.h
 * There's no main function in this file
 */

#include "list.h"

// Return the number of values stored in list L
int size(const List& L) {
    return L.number_of_values;
}
// Size is stored in vanumber_of_values

// Empty if the head points to null
bool is_empty(const List& L) {
    return (L.head == nullptr);
    // return (L.number_of_values == 0);
}

// Insert n in the beginning of the list L
void insert_first(List& L, int n) {
    Node* ptr = new Node;  // create a new node in the heap

    ptr->value = n;      // store value n in the node
    ptr->next = L.head;  // link the new node to the first node of list L
    L.head = ptr;        // update L.head to point to the new node

    // increment number of nodes in the list
    ++L.number_of_values;
}
// We first create the new node. Then we update the value in new ptr to node then we update the point to next L.head Then L.head points to the new value. 
// We increase number of values 

// Remove first value in the list
void remove_first(List& L) {
    if (is_empty(L)) {
        return;
    }

    Node* first = L.head;
    L.head = L.head->next;  // head should point to the second node

    // Delete first node
    delete first;
    first = nullptr;       // pointer first is pointing to nothing
    --L.number_of_values;  // decrement number of nodes in the list
}
// First check that the list isn't empty! Create a pointer to the L head. We set it so that L.head points to the next value. Now we can delete the first value. We set first = nullptr
// Decrease the value

void display_list(const List& L) {
    if (is_empty(L)) {
        std::cout << "List is empty!!\n";
    } else {
        for (Node* p = L.head; p != nullptr; p = p->next) {
            std::cout << p->value << "->";
        }
        std::cout << "\n";
    }
}