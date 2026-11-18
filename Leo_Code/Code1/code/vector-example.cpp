/*********************************************************************
 * TNG033: lecture 1                                                 *
 * Example to illustrate the use of vectors    -- TND012             *
 * *******************************************************************/

// Input: 1 3 5 7 stop

#include <iostream>
#include <vector>

// Read a list of values and return a vector with the values read
std::vector<int> read_input_list() {
    std::vector<int> V;

    int value;
    while (std::cin >> value) {  // input ended with a non-int, e.g. "stop"
        V.push_back(value);
    }
    return V;
}

int main() {
    std::vector<int> list;  // empty vector

    std::cout << "List size: " << std::ssize(list) << "\n";

    std::cout << "\nEnter a list of integers: ";
    list = read_input_list();

    // Display the list of values read
    std::cout << "\nList size: " << std::ssize(list);

    std::cout << "\nList of values (by the entered order): ";
    for (int v : list) {  // range-based loop
        std::cout << v << " ";
    }

    /*
    // same as the range-based loop above
    for (int i = 0; i < std::ssize(list); ++i) {
        std::cout << list[i] << " ";
    }
    */

    // Display in reverse order: move in the vector from the last element to the first (backwards)
    std::cout << "\nList of values (by reverse order): ";
    for (auto i = std::ssize(list) - 1; i > -1; --i) { // auto automatically chooses the correct type based on std::ssize
        std::cout << list[i] << " \n ";

    }

    // Remove last value in the vector
    std::cout << "\n\nRemoving last item from the vector ...";
    list.pop_back();

    // Display again the list of values read
    std::cout << "\nList size: " << std::ssize(list);

    std::cout << "\nList of values: ";
    for (int v : list) {  // range-based loop
        std::cout << v << " ";
    }
    std::cout << "\n";
}
