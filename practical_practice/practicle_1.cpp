#include <iostream>
#include<string>
using namespace std;

#define MAX 15

string movieNames[MAX];
int seatNumbers[MAX];
int totalBookings = 0;

int menu();
void insert();
void update();
void Delete();
void display();

int menu(){
    cout << "Movie Ticket Booking System " << endl;
    cout << "1 -> insert booking " << endl;
    cout << "2 -> Update booking " << endl;
    cout << "3 -> Delete booking " << endl;
    cout << "4 -> Display All Bookings " << endl;
    cout << "5 -> Exit " << endl;
    cout << "\nEnter Your Choice : ";
}
void insert(){
    if(totalBookings >= MAX) {
        cout << "Booking List is Full!!!" <<endl;
        return;
    }
    string movie;
    int seat;

    cout << "Enter Movie name : ";
    cin.ignore();
    getline(cin,movie);

    cout << "Enter seat number : ";
    cin>>seat;

    for (int i = 0; i<totalBookings ; i++){
        if(seatNumbers[i] == seat) cout << "seat already booked !! choose another seat ." << endl; 
    }

    movieNames[totalBookings] = movie;
    seatNumbers[totalBookings] =seat;
    totalBookings++;

    cout << "seat confirmed !! "<<endl;
    
}

void update(){
    if(totalBookings >= MAX) {
        cout << "Booking List is full!! " << endl;
        return;
    }
    
    int seatToupdate;
    cout << "ENter value to update : ";
    cin >> seatToupdate;
    bool found = false;

    for(int i=0; i<totalBookings; i++){
        if(seatNumbers[i] == seatToupdate){
            cout << "Enter a new movie :";
            cin.ignore();
            getline(cin, movieNames[i]);

            cout << "Enter seat no to update :";
            cin >> seatNumbers[i];

            cout << "Booking updated Successfully"<<endl;
            found =true;
            break;
        }
    }
    if(!found) cout << "Booking not found ";
}

void Delete(){
    int seatTodelete;
    cout << "Enter seat no to delete :";
    cin>>seatTodelete;
    bool found = false;

    for (int i =0; i<totalBookings;i++){
        if(seatNumbers[i] == seatTodelete){
            for(int j=i; j<totalBookings-1;j++){
                movieNames[i] = movieNames[i+1];
                seatNumbers[i] = seatNumbers[i+1];
            }
            totalBookings--;
            cout << "Ticket deleted successfully" << endl;
            found = true;
            break;
        }
    }
    if(!found) cout << "Booking not found!!"<<endl;
}

void display(){
    if(totalBookings==0) {
        cout << "No bookings available !!"<<endl;
        return;
    }else{
        cout << " Current Bookings " << endl;
        for(int i=0; i<totalBookings ; i++){
        cout << "Movie no : " << movieNames[i] << " | seat No : " << seatNumbers[i] << endl;
        }
    }
}


int main(int argc, char const *argv[])
{
    int ch;
    do
    {
        ch = menu();
        switch (ch)
        {
        case 1:
            insert();
            break;
        
        case 2:
            update();
            break;
        case 3:
            Delete();
            break;
        case 4:
            display();
            break;
        case 5:
            cout << "Exiting.....!!!"<<endl;
            break;
        default:
        cout << "invalid choice !!"<<endl;
            break;
        }
    } while (ch!=5);
    
    return 0;
}
