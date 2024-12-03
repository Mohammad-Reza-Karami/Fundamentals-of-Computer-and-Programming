// Read an integer number and show the next even number.

#include <iostream>
using namespace std;

int main()
{
    // Declaring Variables:
    int Input_Number, Next_Even_Number;
    // Reading Input_Number:
    cout << "Enter an integer number: ";
    cin >> Input_Number;
    // Determining Next_Even_Number:
    if (Input_Number % 2 == 0) //Checking if Input_Number is even
        Next_Even_Number = Input_Number + 2;
    else
        Next_Even_Number = Input_Number + 1;
    // Printing the output:
    cout << "The next even number is: " << Next_Even_Number;

    return 0;
}