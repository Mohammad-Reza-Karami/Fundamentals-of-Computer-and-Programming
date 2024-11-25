// Create a integer calculator that includes five operators (+ - * / %)

#include <iostream>
using namespace std;

int main()
{
    // Variable Declaration:
    int Number1, Number2, Answer;
    char Operator;
    
    // Getting the input operation:
    cout << "Enter your operation (space seperated): ";
    
    cin >> Number1 >> Operator >> Number2;
    // switch-case structure:
    switch (Operator)
    {
    case '+':
        Answer = Number1 + Number2;
        cout << Number1 << " + " << Number2 << " = " << Answer ;
        break;

    case '-':
        Answer = Number1 - Number2;
        cout << Number1 << " - " << Number2 << " = " << Answer ;
        break;
    
    case '*':
        Answer = Number1 * Number2;
        cout << Number1 << " * " << Number2 << " = " << Answer ;
        break;

    case '/':
        if (Number2 != 0)
        {
            Answer = Number1 / Number2;
            cout << Number1 << " / " << Number2 << " = " << Answer ;
        }   
        else
            cout << "Error: Division by zero!";
        break;
    
    case '%':
         if (Number2 != 0)
        {
            Answer = Number1 % Number2;
            cout << Number1 << " % " << Number2 << " = " << Answer ;
        }   
        else
            cout << "Error: Division by zero!";
        break;       

    default:
        cout << "Error: Operator " << Operator << " is not valid!";
        break;
    }

    return 0;
}