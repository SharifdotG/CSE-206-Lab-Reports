#include <iostream>

// Define a struct for singly linked list node
struct Node {
    int data;
    Node* next;
};

// Initialize the head of the linked list
Node* head = nullptr;

// Function to insert a node at the beginning of the list
void firstInsert(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

// Function to insert a node between the first and last nodes
void betweenInsert(int value, int position) {
    Node* newNode = new Node;
    newNode->data = value;
    Node* current = head;
    int count = 1;
    while (count < position - 1 && current->next != nullptr) {
        current = current->next;
        count++;
    }
    newNode->next = current->next;
    current->next = newNode;
}

// Function to insert a node at the end of the list
void lastInsert(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Function to delete the first node
void firstDelete() {
    if (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

// Function to delete a node between the first and last nodes
void betweenDelete(int position) {
    if (position == 1) {
        firstDelete();
        return;
    }

    Node* current = head;
    int count = 1;
    while (count < position - 1 && current->next != nullptr) {
        current = current->next;
        count++;
    }

    if (current->next == nullptr || current->next->next == nullptr) {
        std::cout << "Cannot delete. Node not found." << std::endl;
        return;
    }

    Node* temp = current->next;
    current->next = current->next->next;
    delete temp;
}

// Function to delete the last node
void lastDelete() {
    if (head == nullptr) {
        std::cout << "Cannot delete. List is empty." << std::endl;
        return;
    }

    if (head->next == nullptr) {
        delete head;
        head = nullptr;
    } else {
        Node* current = head;
        while (current->next->next != nullptr) {
            current = current->next;
        }
        delete current->next;
        current->next = nullptr;
    }
}

// Function to update the value of a node at a given position
void nodeUpdate(int value, int position) {
    Node* current = head;
    int count = 1;
    while (current != nullptr && count < position) {
        current = current->next;
        count++;
    }

    if (current != nullptr) {
        current->data = value;
    } else {
        std::cout << "Node not found at position " << position << ". Update failed." << std::endl;
    }
}

// Function to traverse and print the linked list
void traversing() {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

int main() {
    int choice, value, position;

    while (true) {
        std::cout << "Singly Linked List Operations:" << std::endl;
        std::cout << "1. Insertion (First)" << std::endl;
        std::cout << "2. Insertion (Between first & last)" << std::endl;
        std::cout << "3. Insertion (Last)" << std::endl;
        std::cout << "4. Delete (First)" << std::endl;
        std::cout << "5. Delete (Between first & last)" << std::endl;
        std::cout << "6. Delete (Last)" << std::endl;
        std::cout << "7. Update" << std::endl;
        std::cout << "8. Traverse" << std::endl;
        std::cout << "9. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter value to insert at the beginning: ";
                std::cin >> value;
                firstInsert(value);
                break;
            case 2:
                std::cout << "Enter value to insert: ";
                std::cin >> value;
                std::cout << "Enter position (1 for after the first node): ";
                std::cin >> position;
                betweenInsert(value, position);
                break;
            case 3:
                std::cout << "Enter value to insert at the end: ";
                std::cin >> value;
                lastInsert(value);
                break;
            case 4:
                firstDelete();
                break;
            case 5:
                std::cout << "Enter position (1 for the first node to delete after): ";
                std::cin >> position;
                betweenDelete(position);
                break;
            case 6:
                lastDelete();
                break;
            case 7:
                std::cout << "Enter position of the node to update: ";
                std::cin >> position;
                std::cout << "Enter the new value: ";
                std::cin >> value;
                nodeUpdate(value, position);
                break;
            case 8:
                std::cout << "Linked List: ";
                traversing();
                break;
            case 9:
                return 0;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }

    return 0;
}
