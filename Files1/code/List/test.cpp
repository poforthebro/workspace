/**************************************************
 * TNG033: övning 1 / exercise 1                   *
 * See lecture 3                                   *
 * Test program for Lists                          *
 * *************************************************/

#include <iostream>

#include "list.h"

int main() {
    List my_list;  // empty list

    // Display the list
    std::cout << "My list:  ";
    display_list(my_list);

    insert_first(my_list, 30);
    insert_first(my_list, 20);
    insert_first(my_list, 20);
    insert_first(my_list, 15);
    insert_first(my_list, 10);

    // Display the list
    std::cout << "My list:  ";
    display_list(my_list);  // 10->15->20->20->30

    if (is_sorted(my_list)) {
        std::cout << "My list is sorted increasingly\n";
    }
    else {
        std::cout << "My list is not sorted increasingly\n";
    }

    /* ********* Test frequency ******** */
    std::cout << "\nTest frequency...\n";

    std::cout << "\nfrequency(20): " << frequency(my_list, 20) << "\n";
    std::cout << "frequency(30): " << frequency(my_list, 30) << "\n";

    /* ********* Test insert_last ******** */
    std::cout << "\nTest insert_last...\n";

    List another_list;  // empty list

    insert_last(another_list, 30);
    insert_last(another_list, 20);
    insert_last(another_list, 20);
    insert_last(another_list, 15);
    insert_last(another_list, 10);

    // Display the list
    std::cout << "\nAnother list:  ";
    display_list(another_list);  // 30->20->20->15->10

    if (is_sorted(another_list)) {
        std::cout << "Another list is sorted increasingly\n";
    } else {
        std::cout << "Another list is not sorted increasingly\n";
    }
}
    /* ********* Test copy ******** */
    /*
    std::cout << "\nTest copy...\n";

    List my_list_copy = copy(my_list);

    // Display copy of my_list
    std::cout << "\nCopy of my list:  ";
    display_list(my_list_copy);  // 10->15->20->20->30

    if (is_sorted(my_list_copy)) {
        std::cout << "Copy of my list is sorted increasingly\n";
    } else {
        std::cout << "Copy of my list is not sorted increasingly\n";
    }
    */
    /* **************************** */
    /*
    std::cout << "\nFree all memory used by the lists ...\n";
    make_empty(my_list);
    make_empty(another_list);
    make_empty(my_list_copy);

    // Display the lists
    std::cout << "My list:  ";
    display_list(my_list);
    std::cout << "Another list:  ";
    display_list(another_list);
    std::cout << "Copy of my list:  ";
    display_list(my_list_copy);

    // Dealocate the memory for the dummy nodes
    delete my_list.head;
    delete another_list.head;
    delete my_list_copy.head;
}

/* Expected output

My list:  empty!!
My list:  10->15->20->20->30->
My list is sorted increasingly

Test frequency...

frequency(20): 2
frequency(30): 1

Test insert_last...

Another list:  30->20->20->15->10->
Another list is not sorted increasingly

Test copy...

Copy of my list:  10->15->20->20->30->
Copy of my list is sorted increasingly

Free all memory used by the lists ...
My list:  empty!!
Another list:  empty!!
Copy of my list:  empty!!

*/