// DSA: Practical 7 Double Ended Queue

// Info

/*
    Name: Nikheel C Khadakabhavi
    Dept: AIML(A1)
    PRN: 202401110020
*/

// Problem Statement 

/*
    Implement a program to check whether the given string is 
    palindrome or not using doubly ended queue.
*/

// Code

#include <iostream>
#include <string>
using namespace std;

#define SIZE 100

char dequeArr[SIZE];
int front = -1, rear = -1;

bool isFull() {
    return (front == 0 && rear == SIZE - 1) || (front == rear + 1);
}

bool isEmpty() {
    return (front == -1);
}

void insertRear(char c) {
    if (isFull()) return;
    if (front == -1) front = 0;
    rear = (rear + 1) % SIZE;
    dequeArr[rear] = c;
}

char deleteFront() {
    if (isEmpty()) return '\0';
    char val = dequeArr[front];
    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % SIZE;
    }
    return val;
}

char deleteRear() {
    if (isEmpty()) return '\0';
    char val = dequeArr[rear];
    if (front == rear) {
        front = rear = -1;
    } else {
        rear = (rear - 1 + SIZE) % SIZE;
    }
    return val;
}

bool checkPalindrome(string str) {
    front = rear = -1;
    for (char c : str) {
        if (isalnum(c)) {
            insertRear(tolower(c));
        }
    }
    while (front != -1 && front != rear && (front + 1) % SIZE != rear) {
        char first = deleteFront();
        char last = deleteRear();
        if (first != last)
            return false;
    }
    return true;
}

int main() {
    string input;
    cout << "Enter a string: ";
    getline(cin, input);
    if (checkPalindrome(input))
        cout << "The string is a palindrome.\n";
    else
        cout << "The string is not a palindrome.\n";
    return 0;
}

// Output

/*
    Enter a string: Hello
    The string is not a palindrome.
    [Finished in 3.84s]
*/

/*
    Enter a string: Madam
    The string is a palindrome.
    [Finished in 7.84s]
*/