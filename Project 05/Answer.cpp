// Read an integer number and show it is Odd or Even.

#include <iostream>
using namespace std;

int main()
{
    // Declaring Variable:
    int Input_Number;
    // Reading Input_Number:
    cout << "Enter an integer number: ";
    cin >> Input_Number;
    // Determining that Input_Number is Even or Odd:
    if (Input_Number % 2 == 0) //Checking if Input_Number is even
        cout << Input_Number <<" is Even.";
    else
        cout << Input_Number <<" is Odd.";

    return 0;
}