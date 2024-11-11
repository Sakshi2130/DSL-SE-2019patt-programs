//Pizza parlor accepting maximum M orders. Orders are served in first come first served 

//basis. Order once placed cannot be cancelled. Write C++ program to simulate the system 

//using circular queue using array.

#include <iostream>
using namespace std;

class PizzaParlor {
private:
    int *queue;
    int front, rear, size, capacity;

public:
    // Constructor to initialize the queue
    PizzaParlor(int M) {
        capacity = M;  // Maximum orders the parlor can accept
        size = 0;      // Initially no orders are there
        front = 0;
        rear = capacity - 1;
        queue = new int[capacity];  // Dynamic memory allocation for the queue
    }

    // Function to check if the queue is full
    bool isFull() {
        return size == capacity;
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        return size == 0;
    }

    // Function to add an order
    void addOrder(int orderId) {
        if (isFull()) {
            cout << "Pizza parlor is full! Cannot accept more orders.\n";
        } else {
            rear = (rear + 1) % capacity;  // Circular increment
            queue[rear] = orderId;
            size++;
            cout << "Order " << orderId << " placed successfully.\n";
        }
    }

    // Function to serve the next order
    void serveOrder() {
        if (isEmpty()) {
            cout << "No orders to serve.\n";
        } else {
            int orderId = queue[front];
            front = (front + 1) % capacity;  // Circular increment
            size--;
            cout << "Order " << orderId << " served.\n";
        }
    }

    // Destructor to free the memory allocated for the queue
    ~PizzaParlor() {
        delete[] queue;
    }
};

int main() {
    int M;
    cout << "Enter maximum number of orders the pizza parlor can accept: ";
    cin >> M;

    PizzaParlor parlor(M);

    while (true) {
        int choice;
        cout << "\n1. Place Order\n2. Serve Order\n3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            int orderId;
            cout << "Enter order ID to place: ";
            cin >> orderId;
            parlor.addOrder(orderId);
        } else if (choice == 2) {
            parlor.serveOrder();
        } else if (choice == 3) {
            cout << "Exiting the program.\n";
            break;
        } else {
            cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
