// Finding the maximum of two integer number using ternary conditional operator

#include <iostream>
using namespace std;

int main() 
{
int Number1, Number2, Maximum;
cout << "Insert the first whole number: ";
cin >> Number1;
cout << "Insert the second whole number: ";
cin >> Number2;
Maximum = Number1 > Number2 ? Number1 : Number2;
cout << "The maximum is: " << Maximum;
return 0;
}