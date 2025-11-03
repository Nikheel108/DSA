// DSA: Practical 7 Double Ended Queue

// Info

/*
    Name: Nikheel C Khadakabhavi
    Dept: AIML(A1)
    PRN: 202401110020
*/

// Problem Statement 

/*
    Design and implement a program for double ended queue and its operations 
    for a shopping mall under given Scenarios :-
        b) Output Restricted Deque.
*/

// Code

#include <iostream>
using namespace std;

#define SIZE 5

int dequeArr[SIZE];
int front = -1, rear = -1;

bool isFull() {
    return (front == 0 && rear == SIZE - 1) || (front == rear + 1);
}

bool isEmpty() {
    return (front == -1);
}

void insertFront(int val) {
    if (isFull()) {
        cout << "Deque is full.\n";
        return;
    }
    if (front == -1) {
        front = rear = 0;
    } else {
        front = (front - 1 + SIZE) % SIZE;
    }
    dequeArr[front] = val;
    cout << "Inserted at front: " << val << endl;
}

void insertRear(int val) {
    if (isFull()) {
        cout << "Deque is full.\n";
        return;
    }
    if (front == -1) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % SIZE;
    }
    dequeArr[rear] = val;
    cout << "Inserted at rear: " << val << endl;
}

void deleteFront() {
    if (isEmpty()) {
        cout << "Deque is empty.\n";
        return;
    }
    cout << "Deleted from front: " << dequeArr[front] << endl;
    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % SIZE;
    }
}

void display() {
    if (isEmpty()) {
        cout << "Deque is empty.\n";
        return;
    }
    cout << "Deque elements: ";
    int i = front;
    while (true) {
        cout << dequeArr[i] << " ";
        if (i == rear) break;
        i = (i + 1) % SIZE;
    }
    cout << endl;
}

int main() {
    int choice, val;
    do {
        cout << "\n--- Output Restricted Deque ---\n";
        cout << "1. Insert at Front\n";
        cout << "2. Insert at Rear\n";
        cout << "3. Delete from Front\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> val;
            insertFront(val);
            break;
        case 2:
            cout << "Enter value: ";
            cin >> val;
            insertRear(val);
            break;
        case 3:
            deleteFront();
            break;
        case 4:
            display();
            break;
        case 5:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice.\n";
        }
    } while (choice != 5);
    return 0;
}

// Output

/*
    --- Output Restricted Deque ---
    1. Insert at Front
    2. Insert at Rear
    3. Delete from Front
    4. Display
    5. Exit
    Enter your choice: 1
    Enter value: 50
    Inserted at front: 50

    --- Output Restricted Deque ---
    1. Insert at Front
    2. Insert at Rear
    3. Delete from Front
    4. Display
    5. Exit
    Enter your choice: 2
    Enter value: 60
    Inserted at rear: 60

    --- Output Restricted Deque ---
    1. Insert at Front
    2. Insert at Rear
    3. Delete from Front
    4. Display
    5. Exit
    Enter your choice: 1
    Enter value: 40
    Inserted at front: 40

    --- Output Restricted Deque ---
    1. Insert at Front
    2. Insert at Rear
    3. Delete from Front
    4. Display
    5. Exit
    Enter your choice: 4
    Deque elements: 40 50 60 

    --- Output Restricted Deque ---
    1. Insert at Front
    2. Insert at Rear
    3. Delete from Front
    4. Display
    5. Exit
    Enter your choice: 3
    Deleted from front: 40

    --- Output Restricted Deque ---
    1. Insert at Front
    2. Insert at Rear
    3. Delete from Front
    4. Display
    5. Exit
    Enter your choice: 4
    Deque elements: 50 60 

    --- Output Restricted Deque ---
    1. Insert at Front
    2. Insert at Rear
    3. Delete from Front
    4. Display
    5. Exit
    Enter your choice: 5
    Exiting...
    [Finished in 57.91s]
*/