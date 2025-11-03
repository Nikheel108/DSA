/*
    -------   Practical no 3.4 : Quick / Merge Sort-------------

    Name : Nikheel C Khadakabhavi
    PRN : 202401110020
    Batch : A1

    -----------------------------------------------
*/

#include <iostream>
using namespace std;

void merge(float arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    float L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < n1)
        arr[k++] = L[i++];

    while (j < n2)
        arr[k++] = R[j++];
}
 
void mergeSort(float arr[], int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void display(float arr[], int n)
{
    if (n == 0)
    {
        cout << "No data available.\n";
        return;
    }
    cout << "Percentages: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "% ";
    }
    cout << endl;
}

int main()
{
    int choice, n = 0;
    float arr[50];

    do
    {
        cout << "\n------ MENU ------\n";
        cout << "1. Enter Percentages\n";
        cout << "2. Display Percentages\n";
        cout << "3. Sort using Merge Sort (Ascending)\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter number of students: ";
            cin >> n;
            if (n <= 0 || n > 50)
            {
                cout << "Invalid number! (1-50 allowed)\n";
                n = 0;
                break;
            }
            cout << "Enter percentages:\n";
            for (int i = 0; i < n; i++)
            {
                cout << "Student " << (i + 1) << ": ";
                cin >> arr[i];
            }
            break;

        case 2:
            display(arr, n);
            break;

        case 3:
            if (n == 0)
            {
                cout << "No data to sort!\n";
            }
            else
            {
                mergeSort(arr, 0, n - 1);
                cout << "Array sorted successfully!\n";
            }
            break;

        case 4:
            cout << "Exiting program...\n";
            break;

        default:
            cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 4);

    return 0;
}

/*Output:
    ------ MENU ------
    1. Enter Percentages
    2. Display Percentages
    3. Sort using Merge Sort (Ascending)
    4. Exit
    Enter your choice: 1
    Enter number of students: 2
    Enter percentages:
    Student 1: 99.52
    Student 2: 89.99

    ------ MENU ------
    1. Enter Percentages
    2. Display Percentages
    3. Sort using Merge Sort (Ascending)
    4. Exit
    Enter your choice: 2
    Percentages: 99.52% 89.99%

    ------ MENU ------
    1. Enter Percentages
    2. Display Percentages
    3. Sort using Merge Sort (Ascending)
    4. Exit
    Enter your choice: 3
    Array sorted successfully!

    ------ MENU ------
    1. Enter Percentages
    2. Display Percentages
    3. Sort using Merge Sort (Ascending)
    4. Exit
    Enter your choice: 4
    Exiting program...
*/
