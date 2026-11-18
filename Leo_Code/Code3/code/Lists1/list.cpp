/*************************************************
 * TNG033: lecture 3                              *
 * Definition of functions declared in list.h     *
 * ************************************************/

#include "list.h"

// Return the number of values stored in list L
int size(const List& L) {
    return L.number_of_values;
}

bool is_empty(const List& L) {
    return (L.head == nullptr);
    // return (L.number_of_values == 0);
}

/*
* Insert n at the start of list L
* L points to the first node of the list
*/
void insert_first(List& L, int n) {
    Node* ptr = new Node;

    ptr->value = n;
    ptr->next = L.head;  // link the new node to the first node of list L
    L.head = ptr;        // update L.head to point to the new node

    // Increment number of nodes in the list
    ++L.number_of_values;
}

/*
* Remove first value in the list
* L points to the first node of the list
*/
void remove_first(List& L) {
    if (is_empty(L)) {
        return;
    }

    Node* first = L.head;
    L.head = L.head->next;  // head should point to the second node

    // Delete first node
    delete first;
    first = nullptr;
    --L.number_of_values;  // Decrement number of nodes in the list
}


/*
 * Search for a value n in the list
 * Return true, if n is found in list L
 * Otherwise, return false
 */
bool search(const List& L, int n) {
    Node* ptr = L.head;

    while ((ptr != nullptr) && (ptr->value != n)) {
        ptr = ptr->next;
    }
    return (ptr != nullptr);
}


void display_list(const List& L) {
    if (is_empty(L)) {
        std::cout << "empty!!\n";
    } else {
        for (Node* ptr = L.head; ptr != nullptr; ptr = ptr->next) {
            std::cout << ptr->value << "->";
        }
        std::cout << "\n";
    }
}