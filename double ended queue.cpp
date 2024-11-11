//A double-ended queue (deque) is a linear list in which additions and deletions may be 

//made at either end. Obtain a data representation mapping a deque into a onedimensional array. Write C++ program to simulate deque with functions to add and 

//delete elements from either end of the deque.

#include <iostream>
using namespace std;

class Deque {
    int* arr;      // Array to store deque elements
    int front, rear, size;  // front and rear pointers and the size of the deque

public:
    // Constructor to initialize the deque with a given size
    Deque(int n) {
        size = n;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    // Function to add an element at the front of the deque
    void addFront(int value) {
        if (front == 0 && rear == size - 1 || front == rear + 1) {
            cout << "Deque is full!" << endl;
            return;
        }
        if (front == -1) {  // First element to be added
            front = rear = 0;
        } else if (front == 0) {  // If front is at the start, wrap it around
            front = size - 1;
        } else {
            front--;  // Move front pointer to the previous position
        }
        arr[front] = value;
    }

    // Function to add an element at the rear of the deque
    void addRear(int value) {
        if (front == 0 && rear == size - 1 || front == rear + 1) {
            cout << "Deque is full!" << endl;
            return;
        }
        if (front == -1) {  // First element to be added
            front = rear = 0;
        } else if (rear == size - 1) {  // If rear is at the end, wrap it around
            rear = 0;
        } else {
            rear++;  // Move rear pointer to the next position
        }
        arr[rear] = value;
    }

    // Function to delete an element from the front of the deque
    void deleteFront() {
        if (front == -1) {
            cout << "Deque is empty!" << endl;
            return;
        }
        if (front == rear) {  // Only one element left
            front = rear = -1;
        } else if (front == size - 1) {  // Wrap front around to 0
            front = 0;
        } else {
            front++;  // Move front pointer to the next position
        }
    }

    // Function to delete an element from the rear of the deque
    void deleteRear() {
        if (front == -1) {
            cout << "Deque is empty!" << endl;
            return;
        }
        if (front == rear) {  // Only one element left
            front = rear = -1;
        } else if (rear == 0) {  // Wrap rear around to size-1
            rear = size - 1;
        } else {
            rear--;  // Move rear pointer to the previous position
        }
    }

    // Function to display the elements of the deque
    void display() {
        if (front == -1) {
            cout << "Deque is empty!" << endl;
            return;
        }
        cout << "Deque elements: ";
        if (front <= rear) {
            for (int i = front; i <= rear; i++) {
                cout << arr[i] << " ";
            }
        } else {
            for (int i = front; i < size; i++) {
                cout << arr[i] << " ";
            }
            for (int i = 0; i <= rear; i++) {
                cout << arr[i] << " ";
            }
        }
        cout << endl;
    }
};

// Main function
int main() {
    Deque dq(5);  // Create deque with size 5

    dq.addRear(10);  // Add element at rear
    dq.addRear(20);
    dq.addFront(5);  // Add element at front
    dq.addRear(30);
    dq.addFront(1);

    dq.display();  // Display elements

    dq.deleteFront();  // Delete element from front
    dq.deleteRear();   // Delete element from rear

    dq.display();  // Display after deletion

    return 0;
}
