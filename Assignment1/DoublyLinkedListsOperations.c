#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* head = NULL;

void firstInsert(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = head;
    if (head != NULL) {
        head->prev = newNode;
    }
    head = newNode;
}

void betweenInsert(int value, int position) {
    if (position <= 1) {
        firstInsert(value);
        return;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    struct Node* current = head;
    int count = 1;
    while (count < position - 1 && current != NULL) {
        current = current->next;
        count++;
    }

    if (current == NULL) {
        printf("Cannot insert. Position is out of range.\n");
        return;
    }

    newNode->prev = current;
    newNode->next = current->next;

    if (current->next != NULL) {
        current->next->prev = newNode;
    }

    current->next = newNode;
}

void lastInsert(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    if (head == NULL) {
        newNode->prev = NULL;
        head = newNode;
    } else {
        struct Node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }
}

void firstDelete() {
    if (head != NULL) {
        struct Node* temp = head;
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        free(temp);
    }
}

void betweenDelete(int position) {
    if (position <= 1) {
        firstDelete();
        return;
    }

    struct Node* current = head;
    int count = 1;
    while (count < position - 1 && current != NULL) {
        current = current->next;
        count++;
    }

    if (current == NULL || current->next == NULL || current->next->next == NULL) {
        printf("Cannot delete. Node not found.\n");
        return;
    }

    struct Node* temp = current->next;
    current->next = temp->next;

    if (temp->next != NULL) {
        temp->next->prev = current;
    }

    free(temp);
}

void lastDelete() {
    if (head == NULL) {
        printf("Cannot delete. List is empty.\n");
        return;
    }

    if (head->next == NULL) {
        free(head);
        head = NULL;
    } else {
        struct Node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }

        if (current->prev != NULL) {
            current->prev->next = NULL;
        }

        free(current);
    }
}

void nodeUpdate(int value, int position) {
    struct Node* current = head;
    int count = 1;
    while (current != NULL && count < position) {
        current = current->next;
        count++;
    }

    if (current != NULL) {
        current->data = value;
    } else {
        printf("Node not found at position %d. Update failed.\n", position);
    }
}

void traversing() {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    int choice, value, position;

    while (1) {
        printf("Doubly Linked List Operations:\n");
        printf("1. Insertion (First)\n");
        printf("2. Insertion (Between first & last)\n");
        printf("3. Insertion (Last)\n");
        printf("4. Delete (First)\n");
        printf("5. Delete (Between first & last)\n");
        printf("6. Delete (Last)\n");
        printf("7. Update\n");
        printf("8. Traverse\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert at the beginning: ");
                scanf("%d", &value);
                firstInsert(value);
                break;
            case 2:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                printf("Enter position (1 for after the first node): ");
                scanf("%d", &position);
                betweenInsert(value, position);
                break;
            case 3:
                printf("Enter value to insert at the end: ");
                scanf("%d", &value);
                lastInsert(value);
                break;
            case 4:
                firstDelete();
                break;
            case 5:
                printf("Enter position (1 for the first node to delete after): ");
                scanf("%d", &position);
                betweenDelete(position);
                break;
            case 6:
                lastDelete();
                break;
            case 7:
                printf("Enter position of the node to update: ");
                scanf("%d", &position);
                printf("Enter the new value: ");
                scanf("%d", &value);
                nodeUpdate(value, position);
                break;
            case 8:
                printf("Doubly Linked List: ");
                traversing();
                break;
            case 9:
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
