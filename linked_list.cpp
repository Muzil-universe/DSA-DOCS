#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* next;

    // Constructor to initialize the node
    node(int val) {
        data = val;
        next = nullptr;
    }
};

class list {
public:
    node* head;
    node* tail;

    // Constructor to initialize empty list
    list() {
        head = tail = nullptr;
    }

    // Push a new node at the front of the list
    void pushfront(int val) {
        node* temp = new node(val);
        if (head == nullptr) {
            head = tail = temp;  // First element in the list
        } else {
            temp->next = head;
            head = temp;  // Update head to new node
        }
    }

    // Push a new node at the back of the list
    void pushback(int val) {
        node* temp = new node(val);
        if (head == nullptr) {
            head = tail = temp;  // First element in the list
        } else {
            tail->next = temp;
            tail = temp;  // Move the tail to the new last node
        }
    }

    // Pop the first node from the list
    void popfront() {
        if (head == nullptr) return;  // Empty list, nothing to pop

        node* temp = head;
        head = head->next;
        delete temp;

        if (head == nullptr) {
            tail = nullptr;  // List is now empty
        }
    }

    // Pop the last node from the list
    void popback() {
        if (head == nullptr) return;  // Empty list, nothing to pop

        if (head == tail) {  // Only one node in the list
            delete head;
            head = tail = nullptr;
            return;
        }

        node* current = head;
        while (current->next != tail) {
            current = current->next;
        }

        delete tail;
        tail = current;
        tail->next = nullptr;  // Tail now points to nullptr
    }

    // Insert a new node at a specific position
 void insert_in_btw(int val, int pos) {

    node* newnode = new node(val);
    node* temp = head;

    // move to (pos-1)
    for (int i = 1; i < pos - 1 && temp != nullptr; i++)
        temp = temp->next;

    if (temp == nullptr || temp->next == nullptr) {
        cout << "Position is not in-between" << endl;
        delete newnode;
        return;
    }

    // insert strictly in between
    newnode->next = temp->next;
    temp->next = newnode;
}



    // Print all nodes in the list
    void print() {
        node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    list l1;

    l1.pushfront(5);  // List: 5
    l1.pushfront(7);  // List: 7 5
    l1.pushfront(9);  // List: 9 7 5
    l1.pushfront(3);  // List: 3 9 7 5
    l1.pushback(2);   // List: 3 9 7 5 2
    l1.pushback(5);   // List: 3 9 7 5 2 5

    l1.popfront();    // List: 9 7 5 2 5
    l1.popback();     // List: 9 7 5 2

    l1.pushfront(5);  // List: 5 9 7 5 2
    l1.pushfront(7);  // List: 7 5 9 7 5 2
    l1.pushfront(9);  // List: 9 7 5 9 7 5 2
    l1.pushfront(3);  // List: 3 9 7 5 9 7 5 2
    l1.pushback(2);   // List: 3 9 7 5 9 7 5 2 2
    l1.pushback(5);   // List: 3 9 7 5 9 7 5 2 2 5

    l1.insert_in_btw(23, 3);  // Insert 23 at position 3
    l1.print();  // Expected List: 3 9 23 7 5 9 7 5 2 2 5

    return 0;
}
