/**************************************************
 * TNG033: lecture 3                               *
 * Test the List and functions available for Lists *
 * *************************************************/

#include <iostream>

#include "list.h"

int main() {
    List my_list;  // empty list just contains a dummy node

    // Display the list
    std::cout << "My list:  ";
    display_list(my_list);
    std::cout << "My list stores " << size(my_list) << " values\n";

    std::cout << "\nEnter values to insert: ";
    int k;
    while (std::cin >> k) { // end the input with "stop"
        insert_first(my_list, k);
    }

    // Display the list
    std::cout << "\nL:  ";
    display_list(my_list);
    std::cout << "My list stores " << size(my_list) << " values\n";

    /* ****************************** */

    std::cout << "\nSearching ...\n";

    if (search(my_list, 40)) {
        std::cout << "Found 40\n";
    } else {
        std::cout << "40 not found!!\n";
    }

    /* ****************************** */

    std::cout << "\nRemoving 8 and 20...\n";

    remove(my_list, 8);
    remove(my_list, 20);

    // Display the list
    std::cout << "My list:  ";
    display_list(my_list);

    /* ****************************** */

    std::cout << "\nDeleting all values in the list ...\n";
    make_empty(my_list);

    // Display the list
    std::cout << "My list:  ";
    display_list(my_list);

    /* ****************************** */

    // Deallocate the memory for the dummy node
    delete my_list.head;
    // Good programming practice: all memory should be dealocated before the program ends
}
