// Get name, student I.D. and grades of 5 courses (with the same weights) for 3 students and sort them based on averages or one of the course grades.

#include <iostream>

using namespace std;

// Global Variable:
string Information [3] [8];

bool is_numeric(string String)
{
    int dot_counter = 0;
    for (int i = 0; i < String.length(); i++)
    {
        if (String [i] == '.')
            dot_counter += 1;
        if ((!isdigit(String [i]) && String [i] != '.') || dot_counter > 1) // We must have 1 dot character, at most (if the String is supposed to be a float number).
            return false;
    }
    return true;
}

bool is_grade_valid(string string_grade)
{
    float Grade;

    // Chcking if the string_grade is numeric or not:
    if (!is_numeric(string_grade))
        return false;

    // Here, string is numeric. So we should check if it is in range [0, 20] or not:
    Grade = stof(string_grade);
    if (Grade >= 0 && Grade <= 20)
        return true;

    // Here, string is numeric and it is not in range [0, 20]:
    return false;
}

bool is_option_valid(string Option)
{
    for (int i = 1; i <= 6; i++)
        if (to_string(i) == Option)
            return true;

    return false;    
}

void get_and_store_information()
{
    cout << endl;
    for (int i = 0; i < 3 ; i++)
    {

        cout << "Student " << i + 1 << " of 3" << endl;

        cout << "Name:                    ";
        getline(cin >> ws, Information [i] [0]);

        cout << "Student ID:              ";
        cin >> Information [i] [1];
        while (!is_numeric(Information [i] [1]))
        {
            cout << "!Error: Student ID must be numeric." << endl;
            cout << "Student ID:  ";
            cin >> Information [i] [1];
        }

        cout << "Mathematics:             ";
        cin >> Information [i] [2];
        while (!is_grade_valid(Information [i] [2]))
        {
            cout << "!Error: The grade must be a float/integer number in range [0, 20]" << endl;
            cout << "Mathematics:             ";
            cin >> Information [i] [2];
        }

        cout << "Physics:                 ";
        cin >> Information [i] [3];
        while (!is_grade_valid(Information [i] [3]))
        {
            cout << "!Error: The grade must be a float/integer number in range [0, 20]" << endl;
            cout << "Physics:                 ";
            cin >> Information [i] [3];
        }

        cout << "Fundamental of Computer: ";
        cin >> Information [i] [4];
        while (!is_grade_valid(Information [i] [4]))
        {
            cout << "!Error: The grade must be a float/integer number in range [0, 20]" << endl;
            cout << "Fundamental of Computer: ";
            cin >> Information [i] [4];
        }

        cout << "English:                 ";
        cin >> Information [i] [5];  
        while (!is_grade_valid(Information [i] [5]))
        {
            cout << "!Error: The grade must be a float/integer number in range [0, 20]" << endl;
            cout << "English:                 ";
            cin >> Information [i] [5];
        }        

        cout << "Equation:                ";
        cin >> Information [i] [6];
        while (!is_grade_valid(Information [i] [6]))
        {
            cout << "!Error: The grade must be a float/integer number in range [0, 20]" << endl;
            cout << "Equation:                ";
            cin >> Information [i] [6];
        }  

        cout << "------------------------------------------" << endl;
    }
}

void calculate_and_store_means()
{
    float Summation;

    for (int i = 0; i < 3; i++)
    {
        Summation = 0;
        for (int j = 2; j <= 6; j++)
            Summation += stof (Information [i] [j]);
        Information [i] [7] = to_string (Summation / 5);
    }
}

float * selection_sort(float Array [3])
{
    // Putting Array's data in an array that could be returned:
    static float sorted_array [3];
    for (int i = 0; i < 3; i++)
        sorted_array [i] = Array [i];

    // Sorting sorted_array:
    for (int i = 0; i < 2; i++) 
        for (int j = i + 1; j < 3; j++)
            if (sorted_array [j] > sorted_array [i])
                swap (sorted_array [j], sorted_array [i]);
        
    return sorted_array;
}
float * selection_sort(float first_input, float second_input, float third_input) // Overload practicing
{
    // Putting inputs in an array that could be returned:
    static float sorted_array [3];
    sorted_array[0] = first_input;
    sorted_array[1] = second_input;
    sorted_array[2] = third_input;

    // Sorting sorted_array:
    for (int i = 0; i < 2; i++) 
        for (int j = i + 1; j < 3; j++)
            if (sorted_array [j] > sorted_array [i])
                swap (sorted_array [j], sorted_array [i]);
        
    return sorted_array;
}

void resault_printer(float sorted_array [3], int sort_key_index)
{
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (sorted_array [i] == stof (Information [j] [sort_key_index]) && Information [j] [0] != "Printed")
            {
                cout << Information [j] [0] << " (" << Information [j] [1] << "): " << sorted_array [i] << endl;
                Information [j] [0] = "Printed"; // We do this because we don't want print a specific line, repeatedly.
            }
}

void choose_option()
{   
    string selected_option;
    int sort_key_index;

    cout << "Sort by (Enter 1 for Mathematics, 2 for Physics, 3 for Fundamental of Computer, 4 for English, 5 for Equation and 6 for means): ";
    cin >> selected_option;

    // Checking if the input is valid or not:
    while (!is_option_valid(selected_option))
    {
        cout << "!Error: Enter a valid option." << endl;
        cout << "Sort by: ";
        cin >> selected_option;
    }

    // Beautifying:
    cout << endl;

    // The sort_key_index must be the index that refers to the index in Information array:
    sort_key_index = stoi(selected_option); // stoi: String to Integer
    sort_key_index += 1;

    // Making the array to be sorted:
    float Array [3];
    for (int i = 0; i < 3; i++)
        Array [i] = stof(Information [i] [sort_key_index]);

    // Sorted array is ready:
    float * sorted_array = selection_sort(Array);
    // Overload Practicing using this command instead of the command above:
    sorted_array = selection_sort(Array[0], Array[1], Array[2]); // Could be ommited.

    // Printing the resaults:
    resault_printer(sorted_array, sort_key_index);
}

int main()
{
    get_and_store_information();
    calculate_and_store_means();
    choose_option();

    return 0;
}
