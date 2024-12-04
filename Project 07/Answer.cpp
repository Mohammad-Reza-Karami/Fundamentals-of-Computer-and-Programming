// Read two integer numbers (First and Second) and show First and Second such that First will be the maximum.

#include <iostream>
using namespace std;

int main()
{
    // Declaring Variables:
    int First, Second, Temp;
    // Reading First and Second:
    cout << "Enter the First and the Second number: ";
    cin >> First >> Second;
    // Updating First if it is needed:
    if (Second > First)
    {
        Temp = First;
        First = Second;
        Second = Temp;
    }
    // Printing the outputs:
    cout << "First = " << First << endl;
    cout << "Second = " << Second;

    return 0;
}