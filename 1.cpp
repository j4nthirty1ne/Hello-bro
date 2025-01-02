/*
1. Create an array to store data any type, you want (such as: int, char, float,...);
2. Create a function to show elements of array;
3. Create a function to insert an element to array to the position, which is input by user;
4. Create a function to delete an element (by position, which is input by user) from array;
5. Create a function to delete all elements with value, which is input by user, from array;
6. Create a function to search (non-duplicate and duplicate) element(s) in array by value, which is input by user.*/

#include <iostream>
using namespace std;

// Function to show elements of array
int studentScores[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};

void showElement()
{
    for (int i = 0; i < 10 && studentScores[i] != 0; i++)
    {
        cout << studentScores[i] << " ";
    }
    cout << endl;
}

void insertElement()
{
    cout << "Enter the position you want to insert: ";
    int position;
    cin >> position;
    if (position < 0 || position >= 10)
    {
        cout << "Invalid position" << endl;
        return;
    }
    cout << "Enter the value you want to insert: ";
    int value;
    cin >> value;
    for (int i = 9; i > position; i--)
    {
        studentScores[i] = studentScores[i - 1];
    }
    studentScores[position] = value;
}
void deleteElement()
{
    cout << "Enter the position you want to delete: ";
    int position;
    cin >> position;
    for (int i = position; i < 10 - 1; i++)
    {
        studentScores[i] = studentScores[i + 1];
    }
    studentScores[10 - 1] = 0; 
}

void deleteAllElements()
{
    cout << "Enter the value you want to delete: ";
    int value;
    cin >> value;
    int newSize = 10;
    for (int i = 0; i < newSize; i++)
    {
        if (studentScores[i] == value)
        {
            for (int j = i; j < newSize - 1; j++)
            {
                studentScores[j] = studentScores[j + 1];
            }
            newSize--;
            i--; 
        }
    }
    
    for (int i = newSize; i < 10; i++)
    {
        studentScores[i] = 0;
    }
}

void searchElement()
{
    cout << "Enter the value you want to search: ";
    int value;
    cin >> value;
    int found = 0;
    for (int i = 0; i < 10; i++)
    {
        if (studentScores[i] == value)
        {
            cout << "Found at position: " << i << endl;
            found = 1;
        }
    }
    if (found == 0)
    {
        cout << "Not found" << endl;
    }
}

void ui ()
{
    int choice;
    do
    {
        cout << "1. Show elements of array" << endl;
        cout << "2. Insert an element" << endl;
        cout << "3. Delete an element" << endl;
        cout << "4. Delete all elements with a specific value" << endl;
        cout << "5. Search for an element" << endl;
        cout << "6. Exit" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            showElement();
            break;
        case 2:
            insertElement();
            break;
        case 3:
            deleteElement();
            break;
        case 4:
            deleteAllElements();
            break;
        case 5:
            searchElement();
            break;
        default:
            cout << "Invalid choice" << endl;
        }
    }
    while (choice != 6);
    showElement(); 
}
int main ()
{
    ui();
    return 0;
}
