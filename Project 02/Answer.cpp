// Finding the absolute value of a given whole number

#include <iostream>
using namespace std;

int main()
{
int Number, Absolute_Value;
cout << "Enter a whole number: ";
cin >> Number;
Absolute_Value = Number;
if (Number < 0)
Absolute_Value = -Number;
cout << "The absolute value = " << Absolute_Value;
return 0;
}