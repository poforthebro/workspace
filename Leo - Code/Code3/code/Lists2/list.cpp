/*************************************************
 * TNG033: Fö 3                                   *
 * Definition of functions declared in list.h     *
 * ************************************************/

#include "list.h"

bool is_empty(const List& L) {
    // return (L.head->next == nullptr);
    return (size(L) == 0);
}

/*
* Remove all values of the list
* All nodes are deleted except the dummy node
*/
void make_empty(List& L) {
    if (is_empty(L)) { // if list is empty then no nodes need to be deallocated
        return;
    }

    Node* ptr = L.head->next; // point to the node after the dummy node

    while (ptr != nullptr) { // while not end of the list 
        Node* to_delete = ptr;
        ptr = ptr->next; // make ptr to point to next node

        delete to_delete;
    }
    L.head->next = nullptr; // there's no node after the dummy node
    L.number_of_values = 0;
}

// Return the number of values stored in list L
int size(const List& L) {
    return L.number_of_values;
}

/*
* Insert n at the start of list L -- after the dummy node
*/
void insert_first(List& L, int n) {
    Node* newNode = new Node;

    newNode->value = n;
    newNode->next = L.head->next;  // link the new node to the node after the dummy node

    L.head->next = newNode;  // dummy node should point to new node
    ++L.number_of_values;    // increment the counter of number of nodes in the list
}

/*
 * Remove the node storing n from list L
 * If n is not in the list L then L is not modified
 * Note: if there are several nodes storing n
 * then this function deletes only the first node
 */
void remove(List& L, int n) {
    Node* ptr1 = L.head;

    // 1. Find the node before the node to be removed
    while ((ptr1->next != nullptr) && (ptr1->next->value != n)) {
        ptr1 = ptr1->next;
    }

    if (ptr1->next == nullptr) {  // n not found in list L
        return;
    }

    // 2. Remove
    Node* ptr2 = ptr1->next;  // ptr2 points to the node to be removed
    ptr1->next = ptr2->next;  // bypass the node to be removed

    // 3. Deallocate the memory of the node pointed by ptr2
    delete ptr2;
    --L.number_of_values;  // decrement the counter of number of nodes in the list
}

/*
 * Search for a value n in the list
 * Return true, if n is found in list L
 * Otherwise, return false
 */
bool search(const List& L, int n) {
    Node* ptr = L.head->next;  // skip the dummy node

    while ((ptr != nullptr) && (ptr->value != n)) {
        ptr = ptr->next;
    }
    return (ptr != nullptr);
}

void display_list(const List& L) {
    if (is_empty(L)) {
        std::cout << "empty!!\n";
    } else {
        for (Node* ptr = L.head->next; ptr != nullptr; ptr = ptr->next) {
            std::cout << ptr->value << "->";
        }
        std::cout << "\n";
    }
}

