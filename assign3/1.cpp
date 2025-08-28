#include <iostream>
using namespace std;

#define MAX 100

int stack[MAX];
int top = -1;

void push() {
    if (top >= MAX - 1) {
        cout << "Stack Overflow!" << endl;
        return;
    }
    int value;
    cout << "Enter value to push: ";
    cin >> value;
    stack[++top] = value;
    cout << "Pushed " << value << " onto stack." << endl;
}

void pop() {
    if (top < 0) {
        cout << "Stack Underflow!" << endl;
        return;
    }
    cout << "Popped " << stack[top] << " from stack." << endl;
    top--;
}

void isEmpty() {
    if (top == -1)
        cout << "Stack is empty." << endl;
    else
        cout << "Stack is not empty." << endl;
}

void isFull() {
    if (top == MAX - 1)
        cout << "Stack is full." << endl;
    else
        cout << "Stack is not full." << endl;
}

void display() {
    if (top == -1) {
        cout << "Stack is empty." << endl;
        return;
    }
    cout << "Stack elements: ";
    for (int i = top; i >= 0; i--) {
        cout << stack[i] << " ";
    }
    cout << endl;
}

void peek() {
    if (top == -1) {
        cout << "Stack is empty." << endl;
        return;
    }
    cout << "Top element: " << stack[top] << endl;
}

int main() {
    int choice;
    while (true) {
        cout << "\n--- STACK MENU ---" << endl;
        cout << "1. PUSH" << endl;
        cout << "2. POP" << endl;
        cout << "3. ISEMPTY" << endl;
        cout << "4. ISFULL" << endl;
        cout << "5. DISPLAY" << endl;
        cout << "6. PEEK" << endl;
        cout << "7. EXIT" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: isEmpty(); break;
            case 4: isFull(); break;
            case 5: display(); break;
            case 6: peek(); break;
            case 7: cout << "Exiting..." << endl; return 0;
            default: cout << "Invalid choice!" << endl;
        }
    }
}
