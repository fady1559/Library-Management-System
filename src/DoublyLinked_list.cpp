#include "DoublyLinked_list.h"

/**
 *@brief  Default constructor to initialize list parameters
 *@param  void
 *@return void
 */
doubly_linkedlist::doubly_linkedlist()
{
    head = nullptr;   // Initialize head to null (no elements in the list)
    tail = nullptr;   // Initialize tail to null (no elements in the list)
    length = 0;       // Initialize length to 0 (no elements in the list)
}

/**
 *@brief  Function to insert book at first of the node
 *@param  void
 *@return void
 */
void doubly_linkedlist::insert_first()
{
    node* newNode = new node;  // Create a new node in heap memory "Allocation in heap"

    if (newNode == nullptr) {  // Check if memory allocation failed
        cout << "Memory allocation failed" << endl;
        return; // end function if creation failed
    }

    if (isEmpty()) {  // Check if the list is empty
        head = newNode;  // Set head to the new node
        tail = newNode;  // Set tail to the new node
    }
    else {
        if (isFound(newNode->data.name)) {
            cout << "\nA Book With The Same Title Exists. Choice Different Title Please\n\n";
            delete newNode;
            return; // end function if there is the same book with the same name
        }

        newNode->next = head;   // Set the new node's next to the current head
        head->prev = newNode;   // Set the current head's previous to the new node
        head = newNode;         // Move head to the new node
    }

    length++;   // Increment length of the list
    cout << "Book \"" << newNode->data.name << "\" added successfully to the beginning of the list.\n";
}

/**
 *@brief  Function to insert book at end of list
 *@param  void
 *@return void
 */
void doubly_linkedlist::insert_last()
{
    if (isEmpty()) {  // Check if the list is empty
        insert_first();  // If empty, insert at the beginning
    }
    else {
        node* newNode = new node;  // Create a new node in heap memory "Allocate in heap"

        if (newNode == nullptr) {  // Check if memory allocation failed
            cout << "Memory allocation failed" << endl;
            return; // end function if it failed to create node in heap
        }

        if (isFound(newNode->data.name)) {
            cout << "\nA Book With The Same Title Exists. Choice Different Title Please\n\n";
            delete newNode;
            return; // end function if there is the same book with the same name
        }

        newNode->prev = tail;  // Set the new node's previous to the current tail
        tail->next = newNode;  // Set the current tail's next to the new node
        tail = newNode;        // Move tail to the new node
        length++;  // Increment length of the list

        cout << "Book \"" << newNode->data.name << "\" added successfully to the end of the list.\n";
    }
}

/**
 *@brief  Function to insert book at certain position
 *@param  (n) position of the book we need to insert
 *@return void
 */
void doubly_linkedlist::insert_at_pos(int n)
{
    if (n <= 0 || n > length) { // check of position if it's zero or negative or bigger than the number of books that already existed
        cout << "Position out of range. Valid range is [1, " << length << "].\n";
        return; // end function if position is invalid
    }

    if (isEmpty()) {  // Check if the list is empty
        cout << "The list is empty" << endl;
        return; // end function if the list is empty
    }
    else {
        if (n == 1) {  // If position is 1, insert at the beginning
            insert_first();
        }
        else if (n == length + 1) {  // If position is the last, insert at the end
            insert_last();
        }
        else {
            node* current = head;  // Start from the head
            for (int i = 1; i < n; i++)  // Traverse the list to position n
                current = current->next;

            node* newNode = new node;  // Create a new node in heap memory "Allocate in heap"
            if (newNode == nullptr) {  // Check if memory allocation failed
                cout << "Memory allocation failed" << endl;
                return; // end function if allocation failed
            }

            if (isFound(newNode->data.name)) {
                cout << "\nA Book With The Same Title Exists. Choice Different Title Please\n\n";
                delete newNode;
                return; // end function if there is same book with the same name
            }

            newNode->next = current;  // Set new node's next to the current node
            newNode->prev = current->prev;  // Set new node's previous to the previous of current node
            current->prev->next = newNode;  // Set previous node's next to the new node
            current->prev = newNode;        // Set current node's previous to the new node
            length++;  // Increment length of the list

            cout << "Book \"" << newNode->data.name << "\" added successfully at position " << n << ".\n";
        }
    }


}

/**
 *@brief  Delete book from first
 *@param  void
 *@return void
 */
