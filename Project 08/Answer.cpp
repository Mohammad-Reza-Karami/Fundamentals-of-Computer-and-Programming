// Get a positive integer and print nested hollow squares such that the input is the length of the side of the outermost square. (Consider 1x1 square as a hollow one.)

#include <iostream>
#include <tuple>
using namespace std;

tuple <int, int> head_printer (int outermost_square_length) // Prints the first half of the final output.
{
    // Declaring Variables:
    int row_number = 1, string_counter_for_odd_rows = 1, string_counter_for_even_rows;

    // Processing:
    while (row_number <= outermost_square_length / 2)
    {
        if (row_number % 2 == 0)
        {
            // Printing this Line:
            string_counter_for_even_rows = row_number / 2;
            for (int i = 1; i <= string_counter_for_even_rows; i++)
                cout << " *    ";
            for (int i = 1; i <= outermost_square_length - 4 * string_counter_for_even_rows; i++)
                cout << "   ";
            for (int i = 1; i <= string_counter_for_even_rows; i++)
                cout << "    * ";
            cout << endl;
        }
        else
            if (row_number == 1)
            {
                // Printing the First line:
                for (int i = 1; i <= outermost_square_length; i++)
                    cout << " * " ;
                cout << endl;
            }
            else
                {
                    // Printing this Line:
                    for (int i = 1; i <= string_counter_for_odd_rows; i++)
                        cout << " *    ";
                    for (int i = 1; i <= outermost_square_length - 4 * string_counter_for_odd_rows; i++)
                        cout << " * ";
                    for (int i = 1; i <= string_counter_for_odd_rows; i++)
                        cout << "    * ";
                    cout << endl;
                    // Updating string_counter_for_odd_rows when is needed:
                    if (row_number != outermost_square_length / 2)
                        string_counter_for_odd_rows += 1;
                }
        row_number += 1;     
    }
    return make_tuple (string_counter_for_even_rows, string_counter_for_odd_rows); // Since we want to return more than one thing, we use a tuple.
}

void printer_type_zero(int outermost_square_length) // For when user inputs a 4K number (K is an integer)
{
    // Declaring Variables:
    int string_counter_for_even_rows, string_counter_for_odd_rows, row_number_of_tail = 0;
    
    // Printing the first Half of the Final Output:
    tie (string_counter_for_even_rows, string_counter_for_odd_rows) = head_printer(outermost_square_length);

    // Printing the Second Half of the Final Output:
    while (row_number_of_tail <= outermost_square_length / 2 - 1)
    {
        if (row_number_of_tail == 0) 
        {
            // Printing the First Line of the Second Half of the Final Output:
            for (int i = 1; i <= string_counter_for_even_rows; i++)
                cout << " *    ";
            for (int i = 1; i <= outermost_square_length - 4 * string_counter_for_even_rows; i++)
                cout << "   ";
            for (int i = 1; i <= string_counter_for_even_rows; i++)
                cout << "    * ";
            cout << endl;
        }
        else if (row_number_of_tail % 2 == 0)
        {
            string_counter_for_even_rows -= 1;
            // Printing this Line:
            for (int i = 1; i <= string_counter_for_even_rows; i++)
                cout << " *    ";
            for (int i = 1; i <= outermost_square_length - 4 * string_counter_for_even_rows; i++)
                cout << "   ";
            for (int i = 1; i <= string_counter_for_even_rows; i++)
                cout << "    * ";
            cout << endl;
        }
        else
        {
            string_counter_for_odd_rows -= 1;
            // Printing this line:
            for (int i = 1; i <= string_counter_for_odd_rows; i++)
                cout << " *    ";
            for (int i = 1; i <= outermost_square_length - 4 * string_counter_for_odd_rows; i++)
                cout << " * ";
            for (int i = 1; i <= string_counter_for_odd_rows; i++)
                cout << "    * ";
            cout << endl;
        }
        row_number_of_tail += 1;
    }
}

