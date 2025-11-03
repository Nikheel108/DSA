#include <iostream>
#include <string>
using namespace std;


struct Reservation {
    int seatNumber;
    string passengerName;
    Reservation* prev;
    Reservation* next;
};

Reservation* head = NULL;


Reservation* createNode(int seatNumber, string name) {
    Reservation* newNode = new Reservation();
    newNode->seatNumber = seatNumber;
    newNode->passengerName = name;
    newNode->prev = newNode->next = NULL;
    return newNode;
}


void addAtBegin(int seatNumber, string name) {
    Reservation* newNode = createNode(seatNumber, name);
    if (head == NULL) {
        head = newNode;
        cout << "Reservation added at the beginning.\n";
        return;
    }
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
    cout << "Reservation added at the beginning.\n";
}


void addAtLast(int seatNumber, string name) {
    Reservation* newNode = createNode(seatNumber, name);
    if (head == NULL) {
        head = newNode;
        cout << "Reservation added at the end.\n";
        return;
    }
    Reservation* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
    cout << "Reservation added at the end.\n";
}


void addAtPosition(int pos, int seatNumber, string name) {
    Reservation* newNode = createNode(seatNumber, name);
    if (pos <= 1 || head == NULL) {
        addAtBegin(seatNumber, name);
        return;
    }
    Reservation* temp = head;
    for (int i = 1; i < pos - 1 && temp->next != NULL; i++)
        temp = temp->next;
    newNode->next = temp->next;
    if (temp->next != NULL)
        temp->next->prev = newNode;
    temp->next = newNode;
    newNode->prev = temp;
    cout << "Reservation added at position " << pos << ".\n";
}


void displayAllReservations() {
    if (head == NULL) {
        cout << "No reservations found.\n";
        return;
    }
    cout << "\n--- Current Reservations ---\n";
    Reservation* temp = head;
    while (temp != NULL) {
        cout << "Seat No: " << temp->seatNumber << " | Passenger: " << temp->passengerName << endl;
        temp = temp->next;
    }
}


void cancelReservation(int pos) {
    if (head == NULL) {
        cout << "No reservations to cancel.\n";
        return;
    }

    Reservation* temp = head;

    if (pos == 1) {
        head = head->next;
        if (head != NULL)
            head->prev = NULL;
        delete temp;
        cout << "First reservation cancelled.\n";
        return;
    }

    for (int i = 1; i < pos && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) {
        cout << "Invalid position!\n";
        return;
    }

    if (temp->next != NULL)
        temp->next->prev = temp->prev;
    if (temp->prev != NULL)
        temp->prev->next = temp->next;

    delete temp;
    cout << "Reservation cancelled at position " << pos << ".\n";
}


void sortReservations() {
    if (head == NULL || head->next == NULL) return;

    for (Reservation* i = head; i != NULL; i = i->next) {
        for (Reservation* j = i->next; j != NULL; j = j->next) {
            if (i->seatNumber > j->seatNumber) {
                swap(i->seatNumber, j->seatNumber);
                swap(i->passengerName, j->passengerName);
            }
        }
    }
    cout << "Reservations sorted by seat number.\n";
}


void reverseDisplay() {
    if (head == NULL) {
        cout << "No reservations to display.\n";
        return;
    }
    cout << "\n--- Reservations in Reverse Order ---\n";
    Reservation* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    while (temp != NULL) {
        cout << "Seat No: " << temp->seatNumber << " | Passenger: " << temp->passengerName << endl;
        temp = temp->prev;
    }
}


