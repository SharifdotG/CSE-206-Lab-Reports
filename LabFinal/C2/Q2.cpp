#include <iostream>
#include <string>

using namespace std;

struct Contact {
    string name;
    string number;
    Contact* next;
};

Contact* addContact(Contact* head, const string& name, const string& number) {
    Contact* addNewContact = new Contact;
    addNewContact->name = name;
    addNewContact->number = number;
    addNewContact->next = head;
    return addNewContact;
}

void searchContact(Contact* head, const string& name) {
    Contact* current = head;
    while (current != nullptr) {
        if (current->name == name) {
            cout << "Contact found: " << current->name << ", " << current->number << endl;
            return;
        }
        current = current->next;
    }
    cout << "Contact not found: " << name << endl;
}

Contact* deleteContact(Contact* head, const string& name) {
    Contact* current = head;
    Contact* prev = nullptr;

    while (current != nullptr) {
        if (current->name == name) {
            if (prev != nullptr) {
                prev->next = current->next;
            } else {
                head = current->next;
            }
            delete current;
            cout << "Contact deleted: " << name << endl;
            return head;
        }
        prev = current;
        current = current->next;
    }
    cout << "Contact not found: " << name << endl;
    return head;
}

void displayContacts(Contact* head) {
    Contact* current = head;
    if (current == nullptr) {
        cout << "Contact list is empty." << endl;
    } else {
        cout << "Contacts in the list:" << endl;
        while (current != nullptr) {
            cout << current->name << ", " << current->number << endl;
            current = current->next;
        }
    }
}

void freeContacts(Contact* head) {
    Contact* current = head;
    while (current != nullptr) {
        Contact* temp = current;
        current = current->next;
        delete temp;
    }
}

int main() {
    Contact* head = nullptr;
    int choice;
    string name;
    string number;

    while (true) {
        cout << "Choose an operation:" << endl;
        cout << "1. Add New Contact" << endl;
        cout << "2. Search A Contact" << endl;
        cout << "3. Delete A Contact" << endl;
        cout << "4. Display All The Contacts" << endl;
        cout << "5. Exit The Program" << endl;

        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter a name (Single Word) and the Phone Number: ";
                cin >> name >> number;
                head = addContact(head, name, number);
                cout << "Contact added: " << name << ", " << number << endl;
                break;

            case 2:
                cout << "Enter the Contact Name that you want to search: ";
                cin >> name;
                searchContact(head, name);
                break;

            case 3:
                cout << "Enter the name to delete: ";
                cin >> name;
                head = deleteContact(head, name);
                break;

            case 4:
                displayContacts(head);
                break;

            case 5:
                freeContacts(head);
                return 0;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
