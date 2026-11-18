/***************************************************
 * TNG033: lecture 3                               *
 * Test the List and functions available for Lists *
 * *************************************************/

#include <iostream>

#include "list.h"

int main() {
    List my_list;  // empty list

    // Display the list
    std::cout << "My list:  ";
    display_list(my_list);
    std::cout << "My list has " << size(my_list) << " values\n";

    std::cout << "\nInserting ...\n";

    insert_first(my_list, 30);
    insert_first(my_list, 20);
    insert_first(my_list, 15);
    insert_first(my_list, 10);

    // Display the list
    std::cout << "My list:  ";
    display_list(my_list);
    std::cout << "My list has " << size(my_list) << " values\n\n";

    // Search for 15
    if (search(my_list, 15)) {
        std::cout << "15 is in my list\n";
    } else {
        std::cout << "15 is not in my list\n";
    }

    std::cout << "\nDeleting all values in my list ...\n";

    while (!is_empty(my_list)) {
        remove_first(my_list);
    }

    // Display the list
    std::cout << "My list:  ";
    display_list(my_list);
    std::cout << "My list has " << size(my_list) << " values\n";
}