int main() {
    int choice, seatNumber, pos;
    string name;

    do {
        cout << "\n===== Train Reservation System =====\n";
        cout << "1. Add Reservation at Beginning\n";
        cout << "2. Add Reservation at End\n";
        cout << "3. Add Reservation at Position\n";
        cout << "4. Display All Reservations\n";
        cout << "5. Cancel Reservation\n";
        cout << "6. Sort Reservations by Seat Number\n";
        cout << "7. Display Reservations in Reverse\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Seat Number: ";
                cin >> seatNumber;
                cout << "Enter Passenger Name: ";
                cin.ignore();
                getline(cin, name);
                addAtBegin(seatNumber, name);
                break;

            case 2:
                cout << "Enter Seat Number: ";
                cin >> seatNumber;
                cout << "Enter Passenger Name: ";
                cin.ignore();
                getline(cin, name);
                addAtLast(seatNumber, name);
                break;

            case 3:
                cout << "Enter Position: ";
                cin >> pos;
                cout << "Enter Seat Number: ";
                cin >> seatNumber;
                cout << "Enter Passenger Name: ";
                cin.ignore();
                getline(cin, name);
                addAtPosition(pos, seatNumber, name);
                break;

            case 4:
                displayAllReservations();
                break;

            case 5:
                cout << "Enter position to cancel: ";
                cin >> pos;
                cancelReservation(pos);
                break;

            case 6:
                sortReservations();
                break;

            case 7:
                reverseDisplay();
                break;

            case 8:
                cout << "Exiting... Thank you!\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 8);
    return 0;
}

/*
    output:
    ===== Train Reservation System =====
    1. Add Reservation at Beginning
    2. Add Reservation at End
    3. Add Reservation at Position
    4. Display All Reservations
    5. Cancel Reservation
    6. Sort Reservations by Seat Number
    7. Display Reservations in Reverse
    8. Exit
    Enter your choice: 1
    Enter Seat Number: 24
    Enter Passenger Name: Nikheel
    Reservation added at the beginning.

    ===== Train Reservation System =====
    1. Add Reservation at Beginning
    2. Add Reservation at End
    3. Add Reservation at Position
    4. Display All Reservations
    5. Cancel Reservation
    6. Sort Reservations by Seat Number
    7. Display Reservations in Reverse
    8. Exit
    Enter your choice: 2
    Enter Seat Number: 29
    Enter Passenger Name: Hello
    Reservation added at the end.

    ===== Train Reservation System =====
    1. Add Reservation at Beginning
    2. Add Reservation at End
    3. Add Reservation at Position
    4. Display All Reservations
    5. Cancel Reservation
    6. Sort Reservations by Seat Number
    7. Display Reservations in Reverse
    8. Exit
    Enter your choice: 3
    Enter Position: 1
    Enter Seat Number: 36
    Enter Passenger Name: swapnil
    Reservation added at the beginning.

    ===== Train Reservation System =====
    1. Add Reservation at Beginning
    2. Add Reservation at End
    3. Add Reservation at Position
    4. Display All Reservations
    5. Cancel Reservation
    6. Sort Reservations by Seat Number
    7. Display Reservations in Reverse
    8. Exit
    Enter your choice: 4

    --- Current Reservations ---
    Seat No: 36 | Passenger: swapnil
    Seat No: 24 | Passenger: Nikheel
    Seat No: 29 | Passenger: Hello

    ===== Train Reservation System =====
    1. Add Reservation at Beginning
    2. Add Reservation at End
    3. Add Reservation at Position
    4. Display All Reservations
    5. Cancel Reservation
    6. Sort Reservations by Seat Number
    7. Display Reservations in Reverse
    8. Exit
    Enter your choice: 5
    Enter position to cancel: 3
    Reservation cancelled at position 3.

    ===== Train Reservation System =====
    1. Add Reservation at Beginning
    2. Add Reservation at End
    3. Add Reservation at Position
    4. Display All Reservations
    5. Cancel Reservation
    6. Sort Reservations by Seat Number
    7. Display Reservations in Reverse
    8. Exit
    Enter your choice: 6
    Reservations sorted by seat number.

    ===== Train Reservation System =====
    1. Add Reservation at Beginning
    2. Add Reservation at End
    3. Add Reservation at Position
    4. Display All Reservations
    5. Cancel Reservation
    6. Sort Reservations by Seat Number
    7. Display Reservations in Reverse
    8. Exit
    Enter your choice: 7

    --- Reservations in Reverse Order ---
    Seat No: 36 | Passenger: swapnil
    Seat No: 24 | Passenger: Nikheel

    ===== Train Reservation System =====
    1. Add Reservation at Beginning
    2. Add Reservation at End
    3. Add Reservation at Position
    4. Display All Reservations
    5. Cancel Reservation
    6. Sort Reservations by Seat Number
    7. Display Reservations in Reverse
    8. Exit
    Enter your choice: 8
    Exiting... Thank you!
*/