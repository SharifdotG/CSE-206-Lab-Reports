#include <stdio.h>
#include <stdbool.h>

struct Queue {
    int data[100];
    int front, rear;
    int size;
    int queueSize;
};

void initQueue(struct Queue *queue) {
    queue->front = queue->rear = -1;
    queue->size = 0;
}

bool isEmpty(const struct Queue *queue) {
    return (queue->front == -1);
}

bool isFull(const struct Queue *queue) {
    return (queue->size == queue->queueSize);
}

void enqueue(struct Queue *queue, int item) {
    if (isFull(queue)) {
        printf("Queue is full. Cannot enqueue %d\n", item);
    } else {
        if (queue->front == -1) {
            queue->front = 0;
        }
        queue->rear = (queue->rear + 1) % 100;
        queue->data[queue->rear] = item;
        queue->size++;
        printf("%d enqueued into the queue.\n", item);
    }
}

void dequeue(struct Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot dequeue.\n");
    } else {
        int item = queue->data[queue->front];
        if (queue->front == queue->rear) {
            queue->front = queue->rear = -1;
        } else {
            queue->front = (queue->front + 1) % 100;
        }
        queue->size--;
        printf("%d dequeued from the queue.\n", item);
    }
}

void peekFrontAndRear(const struct Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
    } else {
        printf("Front element of the queue: %d\n", queue->data[queue->front]);
        printf("Rear element of the queue: %d\n", queue->data[queue->rear]);
    }
}

void display(const struct Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue elements:\n");
        int i = queue->front;
        while (1) {
            printf("  %d", queue->data[i]);
            if (i == queue->rear) {
                printf("  <-- rear");
                break;
            }
            if (i == queue->front) {
                printf("  <-- front");
            }
            printf("\n");
            i = (i + 1) % 100;
        }
    }
}

void setSize(struct Queue *queue, int size) {
    queue->queueSize = size;
}

void change(struct Queue *queue, int position, int newValue) {
    if (isEmpty(queue) || position < 1 || position > queue->size) {
        printf("Invalid position or the queue is empty. Cannot change the value.\n");
    } else {
        int currentIndex = queue->front;
        for (int i = 1; i < position; i++) {
            currentIndex = (currentIndex + 1) % 100;
        }
        queue->data[currentIndex] = newValue;
        printf("Value at position %d changed to %d\n", position, newValue);
    }
}

int main() {
    struct Queue queue;
    int choice, item, position, newValue;
    int queueSize;

    printf("Welcome to the Queue Operations Program\n");
    printf("Enter the size of the queue (1-100): ");
    scanf("%d", &queueSize);

    if (queueSize < 1 || queueSize > 100) {
        printf("Invalid queue size. Exiting the program.\n");
        return 1;
    }

    initQueue(&queue);
    setSize(&queue, queueSize);

    while (1) {
        printf("\nQueue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek front and rear\n");
        printf("4. Check if the queue is empty\n");
        printf("5. Check if the queue is full\n");
        printf("6. Change value at position\n");
        printf("7. Display queue\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (queue.size < queueSize) {
                    printf("Enter an element to enqueue: ");
                    scanf("%d", &item);
                    enqueue(&queue, item);
                } else {
                    printf("Queue is full. Cannot enqueue more items.\n");
                }
                break;
            case 2:
                dequeue(&queue);
                break;
            case 3:
                peekFrontAndRear(&queue);
                break;
            case 4:
                printf("The queue is %s\n", (isEmpty(&queue) ? "empty" : "not empty"));
                break;
            case 5:
                printf("The queue is %s\n", (isFull(&queue) ? "full" : "not full"));
                break;
            case 6:
                printf("Enter position to change (1-%d): ", queueSize);
                scanf("%d", &position);
                printf("Enter the new value: ");
                scanf("%d", &newValue);
                change(&queue, position, newValue);
                break;
            case 7:
                printf("\nCurrent Queue Status:\n");
                display(&queue);
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
