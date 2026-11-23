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


// !!!! Update to use Node inser function

// Constructor for creating a singleton {x}
Set::Set(int x) : Set() {
    // ADD CODE
    insert(head, x); // Use the insert function to insert the new value directly after the dummy node
}

/*
 * Constructor: create a set with elements
 * vector elements is not sorted and values in it may not be unique
 */

Set::Set(const std::vector<int>& elements) : Set() {
    /*
        Use the constructor for the nodes
     * Sorting a vector cannot used here
     * std::sort and std::unique cannot be used
     */
    // ADD CODE

    // For every element in vector elements
    for (const int& element : elements ) {
        Node* nextNode = head->next; // Points to the next node, from where we are trying to place newNode
        Node* previousNode = head; // Points to the node before next node
        
        // Now we need to loop through the new set and find the position where the next one is bigger
        // This run as long as the node after the next node is not nullptr. We add the new node when the next node is bigger than it
        while (nextNode != nullptr) {
            
            // if the value in elements i f smaller than the next value we add it before the node in the set
            if (nextNode->value > element) {
                insert(previousNode, element);
                break;
            } 
            
            // If they are equal we can just disregard this element since it already exists in the set. We break to move to the next step in the for loop
            else if (nextNode->value == element) {
                // In this case we are not adding a new node and therefore not increasing the counter
                break;
            }

            previousNode = nextNode;
            nextNode = nextNode->next;  
        }
       
        // If we reach the end of the list we add the new value at the end
        if (nextNode == nullptr) {
            insert(previousNode, element);      
        } 

    }
}

// copy constructor
Set::Set(const Set& rhs) : Set() {
    // ADD CODE
    Node* ptr1 = rhs.head->next; // rhs starts after the dummy node
    Node* ptr2 = head; // *this starts at the head

    // Loop through the rhs
    while(ptr1 != nullptr) {
        ptr2->next = new Node(ptr1->value); // update *this to points to a new node that we create with the rhs value
        ptr1 = ptr1->next; // Step rhs forwards
        ptr2 = ptr2->next; // Step *this fowrard
    }

    counter = rhs.counter; // Update the counter
}

// Assignment operator: use copy-and-swap idiom
Set& Set::operator=(Set rhs) { // rhs is copied by value, it is a new set
    // ADD CODE
    std::swap(head, rhs.head); // We set lhs head to point to the new sets head
    std::swap(counter, rhs.counter); // We set the counter correct

    return *this; // Automatically deletes rhs since it is not in scope anymore. Its destructor runs
}

// Destructor: deallocate all nodes
Set::~Set() {
    // ADD CODE
    Node* ptr = head; // We start at the head since the dummy node should also be deleted

    while (ptr != nullptr) { // Loop through the entire list
        Node* next_ptr = ptr->next; // Save the pointer to the next Node

        delete ptr; // Delete the current node
        ptr = next_ptr; // current node is the next node 
    }

    head = nullptr; // Make sure the head points to null and not the deleted node
    counter = 0;
}

// Return number of elements in the set
std::size_t Set::cardinality() const {
    // ADD CODE
    return counter;  // We return the counter that should be holding the number of elements
}

// Test if set is empty
bool Set::empty() const {
    // ADD CODE
    // If and only if the dummy node points to nullptr the set is empty
    if (head->next == nullptr) {
        return true;
    }

    return false;  // return false if the set isnt empty
}

// Test if x is an element of the set
bool Set::member(int x) const {
    // ADD CODE
    const Node* ptr = head->next; // We start at the dummy node
    
    // Check every element until we reach the end of the set
    while(ptr != nullptr) {
        if(ptr->value == x) {
            return true;
        }
        ptr = ptr->next;
    }
    return false;  // return false at the end if we havent found the element
}

/*
 * Return true, if *this is a subset of Set b
 * Otherwise, false is returned
 */
bool Set::is_subset(const Set& b) const {
    // ADD CODE
    Node* ptr = head->next;
    Node* ptr_b = b.head->next;

    // For every value in *this we check untill we reach the end of *this list
    while(ptr != nullptr) {
            
        // Check against every value in b as long as they are not the same value
        while(ptr_b != nullptr && ptr->value != ptr_b->value) {
                
            // If this is smaller than b we know that we have passed the point where they might be the same. We can return false
            if(ptr->value <= ptr_b->value) {
                    return false;
                }

                ptr_b = ptr_b->next;
        }

        // If ptr_b = nullptr we have reached the end of the list without finding the expected value
        if(ptr_b == nullptr) {
            return false;
        }

        // Move forwards in set *this
        ptr = ptr->next;
    }
    // If all tests above were passed we can return true since the statement must be true
    return true;  // delete, if needed
}


/*
 * Return a new Set representing the union of Sets *this and b
 * Repeated values are not allowed
 * Must implement the algorithm given in Lab1's appendix
 */
Set Set::set_union(const Set& b) const {
    // ADD CODE
    Node* ptr1 = head->next;
    Node* ptr2 = b.head->next;
    Set newSet{}; // create the new set
    Node* ptrNew = newSet.head;

    /*
        Loop through both sets until we find the end of one of them, compare the values between them and insert the one that is smaller. 
        Step forwards in the set with the smaller value
        If the value are equal in the two sets, insert the value and step both sets forward
    */ 

    while(ptr1 != nullptr && ptr2 != nullptr) {

        // If both are equal we insert one value an move forward in both sets
        if(ptr1->value == ptr2->value) {
            newSet.insert(ptrNew, ptr1->value);
            ptrNew = ptrNew->next;
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }

        // We only insert the smaller value and then move forward in the list that had the smaller value
        else if(ptr1->value < ptr2->value){
            newSet.insert(ptrNew, ptr1->value);
            ptrNew = ptrNew->next;
            ptr1 = ptr1->next;
        }
        
        // This runs if ptr2->value is smaller than ptr1->value. We insert the smaller value and then move forward in the list that had the smaller value
        else {
            newSet.insert(ptrNew, ptr2->value);
            ptrNew = ptrNew->next;
            ptr2 = ptr2->next;
        }
    }

    // If set1 is still not nullptr lopp trough it to insert the last values
    while(ptr1 != nullptr) {
        newSet.insert(ptrNew, ptr1->value);
        ptrNew = ptrNew->next;
        ptr1 = ptr1->next;
    }

    // If set2 is still not nullptr lopp trough it to insert the last values
    while(ptr2 != nullptr) {
        newSet.insert(ptrNew, ptr2->value);
        ptrNew = ptrNew->next;
        ptr2 = ptr2->next;
    }

    return newSet;
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

void Set::insert(Node* p, int value) {
    Node* newNode = new Node(value); // we create the new node with the value 
    newNode->next = p->next;
    p->next = newNode;

    ++counter;
}
