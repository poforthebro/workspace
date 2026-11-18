/***********************************************
 * TNG033: Practice session 2                  *
 * Exercise 2a                                 *
 * *********************************************/

/*
* Is there any problem with this code?
* If so, describe the problem?
* 
* 
* 
* 
*/

#include <iostream>
#include <string>

std::string* read_name() {
    std::string* p = new std::string;

    std::cout << "Enter a person's name: ";
    std::cin >> std::ws;
    std::getline(std::cin, *p);

    return p;
}

int main() {
    std::string* ptr = read_name(); // We create a pointer that points to a name(string)
    std::cout << *ptr << "\n"; // Print the string in ptr

    // Read another name
    ptr = read_name(); // We redefine ptr and now loose access to the original name without deleting in the heap
    std::cout << *ptr << "\n";

    delete ptr; // We correctly free the second memory in heap, but not the first one
}
