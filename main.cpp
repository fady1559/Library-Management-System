/****** Include Section   ******/
#include "BooksManage.h"  // Make sure the header file is included.

/****** Functions Section ******/

/**
 *@brief Template function to handle any user inputs
 *@param (lowerLimit) Minimum value user input
 *       (upperLimit) Maximum value user input
 *       (prompt)     String to print for user
 *@return user input or choice
 */
template <typename T>
T getValidatedInput(T lowerLimit, T upperLimit, const string& prompt)
{
    T input;

    while(true)
    {
        cout << prompt;
        cin >> input;

        if ((cin.fail()) || (input < lowerLimit) || (input > upperLimit))
        {
            cin.clear();  // Clear the error state
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignore invalid input
            cout << "Invalid input. Please enter a value between " << lowerLimit << " and " << upperLimit << ".\n";
        }
        else
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Only here to clear the buffer after valid input
            break;  // Valid input, break the loop
        }
    }
    return input;
}


void printascii(string file)
{
    string line = " "; // Variable to hold each line read from the file
    ifstream infile; // Create an input file stream object

    // Attempt to open the file with a hardcoded path
    infile.open("C:\\Users\\Abdelhamid\\Downloads\\DataStructureProject_last\\asci.text.txt");
    if (infile.is_open())   // Check if the file is successfully opened
    {
        // Read the file line by line until the end
        while (getline(infile, line))
        {
            cout << line << endl; // Output each line to the console
        }
    }
    else
    {
        // Error message if the file could not be opened
        cout << "file failed \n";
    }
    // Close the file after processing
    infile.close();

}

/**
 *@brief  Function to print menu choices
 *@param  void
 *@return void
 */
void Print_Choices_Menu()
{
    cout << "*****************************************\n";
    cout << "          Book Management Menu           \n";
    cout << "*****************************************\n\n";
    cout << "1. Insert book\n";
    cout << "2. Delete book\n";
    cout << "3. Sort books\n";
    cout << "4. Display books\n";
    cout << "5. Destroy book list\n";
    cout << "6. Search for a book\n";
    cout << "7. Get the length of the book list\n";
    cout << "8. Update information for a certain book\n\n";
}

int main()
{
    //asci art output
    string file="asci.text";
    printascii(file);
    Sleep(30000);     // DELAY FOR 30 SECOND
    system("cls");   // Clear Terminal Window

    int choose;  // To store the user's choice
    char k;      // To store the user's response for repeating operations
    book_manage obj; // Object of the book_manage class

    do
    {
        system("cls"); // Clear Terminal Window

        Print_Choices_Menu(); // Display the menu options

        // Input validation for the user's choice (1-8)
        choose = getValidatedInput(1, 8, "Enter your choice (1-8): ");

        // Perform the operation based on the user's choice
        switch (choose)
        {
        case 1:
            system("cls"); // Clear Terminal Window
            obj.insert_book();
            break;
        case 2:
            system("cls"); // Clear Terminal Window
            obj.delete_book();
            break;
        case 3:
            system("cls"); // Clear Terminal Window
            obj.sort();
            break;
        case 4:
            system("cls"); // Clear Terminal Window
            obj.display();
            break;
        case 5:
            system("cls"); // Clear Terminal Window
            obj.destroy_list();
            break;
        case 6:
            system("cls"); // Clear Terminal Window
            obj.search();
            break;
        case 7:
            system("cls"); // Clear Terminal Window
            obj.get_length();
            break;
        case 8:
            system("cls"); // Clear Terminal Window
            obj.updateBook();
            break;
        default:
            system("cls"); // Clear Terminal Window
            cout << "Unexpected error.\n"; // This will never happen due to the input validation
            break;
        }

        // Ask the user if they want to perform another operation
        cout << "\nDo you want another operation? (y/n): ";

        // Input validation for repeat question ('y' or 'n')
        while(true)
        {
            cin >> k; // Take 'Y' or 'y' or 'N' or 'n' from user

            if ((cin.fail()) || ((k != 'y') && (k != 'Y') && (k != 'n') && (k != 'N')))
            {
                cin.clear(); // Clear the error state of cin
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
                cout << "Invalid input. Please enter 'y' to continue or 'n' to exit : ";// Prompt again
            }
            else
            {
                break; // Valid input, break out of the loop
            }
        }
    }
    while((k == 'y') || (k == 'Y'));   // Repeat if the user enters 'y' or 'Y'

    system("cls"); // Clear Terminal Window

    // End of the program
    cout << "*****************************************\n";
    cout << "      Exiting the program. Goodbye!      \n";
    cout << "*****************************************\n";

    system("cls");

    printascii(file);
    Sleep(30000);   //Delay for 30 second

    return 0;
}
