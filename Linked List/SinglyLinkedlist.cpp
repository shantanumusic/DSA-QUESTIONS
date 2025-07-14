#include<iostream>
using namespace std;

class Node {
    public:
    int data; // Data part of the node
    Node* next;

    Node(int data) { 
        this -> data = data; // Initializing data
        this -> next = NULL; // Initializing next pointer to NULL
    }
};

void InsertAtHead(Node* &head, int data) {
    Node* newNode = new Node(data); // Creating a new node
    newNode -> next = head; // Pointing new node's next to current head
    head = newNode; // Updating head to point to the new node
}

void printList(Node* head) {
    Node* temp = head; // Temporary pointer to traverse the list
    while (temp != NULL) {
        cout << temp -> data << " -> "; // Printing current node's data
        temp = temp -> next; // Moving to the next node
    }
    cout << "NULL" << endl; // Indicating end of the list
}

int main(){

    Node* node1 = new Node(10); // Dynamically allocating memory for node1
    cout << node1 -> data << endl; // Accessing uninitialized data, may print garbage value
    cout << node1 -> next << endl; // Accessing uninitialized next pointer, may print garbage value

    Node* head = node1;
    printList(head); // Printing the list with a single node

    InsertAtHead(head , 12); // Inserting a new node at the head with data 12
    printList(head); // Printing the list after inserting a new node at head
    InsertAtHead(head , 62); // Inserting a new node at the head with data 12
    printList(head); // Printing the list after inserting a new node at head
    InsertAtHead(head , 72); // Inserting a new node at the head with data 12
    printList(head); // Printing the list after inserting a new node at head
    InsertAtHead(head , 662); // Inserting a new node at the head with data 12
    printList(head); // Printing the list after inserting a new node at head
}