void doubly_linkedlist::delete_first()
{
        node* delPtr;  // Create a pointer to hold the node to be deleted
        delPtr = head;  // Set the pointer to the head
        if (head == tail) {  // If there is only one node in the list
            head = tail = nullptr;  // Set both head and tail to null
        }
        else {
            head = head->next;  // Move head to the next node
            head->prev = nullptr;  // Set the new head's previous to null
        }
        delete delPtr;  // Delete the node
        length--;  // Decrement length of the list
        cout << "Book deleted successfully.\n";
}

/**
 *@brief  Delete book from last
 *@param  void
 *@return void
 */
void doubly_linkedlist::delete_at_end()
{
        node* delPtr = tail;  // Set the pointer to the tail node
        if (head == tail) {  // If there is only one node in the list
            head = tail = nullptr;  // Set both head and tail to null
        }
        else {
            tail = tail->prev;  // Move tail to the previous node
            tail->next = nullptr;  // Set the new tail's next to null
        }
        delete delPtr;  // Delete the node
        length--;  // Decrement length of the list
        cout << "Book deleted successfully.\n";

}

/**
 *@brief  Delete book at certain position
 *@param  (n) position of book we need to delete
 *@return void
 */
void doubly_linkedlist::delete_at_pos(int n)
{
        if (n <= 0 || n > length) { // check of position if it's zero or negative or bigger than the number of books that already existed
            cout << "Position out of range. Valid range is [1, " << length << "].\n";
            return; // end function if the list is empty
        }
        if (n == 1) {  // If position is 1, delete the first node
            delete_first();
        }
        else if (n == length) {  // If position is the last, delete the last node
            delete_at_end();
        }
        else {
            node* delPtr = head;  // Set pointer to the head
            for (int i = 1; i < n; i++) {  // Traverse the list to position n
                delPtr = delPtr->next;
            }
            delPtr->prev->next = delPtr->next;  // Link previous node's next to the node after the current node
            delPtr->next->prev = delPtr->prev;  // Link next node's previous to the node before the current node
            delete delPtr;  // Delete the node
            length--;  // Decrement length of the list
            cout << "Book deleted successfully.\n";
        }
}

/**
 *@brief  Delete book with certain name
 *@param  (title) name of the book we need to delete it
 *@return void
 */
void doubly_linkedlist::delete_book(const string& title) {
    node* delPtr = search_Book(title); // Search for the node with the given title
    if (delPtr) {
        delete_book(delPtr); // Call the function to delete using the node pointer
    } else {
        cout << "Book not found.\n";
    }
}

/**
 *@brief  Delete book if we have its address in memory
 *@param  (delPtr) pointer to address of the book we need to delete
 *@return void
 */
void doubly_linkedlist::delete_book(node* delPtr) {
    if (delPtr) {  // Check if the node pointer is valid
        if (delPtr == head) {  // If the node is the first one
            delete_first();
        } else if (delPtr == tail) {  // If the node is the last one
            delete_at_end();
        } else {  // If the node is in the middle
            delPtr->prev->next = delPtr->next; // Update the next pointer of the previous node
            delPtr->next->prev = delPtr->prev; // Update the previous pointer of the next node
            delete delPtr; // Delete the node
            length--; // Decrease the length of the list
            cout << "Book deleted successfully.\n";
        }

    } else {
        cout << "Error: Null pointer passed to delete_book.\n";
    }
}

/**
 *@brief  Function to update book information
 *@param  (book_name) name of book we need to update its information
 *@return void
 */
void doubly_linkedlist::update_book(const string& book_name)
{
    node* current = search_Book(book_name);
        if (current) {
            cout << "Book found: \n";
            cout << "Name: " << current->data.name
                 << ", Author: " << current->data.author
                 << ", Category: " << current->data.category
                 << ", Publish Year: " << current->data.p_year << "\n";
            current->data.update_data(); // Update the book's details

            cout << "Book updated successfully!\n";
        }
        else{
                cout << "Book with name \"" << book_name << "\" not found in the list.\n";
        }

}


/**
 *@brief  Function to display books forward from head to tail
 *@param  void
 *@return void
 */
