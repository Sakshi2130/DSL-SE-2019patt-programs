//Queues are frequently used in computer programming, and a typical example is the 

//creation of a job queue by an operating system. If the operating system does not use 

//priorities, then the jobs are processed in the order they enter the system. Write C++ 

//program for simulating job queue. Write functions to add job and delete job from queue

#include <iostream>
#include <queue>
#include <string>
using namespace std;

// Function to add a job to the queue
void addJob(queue<string>& jobQueue, const string& job) {
    jobQueue.push(job);
    cout << "Job added: " << job << endl;
}

// Function to delete a job from the queue
void deleteJob(queue<string>& jobQueue) {
    if (!jobQueue.empty()) {
        cout << "Job deleted: " << jobQueue.front() << endl;
        jobQueue.pop();
    } else {
        cout << "No jobs in the queue to delete." << endl;
    }
}

// Function to display the jobs in the queue
void displayJobs(const queue<string>& jobQueue) {
    if (jobQueue.empty()) {
        cout << "The job queue is empty." << endl;
    } else {
        queue<string> tempQueue = jobQueue;
        cout << "Current jobs in the queue: " << endl;
        while (!tempQueue.empty()) {
            cout << tempQueue.front() << endl;
            tempQueue.pop();
        }
    }
}

int main() {
    queue<string> jobQueue;
    int choice;
    string job;

    while (true) {
        cout << "\nJob Queue Menu:" << endl;
        cout << "1. Add Job" << endl;
        cout << "2. Delete Job" << endl;
        cout << "3. Display Jobs" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter job name: ";
                cin.ignore(); // To ignore any leftover newline character in the input buffer
                getline(cin, job);
                addJob(jobQueue, job);
                break;

            case 2:
                deleteJob(jobQueue);
                break;

            case 3:
                displayJobs(jobQueue);
                break;

            case 4:
                cout << "Exiting the program..." << endl;
                return 0;

            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }

    return 0;
}
