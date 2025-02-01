# ifndef Books_Manage_H
# define Books_Manage_H

# include "DoublyLinked_list.h"
# include "book.h"

/// @brief 
class book_manage
{
    public:
    void insert_book();
    void delete_book ();
    void search();
    void sort();
    void display();
    void destroy_list();
    void get_length ();
    void updateBook();
    void show_lists();

    doubly_linkedlist library_list[5];
    int index;
};

#endif
