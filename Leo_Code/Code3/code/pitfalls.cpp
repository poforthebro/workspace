/***************************************************** *
 * TNG033: lecture 3                                   *
 * To illustrate common mistakes when working pointers *
 * ************************************************** */

#include <iostream>

void Ohoops1() {
    int* ptr1 = new int{12};
    *ptr1 *= 2;  // double the value stored in the variable pointed by ptr

    std::cout << "*ptr1 = " << *ptr1 << "\n";

    // Dealocate the memory for the variable pointed by pointer ptr1
    delete ptr1;

    // Ohoops 1! Dereferencing a pointer that points to free memory is a bug!!!
    std::cout << "*ptr1 = " << *ptr1 << "\n";
    // ASan can be used to detect this problem
}

void Ohoops2() {
    int n = 5;
    int* ptr2 = &n;

    // Ohoops 2! Trying to free memory of a variable placed on the stack is a bug!!!
    delete ptr2;
    // ASan can be used to detect this problem
}

void memory_leaks(int k) {
    // Ohoops 3! k memory leaks!!!
    for (int i = 0; i < k; ++i) {
        int* ptr = new int{i};
        std::cout << "*ptr = " << *ptr << "\n";
    }
    /*
     * Memory leaks are usualy very silent bugs
     * ASan on windows machines cannot help you to detect memory leaks, sadly
     */
}

int main() {
    // Ohoops1();
    // Ohoops2();

    memory_leaks(10);
}