#include <stdio.h>
#include <stdbool.h>

struct Stack {
    int data[100];
    int top;
    int size;
};

void initStack(struct Stack* stack) {
    stack->top = -1;
    stack->size = 0;
}

bool isEmpty(const struct Stack* stack) {
    return stack->top == -1;
}

bool isFull(const struct Stack* stack) {
    return stack->top == stack->size - 1;
}

void push(struct Stack* stack, int item) {
    if (isFull(stack)) {
        printf("Stack Overflow! Cannot push %d\n", item);
    } else {
        stack->data[++stack->top] = item;
        printf("%d pushed onto the stack.\n", item);
    }
}

void pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow! Stack is empty.\n");
    } else {
        printf("%d popped from the stack.\n", stack->data[stack->top]);
        stack->top--;
    }
}

int peek(const struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
        return -1;
    }
    return stack->data[stack->top];
}

void change(struct Stack* stack, int position, int newValue) {
    if (position < 1 || position > stack->size) {
        printf("Invalid position. Cannot change the value.\n");
    } else {
        stack->data[position - 1] = newValue;
        printf("Value at position %d changed to %d\n", position, newValue);
    }
}

void display(const struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack elements:\n");
        for (int i = stack->top; i >= 0; i--) {
            printf("  %d", stack->data[i]);
            if (i == stack->top) {
                printf("  <-- top");
            }
            printf("\n");
        }
    }
}

void setSize(struct Stack* stack, int stackSize) {
    stack->size = stackSize;
}

int main() {
    struct Stack stack;
    int choice, item, position, newValue;
    int stackSize;

    printf("Stack Operations!\n");
    printf("Enter the size of the stack (1-100): ");
    scanf("%d", &stackSize);

    if (stackSize < 1 || stackSize > 100) {
        printf("Invalid stack size. Exiting the program.\n");
        return 1;
    }

    initStack(&stack);
    setSize(&stack, stackSize);

    while (1) {
        printf("\nStack Operations:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Check if the stack is empty\n");
        printf("5. Check if the stack is full\n");
        printf("6. Change value at position\n");
        printf("7. Display stack\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter an element to push: ");
                scanf("%d", &item);
                push(&stack, item);
                break;
            case 2:
                pop(&stack);
                break;
            case 3:
                item = peek(&stack);
                if (item != -1) {
                    printf("Top element of the stack: %d\n", item);
                }
                break;
            case 4:
                printf("The stack is %s\n", isEmpty(&stack) ? "empty" : "not empty");
                break;
            case 5:
                printf("The stack is %s\n", isFull(&stack) ? "full" : "not full");
                break;
            case 6:
                printf("Enter position to change (1-%d): ", stack.size);
                scanf("%d", &position);
                printf("Enter the new value: ");
                scanf("%d", &newValue);
                change(&stack, position, newValue);
                break;
            case 7:
                printf("\nCurrent Stack Status:\n");
                display(&stack);
                break;
            case 8:
                printf("Exiting the program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
