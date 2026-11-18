/**********************************************************************************
 * TNG033: lecture 1                                                               *
 * To illustrate pointers                                                          *
 * Read the program and then understand its output                                 *
 * *********************************************************************************/

#include <iostream>
#include <vector>

void foo(int* p) {
    if (p != nullptr) {
        *p = 12;
    }
}

int main() {
    int* p = nullptr;
    int k = 15;

    if (!p) {  // (p == nullptr)
        std::cout << "Pointer p is not pointing to a variable!!\n\n";
    }

    p = &k;  // pointer p points to variable k

    std::cout << "p stores address " << p << '\n';
    std::cout << "Variable k address (&k) is " << &k << "\n\n";

    std::cout << "Variable pointed by p (*p) stores " << *p << '\n';
    std::cout << "k = " << k << "\n\n";

    std::cout << "Address of pointer p is " << &p << "\n\n";

    *p *= 2;  // same as k *= 2;
    std::cout << "*p *= 2;   variable pointed by p (*p) stores " << *p << "\n";
    std::cout << "k = " << k << "\n\n";

    std::cout << "sizeof(p)= " << sizeof(p)
              << "\n\n";  // how many bytes a pointer occupies in memory

    /* ********************* */

    int i = 0;

    std::cout << "\nBefore calling foo(i): i = " << i;
    foo(&i);  // foo modifies i
    std::cout << "\nAfter calling foo(i): i = " << i << "\n\n";

    std::cout << "sizeof(i) = " << sizeof(i) << "\n\n";  // how many bytes int occupies

    /* ********************* */

    std::vector<int> V(10, -1);  // create a vector with 10 elements initialized with -1

    std::cout << "sizeof(V[0]) = " << sizeof(V[0]) << '\n';    // how many bytes V[0] occupies
    std::cout << "sizeof(&V[0]) = " << sizeof(&V[0]) << "\n";  // number of bytes of address of V[0]
}
