//The ticket booking system of Cinemax theater has to be implemented using C++ program. 

//There are 10 rows and 7 seats in each row. Doubly circular linked list has to be 

//maintained to keep track of free seats at rows. Assume some random booking to start 

//with. Use array to store pointers (Head pointer) to each row. On demand

//a) The list of available seats is to be displayed

//b) The seats are to be booked

//c) The booking can be cancelled.

#include <iostream>
using namespace std;

// Seat node for the doubly circular linked list
class Seat {
public:
    int seatNo;
    bool isBooked;
    Seat* next;
    Seat* prev;

    Seat(int num) : seatNo(num), isBooked(false), next(nullptr), prev(nullptr) {}
};

// Row to manage seats as a doubly circular linked list
class Row {
public:
    Seat* head;
    int rowNumber;

    Row(int num) : rowNumber(num), head(nullptr) {}

    // Initialize the row with 7 seats
    void initializeRow() {
        for (int i = 1; i <= 7; ++i) {
            Seat* newSeat = new Seat(i);
            if (!head) {
                head = newSeat;
                head->next = head;
                head->prev = head;
            } else {
                Seat* last = head->prev;
                last->next = newSeat;
                newSeat->prev = last;
                newSeat->next = head;
                head->prev = newSeat;
            }
        }
    }

    // Display available seats in the row
    void displayAvailableSeats() {
        Seat* temp = head;
        bool available = false;
        do {
            if (!temp->isBooked) {
                cout << "Row " << rowNumber + 1 << " Seat " << temp->seatNo << " is available.\n";
                available = true;
            }
            temp = temp->next;
        } while (temp != head);
        if (!available) {
            cout << "All seats are booked in row " << rowNumber + 1 << ".\n";
        }
    }

    // Book a specific seat
    void bookSeat(int seatNo) {
        Seat* temp = head;
        do {
            if (temp->seatNo == seatNo) {
                if (!temp->isBooked) {
                    temp->isBooked = true;
                    cout << "Row " << rowNumber + 1 << " Seat " << seatNo << " is now booked.\n";
                } else {
                    cout << "Row " << rowNumber + 1 << " Seat " << seatNo << " is already booked.\n";
                }
                return;
            }
            temp = temp->next;
        } while (temp != head);
        cout << "Seat number " << seatNo << " not found in row " << rowNumber + 1 << ".\n";
    }

    // Cancel a specific booking
    void cancelBooking(int seatNo) {
        Seat* temp = head;
        do {
            if (temp->seatNo == seatNo) {
                if (temp->isBooked) {
                    temp->isBooked = false;
                    cout << "Booking for Row " << rowNumber + 1 << " Seat " << seatNo << " has been cancelled.\n";
                } else {
                    cout << "Row " << rowNumber + 1 << " Seat " << seatNo << " is already free.\n";
                }
                return;
            }
            temp = temp->next;
        } while (temp != head);
        cout << "Seat number " << seatNo << " not found in row " << rowNumber + 1 << ".\n";
    }
};

int main() {
    Row* theater[10];  // Array to hold 10 rows

    // Initialize the theater with 10 rows
    for (int i = 0; i < 10; ++i) {
        theater[i] = new Row(i);
        theater[i]->initializeRow();
    }

    int choice, row, seat;
    while (true) {
        cout << "\n1. Display Available Seats\n2. Book a Seat\n3. Cancel Booking\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                for (int i = 0; i < 10; ++i) {
                    theater[i]->displayAvailableSeats();
                }
                break;
            case 2:
                cout << "Enter row number (1-10) and seat number (1-7) to book: ";
                cin >> row >> seat;
                if (row >= 1 && row <= 10 && seat >= 1 && seat <= 7) {
                    theater[row - 1]->bookSeat(seat);
                } else {
                    cout << "Invalid row or seat number.\n";
                }
                break;
            case 3:
                cout << "Enter row number (1-10) and seat number (1-7) to cancel booking: ";
                cin >> row >> seat;
                if (row >= 1 && row <= 10 && seat >= 1 && seat <= 7) {
                    theater[row - 1]->cancelBooking(seat);
                } else {
                    cout << "Invalid row or seat number.\n";
                }
                break;
            case 4:
                cout << "Exiting the program.\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
}
