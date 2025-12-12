#include <iostream>
using namespace std;

#define MAX 100 // Maximum size of the stack

class ArrayStack {
    int top;
    int arr[MAX];

public:
    ArrayStack() { top = -1; } // Constructor to initialize top

    // 1. PUSH Operation
    bool push(int x) {
        if (top >= (MAX - 1)) {
            cout << "Stack Overflow (Full)" << endl;
            return false;
        }
        arr[++top] = x; // Increment top, then insert
        cout << x << " pushed into stack\n";
        return true;
    }

    // 2. POP Operation
    int pop() {
        if (top < 0) {
            cout << "Stack Underflow (Empty)" << endl;
            return 0;
        }
        return arr[top--]; // Return value, then decrement top
    }

    // 3. PEEK Operation
    int peek() {
        if (top < 0) {
            cout << "Stack is Empty" << endl;
            return 0;
        }
        return arr[top]; // Just return the value at top
    }
};

int main() {
    ArrayStack s;
    s.push(10);
    s.push(20);
    cout << s.pop() << " popped from stack\n"; // Returns 20
    cout << "Top element is " << s.peek() << endl; // Returns 10
    return 0;
}
