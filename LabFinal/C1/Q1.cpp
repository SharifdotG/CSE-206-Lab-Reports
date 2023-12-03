#include <iostream>
#include <stack>
#include <string>

using namespace std;

string currentText;
stack<string> operationStack;

void insert(const string& enteredText) {
    cout << "\nInserting \"" << enteredText << "\"\n";
    operationStack.push(currentText);
    currentText += enteredText;
}

void deleteLast() {
    cout << "\nDeleting last character\n";
    if (!currentText.empty()) {
        operationStack.push(currentText);
        currentText.pop_back();
    }
}

void print() {
    cout << "\nCurrent text: ";
    cout << currentText << endl;
}

void undo() {
    cout << "\nUndoing last operation\n";
    if (!operationStack.empty()) {
        currentText = operationStack.top();
        operationStack.pop();
    }
}

int main() {
    currentText = "";

    insert("My Name is: ");
    insert("Sharif :3");
    print();

    deleteLast();
    print();

    deleteLast();
    print();

    undo();
    print();

    undo();
    print();

    return 0;
}