#include <iostream>
#include <string>
using namespace std;

struct Song {
    string title;
    Song* next;
};

Song* head = NULL;


Song* createSong(string title) {
    Song* newSong = new Song();
    newSong->title = title;
    newSong->next = newSong; 
    return newSong;
}


void insertAtBegin(string title) {
    Song* newSong = createSong(title);
    if (head == NULL) {
        head = newSong;
    } else {
        Song* temp = head;
        while (temp->next != head)
            temp = temp->next;
        temp->next = newSong;
        newSong->next = head;
        head = newSong;
    }
    cout << "Song added at the beginning: " << title << endl;
}


void insertAtLast(string title) {
    Song* newSong = createSong(title);
    if (head == NULL) {
        head = newSong;
    } else {
        Song* temp = head;
        while (temp->next != head)
            temp = temp->next;
        temp->next = newSong;
        newSong->next = head;
    }
    cout << "Song added at the end: " << title << endl;
}


void deleteBegin() {
    if (head == NULL) {
        cout << "Playlist is empty!\n";
        return;
    }

    Song* temp = head;
    if (head->next == head) { 
        head = NULL;
    } else {
        Song* last = head;
        while (last->next != head)
            last = last->next;
        last->next = head->next;
        head = head->next;
    }
    cout << "Deleted song: " << temp->title << endl;
    delete temp;
}


void deleteLast() {
    if (head == NULL) {
        cout << "Playlist is empty!\n";
        return;
    }

    Song* temp = head;
    if (head->next == head) {
        cout << "Deleted song: " << head->title << endl;
        delete head;
        head = NULL;
        return;
    }

    Song* prev = NULL;
    while (temp->next != head) {
        prev = temp;
        temp = temp->next;
    }
    prev->next = head;
    cout << "Deleted song: " << temp->title << endl;
    delete temp;
}

// Display all songs
void displayList() {
    if (head == NULL) {
        cout << "Playlist is empty!\n";
        return;
    }

    cout << "\n--- Music Playlist ---\n";
    Song* temp = head;
    do {
        cout << temp->title << endl;
        temp = temp->next;
    } while (temp != head);
}


void searchSong(string title) {
    if (head == NULL) {
        cout << "Playlist is empty!\n";
        return;
    }

    Song* temp = head;
    int pos = 1;
    do {
        if (temp->title == title) {
            cout << "Song found at position " << pos << ": " << title << endl;
            return;
        }
        temp = temp->next;
        pos++;
    } while (temp != head);

    cout << "Song not found: " << title << endl;
}


void reverseList() {
    if (head == NULL || head->next == head) {
        cout << "Not enough songs to reverse.\n";
        return;
    }

    Song *prev = NULL, *current = head, *next = NULL;
    Song* tail = head;

    do {
        tail = tail->next;
    } while (tail->next != head);

    do {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    } while (current != head);

    head->next = prev;
    head = prev;
    tail->next = head;

    cout << "Playlist reversed successfully!\n";
}




int main() {
    int choice;
    string title;

    do {
        cout << "\n===== Music Playlist Menu =====\n";
        cout << "1. Insert Song at Beginning\n";
        cout << "2. Insert Song at End\n";
        cout << "3. Delete Song from Beginning\n";
        cout << "4. Delete Song from End\n";
        cout << "5. Search Song\n";
        cout << "6. Reverse Playlist\n";
        cout << "7. Display Playlist\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter song title: ";
                cin.ignore();
                getline(cin, title);
                insertAtBegin(title);
                break;

            case 2:
                cout << "Enter song title: ";
                cin.ignore();
                getline(cin, title);
                insertAtLast(title);
                break;

            case 3:
                deleteBegin();
                break;

            case 4:
                deleteLast();
                break;

            case 5:
                cout << "Enter song title to search: ";
                cin.ignore();
                getline(cin, title);
                searchSong(title);
                break;

            case 6:
                reverseList();
                break;

            case 7:
                displayList();
                break;

            case 8:
                cout << "Exiting Music Playlist. Goodbye!\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 8);
    return 0;
}

/*
    output:
    ===== Music Playlist Menu =====
    1. Insert Song at Beginning
    2. Insert Song at End
    3. Delete Song from Beginning
    4. Delete Song from End
    5. Search Song
    6. Reverse Playlist
    7. Display Playlist
    8. Exit
    Enter your choice: 1
    Enter song title: tu hai kaha
    Song added at the beginning: tu hai kaha

    ===== Music Playlist Menu =====
    1. Insert Song at Beginning
    2. Insert Song at End
    3. Delete Song from Beginning
    4. Delete Song from End
    5. Search Song
    6. Reverse Playlist
    7. Display Playlist
    8. Exit
    Enter your choice: 2
    Enter song title: happy birthday
    Song added at the end: happy birthday

    ===== Music Playlist Menu =====
    1. Insert Song at Beginning
    2. Insert Song at End
    3. Delete Song from Beginning
    4. Delete Song from End
    5. Search Song
    6. Reverse Playlist
    7. Display Playlist
    8. Exit
    Enter your choice: 3
    Deleted song: tu hai kaha

    ===== Music Playlist Menu =====
    1. Insert Song at Beginning
    2. Insert Song at End
    3. Delete Song from Beginning
    4. Delete Song from End
    5. Search Song
    6. Reverse Playlist
    7. Display Playlist
    8. Exit
    Enter your choice: 4
    Deleted song: happy birthday

    ===== Music Playlist Menu =====
    1. Insert Song at Beginning
    2. Insert Song at End
    3. Delete Song from Beginning
    4. Delete Song from End
    5. Search Song
    6. Reverse Playlist
    7. Display Playlist
    8. Exit
    Enter your choice: 5
    Enter song title to search: tu hai kaha
    Playlist is empty!

    ===== Music Playlist Menu =====
    1. Insert Song at Beginning
    2. Insert Song at End
    3. Delete Song from Beginning
    4. Delete Song from End
    5. Search Song
    6. Reverse Playlist
    7. Display Playlist
    8. Exit
    Enter your choice: 1
    Enter song title: tu hai kaha
    Song added at the beginning: tu hai kaha

    ===== Music Playlist Menu =====
    1. Insert Song at Beginning
    2. Insert Song at End
    3. Delete Song from Beginning
    4. Delete Song from End
    5. Search Song
    6. Reverse Playlist
    7. Display Playlist
    8. Exit
    Enter your choice: 1
    Enter song title: ye dil hai mushkil
    Song added at the beginning: ye dil hai mushkil

    ===== Music Playlist Menu =====
    1. Insert Song at Beginning
    2. Insert Song at End
    3. Delete Song from Beginning
    4. Delete Song from End
    5. Search Song
    6. Reverse Playlist
    7. Display Playlist
    8. Exit
    Enter your choice: 6
    Playlist reversed successfully!

    ===== Music Playlist Menu =====
    1. Insert Song at Beginning
    2. Insert Song at End
    3. Delete Song from Beginning
    4. Delete Song from End
    5. Search Song
    6. Reverse Playlist
    7. Display Playlist
    8. Exit
    Enter your choice: 7

    --- Music Playlist ---
    tu hai kaha

    ===== Music Playlist Menu =====
    1. Insert Song at Beginning
    2. Insert Song at End
    3. Delete Song from Beginning
    4. Delete Song from End
    5. Search Song
    6. Reverse Playlist
    7. Display Playlist
    8. Exit
    Enter your choice: 8
    Exiting Music Playlist. Goodbye!
*/
