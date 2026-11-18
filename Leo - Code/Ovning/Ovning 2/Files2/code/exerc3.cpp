/***********************************************
 * TNG033: set of exercises 2                  *
 * Exercise 3b                                 *
 * *********************************************/


// Displayed at line 10: Value of first_ptr value of second pointer
// Displayed at line 10: 4 4



#include <iostream>

int main() {
    int* first_ptr;
    first_ptr = new int; // pointer to an INT

    int* second_ptr; // ponter to an INT
    second_ptr = new int;

    int** p_ptr; // pointer to a pointer to an int
    p_ptr = &first_ptr; // points to the first pointer

    *first_ptr = 4;
    *second_ptr = 8;
    delete second_ptr;
    second_ptr = *p_ptr; // Second pointer points to first pointer. We also loose access to the original second pointer. Mem leak
    std::cout << *first_ptr << " " << *second_ptr << '\n';

    delete first_ptr;    // Deletes the first int
    // delete second_ptr;  // Tries to delete first int again. Problem
    // delete *p_ptr;  // Tries to delete the first int ones more. Not good!
}