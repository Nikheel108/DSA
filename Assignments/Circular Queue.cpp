// DSA: Practical 6 Circular Queue

// Info

/*
    Name: Nikheel C Khadakabhavi
    Dept: AIML(A1)
    PRN: 202401110020
*/

// Problem Statement 

/*
    Implement a Circular Queue-based system to manage real-life service requests, 
    ensuring efficient customer handling using the FIFO approach, 
    where resolved requests free up slots for new entries without data shifting.
*/

// Code

#include <iostream>
#include <string>
using namespace std;

#define SIZE 5

string queueArr[SIZE];
int front = -1, rear = -1;

bool isFull() {
    return (front == 0 && rear == SIZE - 1) || (front == rear + 1);
}

bool isEmpty() {
    return (front == -1);
}

void enqueue(string request) {
    if (isFull()) {
        cout << "Queue is Full! Cannot add new request.\n";
        return;
    }
    if (front == -1)
        front = 0;
    rear = (rear + 1) % SIZE;
    queueArr[rear] = request;
    cout << "Request added: " << request << endl;
}

void dequeue() {
    if (isEmpty()) {
        cout << "No pending requests! Queue is empty.\n";
        return;
    }
    cout << "Resolved request: " << queueArr[front] << endl;
    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % SIZE;
    }
}

void display() {
    if (isEmpty()) {
        cout << "No requests in the system.\n";
        return;
    }
    cout << "\nCurrent Service Requests:\n";
    int i = front;
    while (true) {
        cout << " - " << queueArr[i] << endl;
        if (i == rear)
            break;
        i = (i + 1) % SIZE;
    }
    cout << endl;
}

int main() {
    int choice;
    string request;
    cout << "Service Request Management System (Circular Queue)\n";
    do {
        cout << "\n1. Add Service Request\n";
        cout << "2. Resolve Request\n";
        cout << "3. Display Pending Requests\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "Enter service request: ";
            cin.ignore();
            getline(cin, request);
            enqueue(request);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            cout << "Exiting system...\n";
            break;
        default:
            cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 4);
    return 0;
}

// Output 

/*
    Service Request Management System (Circular Queue)

    1. Add Service Request
    2. Resolve Request
    3. Display Pending Requests
    4. Exit
    Enter your choice: 1
    Enter service request: Internet Issue
    Request added: Internet Issue

    1. Add Service Request
    2. Resolve Request
    3. Display Pending Requests
    4. Exit
    Enter your choice: 1
    Enter service request: Payment Error
    Request added: Payment Error

    1. Add Service Request
    2. Resolve Request
    3. Display Pending Requests
    4. Exit
    Enter your choice: 3

    Current Service Requests:
     - Internet Issue
     - Payment Error


    1. Add Service Request
    2. Resolve Request
    3. Display Pending Requests
    4. Exit
    Enter your choice: 2
    Resolved request: Internet Issue

    1. Add Service Request
    2. Resolve Request
    3. Display Pending Requests
    4. Exit
    Enter your choice: 3

    Current Service Requests:
     - Payment Error


    1. Add Service Request
    2. Resolve Request
    3. Display Pending Requests
    4. Exit
    Enter your choice: 4
    Exiting system...
    [Finished in 51.04s]
*/