#include <iostream>
using namespace std;

struct Stack {
    int data[100];
    int top;
    int size;

    Stack() {
        top = -1;
        size = 0;
    }

    bool isEmpty() {
        return (top == -1);
    }

    bool isFull() {
        return (top == size - 1);
    }

    void push(int item) {
        if (isFull()) {
            cout << "Stack Overflow! Cannot push element!!" << item << endl;
        } else {
            data[++top] = item;
            cout << item << " pushed onto the stack!" << endl;
        }
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow! Stack is empty!" << endl;
        } else {
            cout << data[top] << " popped from the stack!" << endl;
            top--;
        }
    }

    int peek() {
        if (isEmpty()) {
            cout << "The Stack is empty!" << endl;
            return -1;
        }
        return data[top];
    }

    void change(int position, int newValue) {
        if (position < 1 || position > size) {
            cout << "Invalid position! Cannot change the value!" << endl;
        } else {
            data[position - 1] = newValue;
            cout << "Value at position " << position << " changed to " << newValue << "!" << endl;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "The Stack is empty!" << endl;
        } else {
            cout << "Stack elements:\n";
            for (int i = top; i >= 0; i--) {
                cout << "  " << data[i];
                if (i == top) {
                    cout << "  <-- top!";
                }
                cout << endl;
            }
        }
    }

    void setSize(int stackSize) {
        size = stackSize;
    }
};

int main() {
    Stack stack;
    int choice, item, position, newValue;
    int stackSize;

    cout << "Stack Operations!!!" << endl;
    cout << "Enter the size of the stack (1-100): ";
    cin >> stackSize;

    if (stackSize < 1 || stackSize > 100) {
        cout << "Invalid stack size! Exiting the program..." << endl;
        return 1;
    }

    stack.setSize(stackSize);

    while (true) {
        cout << "\nStack Operations:\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. Check if the stack is empty\n";
        cout << "5. Check if the stack is full\n";
        cout << "6. Change value at position\n";
        cout << "7. Display stack\n";
        cout << "8. Exit\n\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter an element to push: ";
                cin >> item;
                stack.push(item);
                break;
            case 2:
                stack.pop();
                break;
            case 3:
                item = stack.peek();
                if (item != -1) {
                    cout << "Top element of the stack: " << item << endl;
                }
                break;
            case 4:
                cout << "The stack is " << (stack.isEmpty() ? "empty" : "not empty") << endl;
                break;
            case 5:
                cout << "The stack is " << (stack.isFull() ? "full" : "not full") << endl;
                break;
            case 6:
                cout << "Enter position to change (1-" << stackSize << "): ";
                cin >> position;
                cout << "Enter the new value: ";
                cin >> newValue;
                stack.change(position, newValue);
                break;
            case 7:
                cout << "\nCurrent Stack Status:\n";
                stack.display();
                break;
            case 8:
                cout << "Exiting the program... Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice! Please try again!!!" << endl;
        }
    }

    return 0;
}