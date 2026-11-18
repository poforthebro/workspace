/***************************************************************************
 * TNG033: lecture 2                                                        *
 * Pointers and references                                                  *
 * Read the code and understand the output                                  *
 * **************************************************************************/

#include <iostream>

int main() {
    int n = 10;
    int& ref1 = n;
    /*
     * ref1 is a reference variable
     * ref1 refers to variable n
     * wherever in the code one sees 'ref1' is as if it is variable n
     * so, ref1 is just another name for variable n, i.e. ref1 is an alias for n
     */

    std::cout << "ref1 refers to var. n = 10\n";
    std::cout << "ref1 : " << ref1 << '\n';
    std::cout << "n : " << n << '\n';
    std::cout << "&n : " << &n << '\n';
    std::cout << "&ref1 : " << &ref1 << '\n';

    int k = 666;
    int* ptr = &k;     // ptr points to variable k
    int*& ref2 = ptr;  // ref2 is a reference to pointer ptr
    /*
     * ref2 is a reference variable
     * ref2 refers to variable ptr (a pointer)
     * wherever in the code one sees 'ref2' is as if it is variable ptr
     * so, ref2 is just another name for variable ptr, i.e. ref2 is an alias for ptr
     */

    std::cout << "\nref2 refers to pointer ptr\n";
    std::cout << "*ptr: " << *ptr << '\n';
    std::cout << "*ref2 : " << *ref2 << '\n';
    std::cout << "ref2 : " << ref2 << '\n';
    std::cout << "ptr : " << ptr << '\n';
}
