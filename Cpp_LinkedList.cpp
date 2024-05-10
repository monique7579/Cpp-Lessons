#include <iostream>


using namespace std;


// Node struct definition
struct Node {
    int data;
    Node* next;
};


// Global head pointer
Node* head = nullptr;


// Function to find a node with given data
Node* find(int value) {
    Node* current = head;
    while (current != nullptr) {
        if (current->data == value) {
            return current;
        }
        current = current->next;
    }
    return nullptr; // Return nullptr if not found
}


// Function to insert a new node at the beginning of the list
void insert(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}


// Function to clear the entire linked list
void clear() {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}


int main() {
    // Test the linked list functions
    insert(5);
    insert(10);
    insert(15);


    // Find function test
    Node* foundNode = find(10);
    if (foundNode != nullptr) {
        cout << "Node found with data: " << foundNode->data << endl;
    }
    else {
        cout << "Node not found." << endl;
    }


    // Clear function test
    clear();
    cout << "Linked list cleared." << endl;


    return 0;
}

