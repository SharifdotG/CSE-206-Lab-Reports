#include <iostream>
#include <stack>
#include <string>

using namespace std;

string currentText;
stack<string> operationStack;

void insert(const string& text) {
    operationStack.push(currentText);
    currentText += text;
}

void deleteLast() {
    if (!currentText.empty()) {
        operationStack.push(currentText);
        currentText.pop_back();
    }
}

void print() {
    cout << currentText << endl;
}

void undo() {
    if (!operationStack.empty()) {
        currentText = operationStack.top();
        operationStack.pop();
    }
}

int main() {
    currentText = ""; // Initialize an empty editor

    // Example usage
    insert("Hello, ");
    insert("world!");
    print(); // Output: "Hello, world!"

    deleteLast();
    print(); // Output: "Hello, world"

    undo();
    print(); // Output: "Hello, world!"

    return 0;
}