void printer_type_one(int outermost_square_length) // For when user inputs a 4K+1 number (K is an integer)
{
    // Declaring Variables:
    int string_counter_for_even_rows, string_counter_for_odd_rows, row_number_of_tail = 0;
    
    // Printing the first Part of the Final Output:
    tie (string_counter_for_even_rows, string_counter_for_odd_rows) = head_printer(outermost_square_length);

    // Printing the Middle Line of the Final Output:
    for (int i = 1; i <= string_counter_for_even_rows; i++)
        cout << " *    ";
    for (int i = 1; i <= (outermost_square_length - 4 * string_counter_for_even_rows - 1) / 2; i++)
        cout << "   ";
    cout << " * ";
    for (int i = 1; i <= (outermost_square_length - 4 * string_counter_for_even_rows - 1) / 2; i++)
        cout << "   ";
    for (int i = 1; i <= string_counter_for_even_rows; i++)
        cout << "    * ";
    cout << endl;

    // Printing the Last Lines of the Final Output:
    while (row_number_of_tail <= outermost_square_length / 2 - 1)
    {
        if (row_number_of_tail == 0) 
        {
            for (int i = 1; i <= string_counter_for_even_rows; i++)
                cout << " *    ";
            for (int i = 1; i <= outermost_square_length - 4 * string_counter_for_even_rows; i++)
                cout << "   ";
            for (int i = 1; i <= string_counter_for_even_rows; i++)
                cout << "    * ";
            cout << endl;
        }
        else if (row_number_of_tail % 2 == 0)
        {
            string_counter_for_even_rows -= 1;
            for (int i = 1; i <= string_counter_for_even_rows; i++)
                cout << " *    ";
            for (int i = 1; i <= outermost_square_length - 4 * string_counter_for_even_rows; i++)
                cout << "   ";
            for (int i = 1; i <= string_counter_for_even_rows; i++)
                cout << "    * ";
            cout << endl;
        }
        else
        {
            string_counter_for_odd_rows -= 1;
            for (int i = 1; i <= string_counter_for_odd_rows; i++)
                cout << " *    ";
            for (int i = 1; i <= outermost_square_length - 4 * string_counter_for_odd_rows; i++)
                cout << " * ";
            for (int i = 1; i <= string_counter_for_odd_rows; i++)
                cout << "    * ";
            cout << endl;
        }
        row_number_of_tail += 1;
    }
}

void printer_type_two(int outermost_square_length) // For when user inputs a 4K+2 number (K is an integer)
{
    // Declaring Variables:
    int string_counter_for_even_rows, string_counter_for_odd_rows, row_number_of_tail = 1;
    
    // Printing the first Half of the Final Output:
    tie (string_counter_for_even_rows, string_counter_for_odd_rows) = head_printer(outermost_square_length);

    // Printing the Second Half of the Final Output:
    while (row_number_of_tail <= outermost_square_length / 2)
    {
        if (row_number_of_tail == 1)
        {
            for (int i = 1; i <= string_counter_for_odd_rows; i++)
                cout << " *    ";
            for (int i = 1; i <= outermost_square_length - 4 * string_counter_for_odd_rows; i++)
                cout << " * ";
            for (int i = 1; i <= string_counter_for_odd_rows; i++)
                cout << "    * ";
            cout << endl;
        }
        else if (row_number_of_tail % 2 == 0)
        {
            for (int i = 1; i <= string_counter_for_even_rows; i++)
                cout << " *    ";
            for (int i = 1; i <= outermost_square_length - 4 * string_counter_for_even_rows; i++)
                cout << "   ";
            for (int i = 1; i <= string_counter_for_even_rows; i++)
                cout << "    * ";
            cout << endl;
            string_counter_for_even_rows -= 1;
        }
        else
        {
            string_counter_for_odd_rows -= 1;
            for (int i = 1; i <= string_counter_for_odd_rows; i++)
                cout << " *    ";
            for (int i = 1; i <= outermost_square_length - 4 * string_counter_for_odd_rows; i++)
                cout << " * ";
            for (int i = 1; i <= string_counter_for_odd_rows; i++)
                cout << "    * ";
            cout << endl;
        }
        row_number_of_tail += 1;
    }
}

