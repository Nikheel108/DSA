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
        a) Input Restricted Deque
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

void insertRear(int val) {
    if (isFull()) {
        cout << "Deque is full.\n";
        return;
    }
    if (front == -1) front = 0;
    rear = (rear + 1) % SIZE;
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

void deleteRear() {
    if (isEmpty()) {
        cout << "Deque is empty.\n";
        return;
    }
    cout << "Deleted from rear: " << dequeArr[rear] << endl;
    if (front == rear) {
        front = rear = -1;
    } else {
        rear = (rear - 1 + SIZE) % SIZE;
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
        cout << "\n--- Input Restricted Deque ---\n";
        cout << "1. Insert at Rear\n";
        cout << "2. Delete from Front\n";
        cout << "3. Delete from Rear\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> val;
            insertRear(val);
            break;
        case 2:
            deleteFront();
            break;
        case 3:
            deleteRear();
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
    --- Input Restricted Deque ---                                      
    1. Insert at Rear                                                   
    2. Delete from Front                                                
    3. Delete from Rear                                                 
    4. Display                                                          
    5. Exit                                                             
    Enter your choice: 1                                                
    Enter value: 10                                                     
    Inserted at rear: 10                                                
                                                                        
    --- Input Restricted Deque ---                                      
    1. Insert at Rear                                                   
    2. Delete from Front                                                
    3. Delete from Rear                                                 
    4. Display                                                          
    5. Exit                                                             
    Enter your choice: 1                                                
    Enter value: 20                                                     
    Inserted at rear: 20                                                

    --- Input Restricted Deque ---
    1. Insert at Rear
    2. Delete from Front
    3. Delete from Rear
    4. Display
    5. Exit
    Enter your choice: 1
    Enter value: 30
    Inserted at rear: 30

    --- Input Restricted Deque ---
    1. Insert at Rear
    2. Delete from Front
    3. Delete from Rear
    4. Display
    5. Exit
    Enter your choice: 4
    Deque elements: 10 20 30 

    --- Input Restricted Deque ---
    1. Insert at Rear
    2. Delete from Front
    3. Delete from Rear
    4. Display
    5. Exit
    Enter your choice: 2
    Deleted from front: 10

    --- Input Restricted Deque ---
    1. Insert at Rear
    2. Delete from Front
    3. Delete from Rear
    4. Display
    5. Exit
    Enter your choice: 3
    Deleted from rear: 30

    --- Input Restricted Deque ---
    1. Insert at Rear
    2. Delete from Front
    3. Delete from Rear
    4. Display
    5. Exit
    Enter your choice: 4
    Deque elements: 20 

    --- Input Restricted Deque ---
    1. Insert at Rear
    2. Delete from Front
    3. Delete from Rear
    4. Display
    5. Exit
    Enter your choice: 5
    Exiting...
    [Finished in 75.46s]
*/