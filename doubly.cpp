#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* next;
    node* prev; // NEW: Pointer to the previous node

    node(int val) {
        data = val;
        next = nullptr;
        prev = nullptr; // Initialize prev to null
    }
};

class list {
public:
    node* head;
    node* tail;

    list() {
        head = tail = nullptr;
    }

    // Push Front (Insert at head)
    void pushfront(int val) {
        node* newnode = new node(val);
        
        if (head == nullptr) {
            head = tail = newnode;
        } else {
            newnode->next = head; // 1. New node points to old head
            head->prev = newnode; // 2. Old head points back to new node
            head = newnode;       // 3. Update head pointer
        }
    }

    // Push Back (Insert at tail)
    void pushback(int val) {
        node* newnode = new node(val);
        
        if (head == nullptr) {
            head = tail = newnode;
        } else {
            tail->next = newnode; // 1. Old tail points to new node
            newnode->prev = tail; // 2. New node points back to old tail
            tail = newnode;       // 3. Update tail pointer
        }
    }

    // Pop Front (Delete head)
    void popfront() {
        if (head == nullptr) return;

        node* temp = head;
        head = head->next; // Move head forward

        if (head != nullptr) {
            head->prev = nullptr; // New head should not point back to deleted node
        } else {
            tail = nullptr; // If list became empty
        }
        
        delete temp;
    }

    // Pop Back (Delete tail) - NOW MUCH FASTER O(1)!
    void popback() {
        if (head == nullptr) return;

        node* temp = tail;

        if (head == tail) { // Only one node
            delete head;
            head = tail = nullptr;
            return;
        }

        // NO LOOP NEEDED! We can just step back.
        tail = tail->prev;    // 1. Move tail backward
        tail->next = nullptr; // 2. Remove link to the old tail
        
        delete temp;          // 3. Delete the old tail
    }

    // Insert Strictly In-Between
    void insert_in_btw(int val, int pos) {
        node* newnode = new node(val);
        node* temp = head;

        // Move to (pos-1)
        for (int i = 1; i < pos - 1 && temp != nullptr; i++) {
            temp = temp->next;
        }

        // Logic from your previous code: STRICTLY in-between
        // Cannot be null, and cannot be the last node (must have a 'next')
        if (temp == nullptr || temp->next == nullptr) {
            cout << "Position is not in-between (or invalid)" << endl;
            delete newnode;
            return;
        }

        // WIRING THE 4 LINKS
        node* nextNode = temp->next; // The node currently after temp

        // 1. Link newnode forward and backward
        newnode->next = nextNode;
        newnode->prev = temp;

        // 2. Link surrounding nodes to newnode
        temp->next = newnode;
        nextNode->prev = newnode;
    }

    // Print Forward
    void print() {
        node* temp = head;
        cout << "Forward: ";
        while (temp != nullptr) {
            cout << temp->data << " <-> "; // Visualizing double links
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    // NEW: Print Backward (To verify prev pointers)
    void printReverse() {
        node* temp = tail; // Start from tail
        cout << "Reverse: ";
        while (temp != nullptr) {
            cout << temp->data << " <-> ";
            temp = temp->prev; // Move backwards!
        }
        cout << "NULL" << endl;
    }
};

int main() {
    list l1;

    // Building list
    l1.pushfront(5);
    l1.pushfront(7);
    l1.pushfront(9); 
    l1.pushback(2);  
    
    // Testing Pop
    l1.popfront();
    l1.popback();

    // Adding more to test insert
    l1.pushfront(10);
    l1.pushback(20);
    l1.pushback(30);

    cout << "Before Insert:" << endl;
    l1.print();

    // Insert 99 at position 3
    l1.insert_in_btw(99, 3);

    cout << "After Insert:" << endl;
    l1.print();
    l1.printReverse(); // Check if backward links are broken!

    return 0;
}