void printer_type_three(int outermost_square_length) // For when user inputs a 4K+3 number (K is an integer)
{
    // Declaring Variables:
    int string_counter_for_even_rows, string_counter_for_odd_rows, row_number_of_tail = 0;
    
    // Printing the first Part of the Final Output:
    tie (string_counter_for_even_rows, string_counter_for_odd_rows) = head_printer(outermost_square_length);

    // Printing the Middle Lines of the Final Output:
        // Printing the First Middle Line:
    for (int i = 1; i <= string_counter_for_odd_rows; i++)
        cout << " *    ";
    for (int i = 1; i <= outermost_square_length - 4 * string_counter_for_odd_rows - 2; i++)
        cout << " * ";   
    cout << "   ";
    cout << " * ";
    for (int i = 1; i <= string_counter_for_odd_rows; i++)
        cout << "    * ";
    cout << endl;
        // Printing the Second Middle Line:
    for (int i = 1; i <= string_counter_for_odd_rows; i++)
        cout << " *    ";
    for (int i = 1; i <= outermost_square_length - 4 * string_counter_for_odd_rows; i++)
        cout << " * ";   
    for (int i = 1; i <= string_counter_for_odd_rows; i++)
        cout << "    * ";
    cout << endl;

    // Printing the Last Lines of the Final Output:
    while (row_number_of_tail <= outermost_square_length / 2 - 2)
    {
        if (row_number_of_tail == 0) 
        {
            for (int i = 1; i <= string_counter_for_even_rows; i++)
                cout << " *    ";
            for (int i = 1; i <= outermost_square_length - 4 * string_counter_for_even_rows; i++)
                cout << "   ";
            for (int i = 1; i <= string_counter_for_even_rows; i++)
                cout << "    * ";
            cout << endl;
        }
        else if (row_number_of_tail % 2 == 0)
        {
            string_counter_for_even_rows -= 1;
            for (int i = 1; i <= string_counter_for_even_rows; i++)
                cout << " *    ";
            for (int i = 1; i <= outermost_square_length - 4 * string_counter_for_even_rows; i++)
                cout << "   ";
            for (int i = 1; i <= string_counter_for_even_rows; i++)
                cout << "    * ";
            cout << endl;
        }
        else
        {
            string_counter_for_odd_rows -= 1;
            for (int i = 1; i <= string_counter_for_odd_rows; i++)
                cout << " *    ";
            for (int i = 1; i <= outermost_square_length - 4 * string_counter_for_odd_rows; i++)
                cout << " * ";
            for (int i = 1; i <= string_counter_for_odd_rows; i++)
                cout << "    * ";
            cout << endl;
        }
        row_number_of_tail += 1;
    }
}

int main()
{
    // Declaring Variable:
    int outermost_square_length;

    // Getting and Storing the User Input:
    cout << "Please enter a positive integer: ";
    cin >> outermost_square_length;
    cout << endl;

    // Processing:
        // For outermost_square_length < 4:
    if (outermost_square_length == 1)
        cout << " * " << endl;
    else if (outermost_square_length == 2)
        cout << " *  * " << endl << " *  * " << endl;
    else if (outermost_square_length == 3)
        cout << " *  *  * " << endl << " *     * " << endl << " *  *  * " << endl;
    else
        {
            // For outermost_square_length >= 4:
            if (outermost_square_length % 4 == 0)
                printer_type_zero(outermost_square_length);
            else if (outermost_square_length % 4 == 1)
                printer_type_one(outermost_square_length);
            else if (outermost_square_length % 4 == 2)
                printer_type_two(outermost_square_length);
            else
                printer_type_three(outermost_square_length);
        }

    return 0;
}
