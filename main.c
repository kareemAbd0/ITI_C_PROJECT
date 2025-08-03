#include <stdio.h>
#include "headers/file_handler.h"

int main(void) {

    read_users_file();

    read_books_file();

    read_borrowed_books_file();

    Book b = {"2","Programming","Mazen","2025",1};
    add_book(&b);

    Borrowed_book br = {"491817892","300",5};
    add_borrowed_book(&br);

    Users u = {"400","Karim","123456",1};
    add_user(&u);

    delete_user("300");

    delete_book(b.isbn);

    delete_borrowed_book(&br);
    
    write_endline_file("data\\users.txt","500,Youssef,123456,user");
    return 0;
}