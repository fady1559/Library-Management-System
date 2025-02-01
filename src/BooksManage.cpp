/****** Include Section   ******/
#include "BooksManage.h"

/****** Functions Section ******/

/**
 *@brief Template function to handle any user inputs
 *@param (lowerLimit) Minimum value user input
 *       (upperLimit) Maximum value user input
 *       (prompt)     String to print for user
 *@return user input or choice
 */
template <typename T>
T getValidatedInput(T lowerLimit, T upperLimit, const string& prompt) {
    T input;
    while (true) {
        cout << prompt;
        cin >> input;

        if (cin.fail() || input < lowerLimit || input > upperLimit) {
            cin.clear();  // Clear the error state
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignore invalid input
            cout << "Invalid input. Please enter a value between " << lowerLimit << " and " << upperLimit << ".\n";
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Only here to clear the buffer after valid input
            break;  // Valid input, break the loop
        }
    }
    return input;
}

/**
 *@brief Function to handle operations of inserting books
 *@param void
 *@return void
 */
void book_manage::insert_book() {
    cout << "****************************************\n";
    cout << "           Insert Book Menu             \n";
    cout << "****************************************\n";
    cout << "1 - Insert book at the beginning\n";
    cout << "2 - Insert book at the end\n";
    cout << "3 - Insert book at a specific position\n";
    cout << "****************************************\n";

    int choice = getValidatedInput(1, 3, "\nEnter the number of the operation you want (1-3): ");

    switch (choice) {
        case 1:
            library_list[index].insert_first(); // Insert book at the beginning
            break;
        case 2:
            library_list[index].insert_last(); // Insert book at the end
            break;
        case 3:
            {
                int position;
                cout << "Enter the position: ";
                cin >> position;
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clearing the buffer after position input
                library_list[index].insert_at_pos(position); // Insert book at a specific position
            }
            break;
    }
}

/**
 *@brief Function to handle operations of deleting books
 *@param void
 *@return void
 */
void book_manage::delete_book() {
    cout << "****************************************\n";
    cout << "           Delete Book Menu             \n";
    cout << "****************************************\n";
    cout << "1 - Delete book at the beginning\n";
    cout << "2 - Delete book at the end\n";
    cout << "3 - Delete book at a specific position\n";
    cout << "4 - Delete book by the title\n";
    cout << "****************************************\n";

    if (library_list[index].isEmpty()) {  // Check if the list is empty
        cout << "The list is empty.\n";  // Print message if the list is empty
        return;
    }

    int choice = getValidatedInput(1, 4, "Enter the number of the operation you want (1-4): ");

    switch (choice) {
        case 1:
            library_list[index].delete_first(); // Delete book from the beginning
            break;
        case 2:
            library_list[index].delete_at_end(); // Delete book from the end
            break;
        case 3:
            {
                int position;
                cout << "Enter the position: ";
                cin >> position;
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clearing the buffer after position input
                library_list[index].delete_at_pos(position); // Delete book from a specific position
            }
            break;
        case 4:
            {
                string title;
                cout << "Enter the name of the book you want to delete: ";
                getline(cin, title);
                library_list[index].delete_book(title); // Delete book by title
            }
            break;
    }
}

/**
 *@brief Function to handle operations of searching of books
 *@param void
 *@return void
 */
void book_manage::search() {
    cout << "****************************************\n";
    cout << "           Search Book Menu             \n";
    cout << "****************************************\n";

     if (library_list[index].isEmpty()) {
        cout << "The list is empty. No book to update.\n";
        return;
    }

    string title;
    cout << "Enter the name of the book you want to search for: ";
    getline(cin, title);

    node* search = library_list[index].search_Book(title); // Search for the book by title
    if (search) {
        int x;
        cout << "Book is found \n\n";
        cout << "------------------------\n\n";
        cout << "1- Print the book information \n";
        cout << "2- Update the book information \n";
        cout << "3- Delete this book \n";
        cout << "4- Exit\n\n";
        x = getValidatedInput(1, 4, "Enter the number of the operation you want (1-4): ");

        switch (x) {
            case 1:
                search->data.print();
                break;
            case 2:
                search->data.update_data();
                break;
            case 3:
                library_list[index].delete_book(search);
                break;
            case 4:
                break;
        }
    } else {
        cout << "The book "<<title<<" is not found\n";
    }
}

