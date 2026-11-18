/******************************************************************
 * TNG033: övning 1 / exercise 1                                  *
 * Review lecture 3                                               *
 * Definition of functions declared in list.h                     *
 * ****************************************************************/

#include "list.h"

bool is_empty(const List& L) {
    return (L.head->next == nullptr);
}

// Test whether list L is sorted
bool is_sorted(const List& L) {
    return L.is_sorted_increasingly;
}

/*
 * Make list L empty
 * All nodes are deleted except the dummy node
 */
void make_empty(List& L) {
    if (is_empty(L)) {  // if list is empty then no nodes need to be deallocated
        return;
    }

    Node* ptr = L.head->next;  // point to the node after the dummy node
    while (ptr != nullptr) {   // end of the list?
        Node* to_delete = ptr;
        ptr = ptr->next;  // make ptr to point to next node

        delete to_delete;  // free the memory
    }
    L.head->next = nullptr;  // there's no node after the dummy node
    L.is_sorted_increasingly = true;      // an empty list is sorted
}

// Insert n in the start of the list L -- after the dummy node
void insert_first(List& L, int n) {
    if (is_empty(L) == false and    // is list L not empty?
        n > L.head->next->value) {  // is n larger than the first value in list L?
        L.is_sorted_increasingly = false;
    }
    Node* newNode = new Node;  // create a new node
    newNode->value = n;        // store n in the new node

    // link the new node to the node after the dummy node
    newNode->next = L.head->next;
    L.head->next = newNode;
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

/* ************* TODO **************** */

// Return the number of occurrences of value in list L
int frequency(const List& L, int value) {
    // ADD CODE
    Node* ptr = L.head->next;
    
    int oc = 0;
    if (is_empty(L)) {
        return oc;
    }
    
    while (ptr != nullptr) {
        if (value == ptr->value) {
            oc++;
        }
            ptr = ptr->next;
    }
    return oc;
}
    
 // Insert n at the end of list L
void insert_last(List& L, int n) {
    Node* listptr = L.head;

    Node* ptr = new Node;
    ptr->value = n;
    ptr->next = nullptr;

    if (is_empty(L)) {                          
        listptr->next = ptr;
        return;
    }


    while (listptr->next != nullptr) {
        listptr = listptr->next;
    }
    listptr->next = ptr;
    
    
    
}
/*
// Return a copy of list L
List copy(const List& L) {
    List copy_;  // empty list
    // ADD CODE
    return copy_;
}
*/