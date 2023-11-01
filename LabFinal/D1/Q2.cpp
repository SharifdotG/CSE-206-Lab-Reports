#include <iostream>
#include <queue>
#include <string>

using namespace std; // Import the std namespace

// Define a structure to represent a customer's booking information
struct Customer {
    string name;
    int tickets;

    Customer(const string& n, int t) : name(n), tickets(t) {}
};

// Define a queue to manage the booking system
queue<Customer> bookingQueue;
int availableTickets = 100; // Total available tickets

// Function to add a customer to the queue for booking movie tickets
void enqueueBooking(const string& name, int tickets) {
    if (tickets > 0) {
        Customer customer(name, tickets);
        bookingQueue.push(customer);
        cout << name << " has been added to the queue for booking " << tickets << " tickets." << endl;
    } else {
        cout << "Invalid number of tickets requested." << endl;
    }
}

// Function to process the booking for the customer at the front of the queue
void processBooking() {
    if (!bookingQueue.empty()) {
        Customer customer = bookingQueue.front();
        if (customer.tickets <= availableTickets) {
            availableTickets -= customer.tickets;
            cout << customer.name << " has booked " << customer.tickets << " tickets." << endl;
            bookingQueue.pop();
        } else {
            cout << "Not enough tickets available for " << customer.name << ". Moving to the next customer." << endl;
        }
    } else {
        cout << "No customers in the queue." << endl;
    }
}

// Function to cancel the booking for a specific customer
void cancelBooking(const string& name) {
    queue<Customer> tempQueue;
    while (!bookingQueue.empty()) {
        Customer customer = bookingQueue.front();
        if (customer.name == name) {
            availableTickets += customer.tickets;
            cout << "Booking for " << name << " has been canceled." << endl;
        } else {
            tempQueue.push(customer);
        }
        bookingQueue.pop();
    }
    bookingQueue = tempQueue;
}

// Function to display the list of customers in the booking queue
void printBookings() {
    cout << "Current Booking Queue:" << endl;
    queue<Customer> tempQueue = bookingQueue;
    while (!tempQueue.empty()) {
        Customer customer = tempQueue.front();
        cout << customer.name << " - " << customer.tickets << " tickets" << endl;
        tempQueue.pop();
    }
}

int main() {
    // Example usage:
    enqueueBooking("Customer 1", 3);
    enqueueBooking("Customer 2", 5);
    enqueueBooking("Customer 3", 2);

    printBookings();

    processBooking();
    printBookings();

    cancelBooking("Customer 2");
    printBookings();

    enqueueBooking("Customer 4", 7);
    printBookings();

    processBooking();
    processBooking();

    printBookings();

    return 0;
}