/**
 *@brief Function to handle operations of sorting list
 *@param void
 *@return void
 */
void book_manage::sort() {
    cout << "****************************************\n";
    cout << "            Sort Book Menu              \n";
    cout << "****************************************\n";


    if(library_list[index].isEmpty())
    {
    cout<<"the list is empty\n";
    return;
    }
    else if (library_list[index].get_length()==1)
    {
        cout<<"the library has only one book ";
        return;
    }
    char choice;
    cout << "Are you sure you want to sort the list? (y/n): ";
    do {
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clearing the buffer after the 'y/n' input
        if (cin.fail()) {
            cin.clear();
            cout << "Invalid input. Please enter 'y' or 'n'.\n";
        }
    } while (choice != 'y' && choice != 'n' && choice != 'Y' && choice != 'N'); // loop to check the input if it's invalid

    if (choice == 'y' || choice == 'Y') { // Check the input of user either 'y' or 'Y' to sort the list
        cout << "Sorting the list...\n";
        library_list[index].sort(); // Sort the books
    } else {
        cout << "Sorting process aborted.\n";
    }
}

/**
 *@brief Function to handle operations of display list
 *@param void
 *@return void
 */
void book_manage::display() {
    cout << "****************************************\n";
    cout << "          Display Book Menu             \n";
    cout << "****************************************\n";
    cout << "1 - Display list forward\n";
    cout << "2 - Display list backward\n";
    cout << "****************************************\n";

     if (library_list[index].isEmpty())  // Check if the list is empty
    {
        cout << "The list is empty\n";  // Print message if the list is empty
        return;
    }

    int choice = getValidatedInput(1, 2, "Enter the number of the operation (1-2): ");

    if (choice == 1) {
        library_list[index].display_Forward(); // Display books in forward order from head to tail
    } else {
        library_list[index].display_backward(); // Display books in backward order from tail to head
    }
}

/**
 *@brief Function to handle operation of update book information
 *@param void
 *@return void
 */
void book_manage::updateBook() {
    cout << "****************************************\n";
    cout << "           Update Book Menu             \n";
    cout << "****************************************\n";

     if (library_list[index].isEmpty()) {
        cout << "The list is empty. No book to update.\n";
        return;
    }
    string title;
    cout << "Enter the name of the book you want to update its information: ";
    getline(cin, title);
    library_list[index].update_book(title); // Update the book information
}

void book_manage::show_lists()
{
    cout << "****************************************\n";
    cout << "               Lists Menu               \n";
    cout << "****************************************\n";
    for(int i=0;i<5;i++)
        {
            if(library_list[i].list_name!= "NUll")
             cout<<"list "<<i+1<<" : "<< library_list[i].list_name<<endl; 
             else
             return;
        }
}

/**
 *@brief Function to handle operation of destroy list
 *@param void
 *@return void
 */
void book_manage::destroy_list() {
    cout << "****************************************\n";
    cout << "        Destroy Book List Menu          \n";
    cout << "****************************************\n";

        if (library_list[index].isEmpty())
            {
                cout<<"\nThe list is Empty\n";
                return;
            }                                                               // Return if the list is empty or has only one book
            else if (library_list[index].get_length()==1)
            {
                cout<<"\nThe list contain only  book\n";
            }
    char choice;
    cout << "Are you sure you want to free the list? (y/n): ";
    do {
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clearing the buffer after the 'y/n' input
        if (cin.fail()) { // to check the input of user if it's invalid
            cin.clear();
            cout << "Invalid input. Please enter 'y' or 'n'.\n";
        }
    } while (choice != 'y' && choice != 'n' && choice != 'Y' && choice != 'N'); // loop to take correct input from user

    if (choice == 'y' || choice == 'Y') { // Check the input of user either 'y' or 'Y' to destroy list
        cout << "Freeing the list...\n";
        library_list[index].freeList(); // Free the list
    } else {
        cout << "Freeing process aborted.\n";
    }
}

/**
 *@brief Function to handle operation of length of list
 *@param void
 *@return void
 */
void book_manage::get_length() {
    cout << "The list contains " << library_list[index].get_length() << " Books\n";
}
