#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* next;

    node(int val) {
        data = val;
        next = nullptr;
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
            tail->next = head; // CIRCULAR LINK: Points to itself
        } else {
            newnode->next = head;
            head = newnode;
            tail->next = head; // CRITICAL: Tail must now point to the NEW head
        }
    }

    // Push Back (Insert at tail)
    void pushback(int val) {
        node* newnode = new node(val);

        if (head == nullptr) {
            head = tail = newnode;
            tail->next = head; // Points to itself
        } else {
            tail->next = newnode; // Old tail points to new node
            tail = newnode;       // Update tail pointer
            tail->next = head;    // CRITICAL: New tail must point back to head
        }
    }

    // Pop Front (Delete head)
    void popfront() {
        if (head == nullptr) return;

        // Special Case: Only 1 node
        if (head == tail) {
            delete head;
            head = tail = nullptr;
            return;
        }

        node* temp = head;
        head = head->next;     // Move head forward
        tail->next = head;     // CRITICAL: Update tail to point to NEW head
        delete temp;
    }

    // Pop Back (Delete tail)
    void popback() {
        if (head == nullptr) return;

        if (head == tail) {
            delete head;
            head = tail = nullptr;
            return;
        }

        node* current = head;
        // Loop looks different! We stop when we reach tail.
        while (current->next != tail) {
            current = current->next;
        }

        node* temp = tail;
        tail = current;       // Move tail back one step
        tail->next = head;    // CRITICAL: New tail points to head (Circle closed)
        delete temp;
    }

    // Print is VERY different (to avoid infinite loops)
    void print() {
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }

        node* temp = head;
        
        // We use a DO-WHILE loop to ensure it runs at least once
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head); // Stop when we circle back to the start

        cout << "(HEAD)" << endl; // Shows it loops back
    }
};

int main() {
    list l1;

    l1.pushfront(10);
    l1.pushfront(20);
    l1.pushback(30);  // List: 20 -> 10 -> 30 -> (back to 20)

    l1.print();

    l1.popfront();    // Removes 20. Tail (30) must now point to 10.
    l1.print();

    return 0;
}
