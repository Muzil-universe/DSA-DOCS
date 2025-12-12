#include <iostream>
using namespace std;

// 1. Node Class (Same as your code, but 'prev' is not needed for Stack)
class node {
public:
    int data;
    node* next;

    node(int val) {
        data = val;
        next = nullptr;
    }
};

// 2. Stack Class
class Stack {
public:
    node* head; // 'head' acts as the TOP of the stack

    Stack() {
        head = nullptr;
    }

    // PUSH Operation (Same logic as 'pushfront')
    void push(int val) {
        node* newnode = new node(val);
        
        // 1. New node points to current head
        newnode->next = head; 
        
        // 2. Head updates to new node
        head = newnode;       
        
        cout << val << " pushed to stack." << endl;
    }

    // POP Operation (Same logic as 'popfront')
    void pop() {
        if (head == nullptr) {
            cout << "Stack Underflow (Empty)" << endl;
            return;
        }

        node* temp = head; // Store current top to delete later
        
        // 1. Move head to the next node
        head = head->next; 
        
        // 2. Delete the old top
        delete temp;       
        cout << "Popped top element." << endl;
    }

    // PEEK Operation (View the head data)
    int peek() {
        if (head == nullptr) {
            cout << "Stack is Empty" << endl;
            return -1;
        }
        return head->data;
    }

    // Helper to check if empty
    bool isEmpty() {
        return head == nullptr;
    }
};

int main() {
    Stack s;

    // LIFO Behavior: Last In, First Out
    s.push(10);
    s.push(20);
    s.push(30); // 30 is now at the 'head' (Top)

    cout << "Top element is: " << s.peek() << endl; // Should be 30

    s.pop(); // Removes 30
    cout << "Top element after pop is: " << s.peek() << endl; // Should be 20

    return 0;
}
