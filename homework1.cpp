#include <iostream>
using namespace std;

int array[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};

void showElement()
{
    for (int i = 0; i < 10 && array[i] != 0; i++)
    {
        cout << array[i] << " ";
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
        array[i] = array[i - 1]; 
    }
    array[position] = value;
    showElement();
    cout << "Successfully completed" << endl;
}
void deleteElement()
{
    cout << "Enter the position you want to delete: ";
    int position;
    cin >> position;
    for (int i = position; i < 9; i++) // 9 is size array
    {
        array[i] = array[i + 1]; // shift the elements to left
    }
    array[10 - 1] = 0; // remove last element
    if (position < 0 || position >= 10) 
    {
        cout << "Invalid position" << endl;
        return;
    }
    else 
    {
        showElement();
        cout << "Successfully completed" << endl;
    }
}

void deleteAllElements()
{
    cout << "Enter the value you want to delete: ";
    int value;
    cin >> value;
    int newSize = 10;
    for (int i = 0; i < newSize; i++) 
    {
        if (array[i] == value) // if the value is found
        {
            for (int j = i; j < newSize - 1; j++) 
            {
                array[j] = array[j + 1]; 
            }
            newSize--; // decrease size of array
            i--; // decrease index
        }
    }
    
    for (int i = newSize; i < 10; i++) 
    {
        array[i] = 0; // remove the rest of the elements
    }
    showElement();
    cout << "Successfully completed" << endl;
}

void searchElement()
{
    cout << "Enter the value you want to search: ";
    int value;
    cin >> value;
    int found = 0;
    for (int i = 0; i < 10; i++)
    {
        if (array[i] == value) 
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
        cout << "============================================="<< endl;
        cout << "1. Show elements of array" << endl;
        cout << "2. Insert an element" << endl;
        cout << "3. Delete an element" << endl;
        cout << "4. Delete all elements with a specific value" << endl;
        cout << "5. Search for an element" << endl;
        cout << "6. Exit" << endl;
        cout << "============================================="<< endl;
        cout << "Choose an option: ";
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
        case 6:
            cout << "Bye Bye!!!" << endl;
            break;
        default:
            cout << "Invalid choice" << endl;
        }
    }
    
    while (choice != 6);
}
int main ()
{
    system ("cls");
    ui();
    return 0;
}
