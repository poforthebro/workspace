#include "set.hpp"

/*
 * std::size_t is defined in the C++ standard library
 * std::size_t is an unsigned integer type that can store the maximum size of any possible object
 * sizes are non-negative integers -- i.e. unsigned integer type
 */

/* *********** class Node ************ */

/*
 * This class is private to class Set
 *  but all class Node members are public to class Set
 */
class Set::Node {
public:
    // Constructor
    Node(int nodeVal = 0, Node* nextPtr = nullptr) : value{nodeVal}, next{nextPtr} {
        ++count_nodes;
    }

    // Destructor
    ~Node() {
        --count_nodes;
        assert(count_nodes >= 0);  // number of existing nodes can never be negative
    }
	
	Node(const Node&) = delete;
	Node& operator=(const Node&) = delete; 
	
    int value;
    Node* next;

    /*
     * Total number of existing nodes -- used only to help to detect bugs in the code
     * Cannot be used in the implementation of the member functions
     */
    static std::size_t count_nodes;

    friend std::ostream& operator<<(std::ostream& os, const Set& rhs);
};

/* ************************************ */

// Initialize the counter of the total number of existing nodes
std::size_t Set::Node::count_nodes = 0;

/*
 * Return number of existing nodes
 * Used only for debug purposes
 */
std::size_t Set::get_count_nodes() { return Set::Node::count_nodes; }

/* *********** class Set member functions ************ */

// Default constructor
Set::Set() : head{new Node{}}, counter{0} {  // create the dummy node
}

// Constructor for creating a singleton {x}
Set::Set(int x) : Set() {
    // ADD CODE
    Node* newNode = new Node;
    newNode->value = x;
    newNode->next = head->next;

    head->next = newNode;
    ++counter;
}

/*
 * Constructor: create a set with elements
 * vector elements is not sorted and values in it may not be unique
 */



// This function seems to work correctly now, needs some cleanup

Set::Set(const std::vector<int>& elements) : Set() {
    /*
        Use the constructor for the nodes
     * Sorting a vector cannot used here
     * std::sort and std::unique cannot be used
     */
    // ADD CODE
    int length = std::ssize(elements); 

    // For every element in vector elements
    for (int i = 0; i < length; ++i) {
        Node* nextNode = head->next; // Points to the next node, from where we are trying to place newNode
        Node* previousNode = head; // Points to the node before next node
        
        // Now we need to loop through the new set and find the position where the next one is bigger
        
        
        // This run as long as the ndoe after the next node is not nullptr. We add the new node when the next node is bigger than it
        while (nextNode != nullptr) {
            
            if (nextNode->value > elements[i]) {
                
                insert(previousNode, elements[i]);
             
                break;
            } 
            
            else if (nextNode->value == elements[i]) {

                // In this case we are not adding a new node and therefore not increasing the counter
                break;
            }

            previousNode = nextNode;
            nextNode = nextNode->next;
            
        }
       
        
        // If we reach the end of the list we add the new value at the end
        if (nextNode == nullptr && elements[i] != previousNode->value) {
            insert(previousNode, elements[i]);
            
        } 

    }

}

// copy constructor
Set::Set(const Set& rhs) : Set() {
    // ADD CODE
    Node* ptr1 = rhs.head->next;
    Node* ptr2 = head;

    while(ptr1 != nullptr) {
        ptr2->next = new Node(ptr1->value);

        ptr1 = ptr1->next;
        ptr2 = ptr2->next;

    }
    counter = rhs.counter;


}

// Assignment operator: use copy-and-swap idiom
Set& Set::operator=(Set rhs) {
    // ADD CODE
    std::swap(head, rhs.head);
    std::swap(counter, rhs.counter);

    return *this;
}

// Destructor: deallocate all nodes
Set::~Set() {
    // ADD CODE
    Node* ptr = head; // We start at the head since the dummy node should also be deleted

    while (ptr != nullptr) { // Loop until we find the end
        Node* next_ptr = ptr->next; // Save the pointer to the next Node
        delete ptr; // Delete the current node
        ptr = next_ptr; // current node is the next node
        }

    delete ptr;  // Delete the last node
}

// Return number of elements in the set
std::size_t Set::cardinality() const {
    // ADD CODE

    return counter;  // We return the counter that should be holding the number of elements
}

// Test if set is empty
bool Set::empty() const {
    // ADD CODE
    if (head->next == nullptr) {
        return true;
    }

    return false;  // delete, if needed
}

// Test if x is an element of the set
bool Set::member(int x) const {
    // ADD CODE
    
    const Node* ptr = head->next;
    while(ptr != nullptr) {
            if(ptr->value == x) {
                return true;
            }

        ptr = ptr->next;
    }

    return false;  // delete, if needed
}

/*
 * Return true, if *this is a subset of Set b
 * Otherwise, false is returned
 */
bool Set::is_subset(const Set& b) const {
    // ADD CODE
    return false;  // delete, if needed
}


/*
 * Return a new Set representing the union of Sets *this and b
 * Repeated values are not allowed
 * Must implement the algorithm given in Lab1's appendix
 */
Set Set::set_union(const Set& b) const {
    // ADD CODE
    return Set{};  // delete, if needed
}

// Return a new Set representing the intersection of Sets *this and b
Set Set::set_intersection(const Set& b) const {
    // ADD CODE
    return Set{};  // delete, if needed
}

// Return a new Set representing the difference between Set *this and Set b
Set Set::set_difference(const Set& b) const {
    // ADD CODE
    return Set{};  // delete, if needed
}

std::ostream& operator<<(std::ostream& os, const Set& rhs) {
    if (rhs.empty()) {
        os << "Set is empty!";
    } else {
        Set::Node* ptr = rhs.head->next;
        os << "{ ";

        while (ptr != nullptr) {
            os << ptr->value << " ";
            ptr = ptr->next;
        }
        os << "}";
    }
    return os;
}

/********** Private member functions ************/

    void Set::insert(Node* &p, int value) {
        Node* newNode = new Node(value); // we create the new node with the value 
        newNode->next = p->next;
        p->next = newNode;

        ++counter;
    }