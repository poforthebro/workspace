#include<iostream>


struct Node {
    int value = 0;
    Node* next = nullptr;

};


using List = Node*; // We alias it as List

void insert_first(List& l, int n) {
    Node* ptr = new Node;

    ptr->value = n;
    ptr->next = l;

    l = ptr;
}

using Word = std::string;
using Line = std::vector<Word>;
using Text = std::vector<Line>;


int main() {
    
    // Part 0
    if(false) {
        std::cout << "Hej världen på föreläsning 2 \n";

        int n = 10;
        int* ptr = &n;

        std::cout << "n = " << n;

        std::cout << "\naddress of n = " << &n;
        std::cout << "\nptr = " << ptr;

        std::cout << "\nAddress of pointer = " << &ptr;
        std::cout << "\n";

    }




    // Part 1
    if(false) {
        double* pd = new double(45.5);

        std::cout << "\npd = " << pd;
        std::cout << "\n *pd = " << *pd;
        std::cout << "\n";

        delete pd; // Deletes memory
    }





    // Part 2, Lists and nodes
        if(false) {
            List L = nullptr;
            // Equal to Node* L = nullptr;



    }



    // Part 3, myEssay
        if(false) {
           // std::vector<std::vector<std::string>> myEssay;
            Text myEssay;


    }



    // Part 4
        if(true) {
            List L = nullptr; // Create an empty list
            insert_first(L, 50);
            insert_first(L, 33);
            insert_first(L, 42);
            insert_first(L, 12);
            
            std::cout << L[0].value << "\n";

    }


}