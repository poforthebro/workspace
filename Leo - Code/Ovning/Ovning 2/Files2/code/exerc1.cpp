/********************************
 * TNG033: Practice session 2   *
 * Exercise 1                   *
 * ******************************/

#include <iostream>

// Define my_swap
void my_swap(int*& p1, int*& p2);

int main() {
    int* p1 = new int(10);
    int* p2 = new int(-10);

    std::cout << "Before my swap: *p1 = " << *p1 << "  *p2 = " << *p2 << "\n";

    my_swap(p1, p2);

    std::cout << "After my swap: *p1 = " << *p1 << "  *p2 = " << *p2 << "\n";

    // free the dynamically allocated memory
    delete p1;
    delete p2;
}

/* Expected output

Before my swap: *p1 = 10  *p2 = -10
After my swap:  *p1 = -10  *p2 = 10

*/


void my_swap(int* &p1, int* &p2) {

    // We should swap the values they are pointing to
    int* ptr = p1;
    p1 = p2;
    p2 = ptr;

}