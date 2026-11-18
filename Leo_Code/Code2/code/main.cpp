/***************************************************
 * TNG033: lecture 2                               *
 * Test the List and functions available for Lists *
 * *************************************************/

#include <iostream>

#include "list.h"  // this is needed for compiler to see the functions declarations

int main() {
    List L;  // empty list

    // Display the list
    std::cout << "L:  ";
    display_list(L);
    std::cout << "L has " << size(L) << " values\n";

    std::cout << "\nInserting ...\n";

    insert_first(L, 30);
    insert_first(L, 20);
    insert_first(L, 15);
    insert_first(L, 10);

    // Display the list
    std::cout << "L:  ";
    display_list(L);
    std::cout << "L has " << size(L) << " values\n";

    std::cout << "\nDeleting all values in the list ...\n";

    while (!is_empty(L)) {
        remove_first(L);
    }

    // Display the list
    std::cout << "L:  "; 
    display_list(L);
    std::cout << "L has " << size(L) << " values\n";
}
