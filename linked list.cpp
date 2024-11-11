//Department of Computer Engineering has student's club named 'Pinnacle Club'. Students 

//of second, third and final year of department can be granted membership on request. 

//Similarly one may cancel the membership of club. First node is reserved for president of 

//club and last node is reserved for secretary of club. Write C++ program to maintain club 

//member‘s information using singly linked list. Store student PRN and Name. Write 

//functions to:

//a) Add and delete the members as well as president or even secretary.

//b) Compute total number of members of club

//c) Display members

//d) Two linked lists exists for two divisions. Concatenate two lists

#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    int prn; // PRN of student
    string name; // Name of student
    Node* next;

    Node(int p, string n) : prn(p), name(n), next(nullptr) {}
};

class PinnacleClub {
    Node* head; // First node (President)
    Node* tail; // Last node (Secretary)

public:
    PinnacleClub() : head(nullptr), tail(nullptr) {}

    // Function to add a member (President, Secretary, or normal member)
    void addMember(int prn, string name, string position) {
        Node* newNode = new Node(prn, name);

        if (position == "President") {
            newNode->next = head;
            head = newNode;
            if (tail == nullptr) tail = head; // If no members yet, head = tail
        } else if (position == "Secretary") {
            if (head == nullptr) { // If no members, make it President & Secretary
                head = tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }
        } else { // Add as normal member
            if (head == nullptr) {
                head = tail = newNode;
            } else {
                Node* temp = head;
                while (temp->next != tail) {
                    temp = temp->next;
                }
                newNode->next = tail;
                temp->next = newNode;
            }
        }
    }

    // Function to delete a member (President, Secretary, or normal member)
    void deleteMember(string position) {
        if (head == nullptr) {
            cout << "Club is empty.\n";
            return;
        }

        if (position == "President") {
            Node* temp = head;
            head = head->next;
            delete temp;
            if (head == nullptr) tail = nullptr;
        } else if (position == "Secretary") {
            Node* temp = head;
            if (head == tail) { // Only one member
                delete head;
                head = tail = nullptr;
            } else {
                while (temp->next != tail) {
                    temp = temp->next;
                }
                delete tail;
                tail = temp;
                tail->next = nullptr;
            }
        } else { // Delete normal member by PRN
            cout << "Enter PRN of member to delete: ";
            int prn;
            cin >> prn;

            Node* temp = head;
            Node* prev = nullptr;
            while (temp != nullptr && temp->prn != prn) {
                prev = temp;
                temp = temp->next;
            }

            if (temp == nullptr) {
                cout << "Member with PRN " << prn << " not found.\n";
                return;
            }

            prev->next = temp->next;
            delete temp;
        }
    }

    // Function to count total members
    int countMembers() {
        int count = 0;
        Node* temp = head;
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    // Function to display members
    void displayMembers() {
        Node* temp = head;
        cout << "Club Members:\n";
        while (temp != nullptr) {
            cout << "PRN: " << temp->prn << ", Name: " << temp->name << endl;
            temp = temp->next;
        }
    }

    // Function to concatenate two club lists
    void concatenate(PinnacleClub& otherClub) {
        if (head == nullptr) {
            head = otherClub.head;
            tail = otherClub.tail;
        } else {
            tail->next = otherClub.head;
            if (otherClub.tail != nullptr) {
                tail = otherClub.tail;
            }
        }
        otherClub.head = otherClub.tail = nullptr;
    }
};

int main() {
    PinnacleClub clubA, clubB;

    clubA.addMember(1, "Alice", "President");
    clubA.addMember(2, "Bob", "Member");
    clubA.addMember(3, "Charlie", "Secretary");

    clubB.addMember(4, "David", "President");
    clubB.addMember(5, "Eve", "Member");
    clubB.addMember(6, "Frank", "Secretary");

    cout << "Club A Members:\n";
    clubA.displayMembers();

    cout << "\nClub B Members:\n";
    clubB.displayMembers();

    cout << "\nConcatenating Club A and Club B...\n";
    clubA.concatenate(clubB);

    cout << "\nCombined Club Members:\n";
    clubA.displayMembers();

    cout << "\nTotal Members: " << clubA.countMembers() << endl;

    clubA.deleteMember("President");
    cout << "\nAfter deleting President:\n";
    clubA.displayMembers();

    return 0;
}
