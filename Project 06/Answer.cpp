/* Implement the following function:
f(x) =
-2                  ; x = 0
x^3 + 2             ; x < 0
2x^3 - 2x + 1       ; x > 0
*/

#include <iostream>
using namespace std;

int main()
{
    // Declaring Variables:
    float x, fx;
    // Reading x:
    cout << "Enter x: ";
    cin >> x;
    // Calculating fx:
    if (x == 0)
        fx = -2;
    else if (x < 0)
        fx = x * x * x + 2;
    else
        fx = 2 * x * x * x - 2 * x + 1;
    // Printing the output:
    cout << "f(" << x << ") = " << fx;

    return 0;
}