/******************************************************************
 * TNG033: �vning 1 / exercise 1                                  *
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
    int freq = 0;

    if(is_empty(L)) {
        std::cout << "empty!!";
        return 0;
    }

    Node* ptr = L.head->next;

    while(ptr != nullptr) {

        if(ptr->value == value) {
            ++freq;
        }


        ptr = ptr->next;
    }
  
    return freq; 
}

// Insert n at the end of list L
void insert_last(List& L, int n) {
   // ADD CODE
   
    // Create the new node
   Node* newNode = new Node;
    newNode->value = n;
    newNode->next = nullptr;

    // Check if the list L is empty
    if(is_empty(L)) {
        L.head->next = newNode; // We beed the -> next since the head points to the dummy node that we want to keep
        L.is_sorted_increasingly = true;

        return;
    }
            
        // if the list wasnt empty we find the last Node in the list
        Node* ptr = L.head;

        while(ptr->next != nullptr) {

            ptr = ptr->next;
        }
        
        int previous_value = ptr->value;

        if(newNode->value < previous_value) {
            L.is_sorted_increasingly = false;
        }

        ptr->next = newNode; 

}

// Return a copy of list L
List copy(const List& L) {
    List copy_;  // empty list
    copy_.is_sorted_increasingly = L.is_sorted_increasingly;

    Node* ptr = L.head->next; // Pointer to the next node( the one after the dumme node)
    Node* node = new Node; // Create the new node that we will copy to
    copy_.head->next = node; // The head points to this new node
    
    // ptr2 = copy_.head;
    // We only need to add a new node
    // copy value
    // ptr to new node
    // ADvance


    while(ptr != nullptr) {
        // Create a new node
        // previous node points to new node
        // Copy values
        Node* newNode = new Node; 
        node->next = newNode;                        // We want the previous node to point to this adress

        newNode->value = ptr->value;

        node = newNode;
        ptr = ptr->next;
    }
    

    return copy_;
}