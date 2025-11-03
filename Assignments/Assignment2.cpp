/* 
	-------   Practical no 2 : Hashing  ----------

	Name : Nikheel C Khadakabhavi
	PRN : 202401110020
	Batch : A1

	----------------------------------------------
*/

#include<iostream>
using namespace std;

const int totalSpots = 10;
int parking_Slot[totalSpots];
int carNum;
int count_book = 0;


void menu();
int linear_Probing();
void parking_Slot_init();
void car_Park();
void remove_parked_car();
void search_Car();
void display_parking_Slot();

void Menu() {
    cout << "\n----- Self Parking Lot Menu (Using Linear Probing) -----" << endl;
    cout << "	1. Park a car" << endl;
    cout << "	2. Remove a car" << endl;
    cout << "	3. Search for a car" << endl;
    cout << "	4. Display Parking Lot" << endl;
    cout << "	5. Exit\n";
    cout << "--------------------------------------------------------" << endl;
    cout << "Enter your choice: ";
}

int linear_Probing() { return carNum % totalSpots;	}

void parking_Slot_init() {
  	for (int i = 0; i < totalSpots; i++) parking_Slot[i] = -1;
    cout << "Parking Lot Initialized.\n";    
}

void display_parking_Slot() {
    for (int i = 0; i < totalSpots; i++)
    {
        if(parking_Slot[i] != -1)
            cout << "Slot " << i+1 << ": Car " << parking_Slot[i] << endl;
        else
            cout << "Slot " << i+1 << ": Empty" << endl;
    }
    
    cout << "\n" << count_book << " car parked.\n";
    cout << "Remaining " << totalSpots - count_book << " slot.\n";
}

void car_Park() {
    cout << "Enter Car registration number to Park: ";
    cin >> carNum;

    int index = linear_Probing();
    int starting_index = index;

    do {
        if (parking_Slot[index] == -1) {
            parking_Slot[index] = carNum;
            count_book++;
            cout << "Car " << carNum << " parked at slot " << index+1 << endl;
            return;  
        } else {
            cout << "Collision! Slot " << index+1 
                 << " occupied by Car " << parking_Slot[index] << endl;
            index = (index + 1) % totalSpots;
        }
    } while (index != starting_index);

    cout << "Parking lot full! Could not park car " << carNum << endl;
}

void remove_parked_car() {
    int num, found = 0;
    cout << "Enter Car registration number to remove: ";
    cin >> num;

    for (int i = 0; i < totalSpots; i++) {
        if (parking_Slot[i] == num) {
            parking_Slot[i] = -1;
            count_book--;
            cout << "Car " << num << " removed. Slot " << i+1 << " is now free.\n";
            found = 1;
            break;
        }
    }
    if (!found) cout << "Car " << num << " not found in the lot.\n";
}

void search_Car() {
    int num, found = 0;
    cout << "Enter Car registration number to search: ";
    cin >> num;

    for (int i = 0; i < totalSpots; i++) {
        if (parking_Slot[i] == num) {
            cout << "Car " << num << " is parked at slot " << i+1 << ".\n";
            found = 1;
            break;
        }
    }
    if (!found) cout << "Car " << num << " not found in the lot.\n";
}

int main() {
    parking_Slot_init();
    int choice;
    do {
        Menu();
        cin >> choice;
        switch(choice) {
            case 1: car_Park(); break;
            case 2: remove_parked_car(); break;
            case 3: search_Car(); break;
            case 4: display_parking_Slot(); break;
            case 5: cout << "Thank you for using Self Parking Lot!\n"; break;
            default: cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 5);

    return 0;
}


/*
    Parking Lot Initialized.

    ----- Self Parking Lot Menu (Using Linear Probing) -----
            1. Park a car
            2. Remove a car
            3. Search for a car
            4. Display Parking Lot
            5. Exit
    --------------------------------------------------------
    Enter your choice: 1
    Enter Car registration number to Park: 1080
    Car 1080 parked at slot 1

    ----- Self Parking Lot Menu (Using Linear Probing) -----
            1. Park a car
            2. Remove a car
            3. Search for a car
            4. Display Parking Lot
            5. Exit
    --------------------------------------------------------
    Enter your choice: 1
    Enter Car registration number to Park: 2344
    Car 2344 parked at slot 5

    ----- Self Parking Lot Menu (Using Linear Probing) -----
            1. Park a car
            2. Remove a car
            3. Search for a car
            4. Display Parking Lot
            5. Exit
    --------------------------------------------------------
    Enter your choice: 3444
    Invalid choice! Try again.

    ----- Self Parking Lot Menu (Using Linear Probing) -----
            1. Park a car
            2. Remove a car
            3. Search for a car
            4. Display Parking Lot
            5. Exit
    --------------------------------------------------------
    Enter your choice: 1
    Enter Car registration number to Park: 3444
    Collision! Slot 5 occupied by Car 2344
    Car 3444 parked at slot 6

    ----- Self Parking Lot Menu (Using Linear Probing) -----
            1. Park a car
            2. Remove a car
            3. Search for a car
            4. Display Parking Lot
            5. Exit
    --------------------------------------------------------
    Enter your choice: 2
    Enter Car registration number to remove: 1234
    Car 1234 not found in the lot.

    ----- Self Parking Lot Menu (Using Linear Probing) -----
            1. Park a car
            2. Remove a car
            3. Search for a car
            4. Display Parking Lot
            5. Exit
    --------------------------------------------------------
    Enter your choice: 3
    Enter Car registration number to search: 3444
    Car 3444 is parked at slot 6.

    ----- Self Parking Lot Menu (Using Linear Probing) -----
            1. Park a car
            2. Remove a car
            3. Search for a car
            4. Display Parking Lot
            5. Exit
    --------------------------------------------------------
    Enter your choice: 4

    Slot: 1 2 3 4 5 6 7 8 9 10
    Car : 1080 -1 -1 -1 2344 3444 -1 -1 -1 -1
    3 car parked.
    Remaining 7 slot.

    ----- Self Parking Lot Menu (Using Linear Probing) -----
            1. Park a car
            2. Remove a car
            3. Search for a car
            4. Display Parking Lot
            5. Exit
    --------------------------------------------------------
    Enter your choice: 5
    Thank you for using Self Parking Lot!
*/
