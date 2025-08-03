#include <stdio.h>
#include "headers/file_handler.h"

int main(void) {

    read_users_file();

    read_books_file();

    read_borrowed_books_file();

    Book b = {"2","Programming","Mazen","2025",1};
    book_add(&b);

    Borrowed_book br = {"491817892","300",5};
    borrowed_book_add(&br);

    Users u = {"400","Karim","123456",1};
    user_add(&u);

    user_delete("100");

    book_delete(b.isbn);

    borrowed_book_delete(&br);

    write_endline_file("data\\users.txt","500,Youssef,123456,user");
    return 0;
}