void doubly_linkedlist::display_Forward()
{
    //system("cls"); // Clear Terminal Window

    node* current = head;  // Start from the head
   cout << left << setw(10) << "No."
         << setw(30) << "Book Title"
         << setw(30) << "Author"
         << setw(30) << "Publication Year"
         << setw(30) << "Category"
         << endl;
    cout << string(108, '-') << endl;  // Separate line

    int i = 1;                                        // For printing the number of the book
    while (current)
    {
        cout << left << setw(10) << i                 // Display the number of the book
             << setw(30) << current->data.name        // Align the book name
             << setw(30) << current->data.author      // Align the author's name
             << setw(30) << current->data.p_year      // Align the publication year
             << setw(30) << current->data.category    // Align the category
             << endl;

        current = current->next;  // Move to the next node
        i++;
    }
}

/**
 *@brief  Function to display books backward from tail to head
 *@param  void
 *@return void
 */
void doubly_linkedlist::display_backward()
{
    //system("cls"); // Clear Terminal Window

    cout << left << setw(10) << "No."
         << setw(30) << "Book Title"
         << setw(30) << "Author"
         << setw(30) << "Publication Year"
         << setw(30) << "Category"
         << endl;
    cout << string(108, '-') << endl;  // separate line

    node* current = tail;  // Start from the tail
    int i = 1;  // For printing the number of the book
    while (current)
    {
        cout << left << setw(10) << i  // Display the number of the book
             << setw(30) << current->data.name         // Align the book name
             << setw(30) << current->data.author       // Align the author's name
             << setw(30) << current->data.p_year      // Align the publication year
             << setw(30) << current->data.category    // Align the category
             << endl;

        current = current->prev;  // Move to the previous node
        i++;  // Increment the book number
    }
}

/// @brief Search for a book by name and print its details
node* doubly_linkedlist::search_Book(const string& name)
{
    node* temp_head = head;  // Start from the head
    node* temp_tail = tail;  // Start from the tail

    while (temp_head != nullptr && temp_tail != nullptr && temp_head != temp_tail->next)  // Proper termination condition
    {
        if (temp_head->data.name == name)  // If book is found at the head side
        {
            return temp_head;  // Return pointer to the node
        }
        if (temp_tail->data.name == name)  // If book is found at the tail side
        {
            return temp_tail;  // Return pointer to the node
        }

        temp_head = temp_head->next;  // Move the head pointer forward
        temp_tail = temp_tail->prev;  // Move the tail pointer backward
    }

    return nullptr;  // If the book is not found
}


/// @brief Check if the list is empty
bool doubly_linkedlist::isEmpty()
{
    return (head == nullptr);  // Return true if head is null (list is empty)
}

/// @brief Check if a book is found in the list by its name
bool doubly_linkedlist::isFound(const string& name)
{
    node* temp_head = head;  // Start from the head
    node* temp_tail = tail;  // Start from the tail

    while (temp_head != nullptr && temp_tail != nullptr && temp_head != temp_tail->next)  // Proper termination condition
    {
        if (temp_head->data.name == name)  // If book is found at the head side
        {
            return true;  // Return pointer to the node
        }
        if (temp_tail->data.name == name)  // If book is found at the tail side
        {
            return true;  // Return pointer to the node
        }

        temp_head = temp_head->next;  // Move the head pointer forward
        temp_tail = temp_tail->prev;  // Move the tail pointer backward
    }

    return false;  // If the book is not found
}

/// @brief Display the number of books in the list
int doubly_linkedlist::get_length()
{
    return length ;  // Print the number of books
}

/// @brief Sort the list alphabetically by book name
void doubly_linkedlist::sort()
{
    for (node* i = head; i->next != nullptr; i = i->next)  // Outer loop for sorting
    {
        for (node* j = i->next; j != nullptr; j = j->next)  // Inner loop for comparison
        {
            if (i->data.name > j->data.name)  // If the current book's name is greater, swap
            {
                swap(i->data, j->data);
            }
        }
    }
}

/// @brief Free all nodes in the list and reset to empty
void doubly_linkedlist::freeList()
{
    node* temp;  // Create pointer for deleting nodes
    while (head)  // While there are nodes to delete
    {
        temp = head;  // Set temp to the current head
        head = head->next;  // Move head to the next node
        delete temp;  // Delete the current node
    }

    tail = nullptr;  // Set tail to null
    length = 0;  // Set length to 0
}

/// @brief Destructor to free the list when it is no longer needed
doubly_linkedlist::~doubly_linkedlist()
{
    freeList();  // Call freeList to delete all nodes
}
