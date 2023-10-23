#include <iostream>
using namespace std;

struct Queue {
    int data[100];
    int front, rear;
    int size;
    int queueSize;

    Queue() {
        front = rear = -1;
        size = 0;
    }

    bool isEmpty() {
        return (front == -1);
    }

    bool isFull() {
        return (size == queueSize);
    }

    void enqueue(int item) {
        if (isFull()) {
            cout << "Queue is full! Cannot enqueue!!" << item << endl;
        } else {
            if (front == -1) {
                front = 0;
            }
            rear = (rear + 1) % 100;
            data[rear] = item;
            size++;
            cout << item << " enqueued into the queue!" << endl;
        }
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty! Cannot dequeue!!" << endl;
        } else {
            int item = data[front];
            if (front == rear) {
                front = rear = -1;
            } else {
                front = (front + 1) % 100;
            }
            size--;
            cout << item << " dequeued from the queue!" << endl;
        }
    }

    void peekFrontAndRear() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
        } else {
            cout << "Front element of the queue: " << data[front] << "!" << endl;
            cout << "Rear element of the queue: " << data[rear] << "!" << endl;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!!" << endl;
        } else {
            cout << "Queue elements:\n";
            int i = front;
            while (true) {
                cout << "  " << data[i];
                if (i == rear) {
                    cout << "  <-- rear!";
                    break;
                }
                if (i == front) {
                    cout << "  <-- front!";
                }
                cout << endl;
                i = (i + 1) % 100;
            }
        }
    }

    void setSize(int size) {
        queueSize = size;
    }

    void change(int position, int newValue) {
        if (isEmpty() || position < 1 || position > size) {
            cout << "Invalid position or the queue is empty! Cannot change the value!!" << endl;
        } else {
            int currentIndex = front;
            for (int i = 1; i < position; i++) {
                currentIndex = (currentIndex + 1) % 100;
            }
            data[currentIndex] = newValue;
            cout << "Value at position " << position << " changed to " << newValue << "!" << endl;
        }
    }
};

int main() {
    Queue queue;
    int choice, item, position, newValue;
    int queueSize;

    cout << "Queue Operations:" << endl;
    cout << "Enter the size of the queue (1-100): ";
    cin >> queueSize;

    if (queueSize < 1 || queueSize > 100) {
        cout << "Invalid queue size! Exiting the program!" << endl;
        return 1;
    }

    queue.setSize(queueSize);

    while (true) {
        cout << "\nQueue Operations:\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Peek front and rear\n";
        cout << "4. Check if the queue is empty\n";
        cout << "5. Check if the queue is full\n";
        cout << "6. Change value at position\n";
        cout << "7. Display queue\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                if (queue.size < queueSize) {
                    cout << "Enter an element to enqueue: ";
                    cin >> item;
                    queue.enqueue(item);
                } else {
                    cout << "Queue is full! Cannot enqueue more items!!" << endl;
                }
                break;
            case 2:
                queue.dequeue();
                break;
            case 3:
                queue.peekFrontAndRear();
                break;
            case 4:
                cout << "The queue is " << (queue.isEmpty() ? "empty" : "not empty!") << endl;
                break;
            case 5:
                cout << "The queue is " << (queue.isFull() ? "full" : "not full!") << endl;
                break;
            case 6:
                cout << "Enter position to change (1-" << queueSize << "): ";
                cin >> position;
                cout << "Enter the new value: ";
                cin >> newValue;
                queue.change(position, newValue);
                break;
            case 7:
                cout << "\nCurrent Queue Status:\n";
                queue.display();
                break;
            case 8:
                cout << "Exiting the program... Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice... Please try again!!" << endl;
        }
    }

    return 0;
}
