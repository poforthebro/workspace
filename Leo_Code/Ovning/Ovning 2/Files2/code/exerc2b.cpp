/***********************************************
 * TNG033: Practice session 2                  *
 * Exercise 2b                                 *
 * *********************************************/

/*
 * Is there any problem with this code?
 * If so, describe the problem?
 * How can it be fixed without modifying the functions' meaning 
 * 
 * The problem is that we try to delete nodes that arent allocated
 * 
 * 
 */

#include <iostream>

struct Node {
    int value = 0;
    Node* next = nullptr;  // points to the next node in the list
};

struct List {
    Node* head = new Node;     // head points to a dummy node
    int number_of_values = 0;  // number of values stored in the list
};

/*
 * Insert n at the start of list L -- after the dummy node
 */
void insert_first(List& L, int n) {
     Node newNode; // We create teh new node // This node is not in heap since it isnt initiated using new
    Node* ptr_newNode = new Node; // pointer to the new node

    ptr_newNode->value = n; // New node gets a value
    ptr_newNode->next = L.head->next;  // link the new node to the node after the dummy node

    L.head->next = ptr_newNode;  // dummy node should point to new node
    ++L.number_of_values;        // increment the counter of number of nodes in the list

    Node* p = &newNode;
    delete p;


} // 

/*
 * Remove all values of the list
 * All nodes are deleted except the dummy node
 */
void make_empty(List& L) {
    if (L.number_of_values == 0) {  // if list is empty then no nodes need to be deallocated
        return;
    }

    Node* ptr = L.head->next;  // point to the node after the dummy node

    while (ptr != nullptr) {  // while not end of the list
        Node* to_delete = ptr;
        ptr = ptr->next;  // make ptr to point to next node

        delete to_delete; // We delete memory that isnt allocated. THis is weird !!!!!!!!!!!!!!!
    }
    L.head->next = nullptr;  // there's no node after the dummy node
    L.number_of_values = 0;
}

void display_list(const List& L) {
    if (L.number_of_values == 0) {
        std::cout << "empty!!\n";
    } else {
        for (Node* ptr = L.head->next; ptr != nullptr; ptr = ptr->next) {
            std::cout << ptr->value << "->";
        }
        std::cout << "\n";
    }
}

int main() {
    List L;  // empty list
    display_list(L);

    // Insert some values
    insert_first(L, 6);
    insert_first(L, 4);
    insert_first(L, 2);

    display_list(L);

    // make_empty(L);
    // delete L.head;
}