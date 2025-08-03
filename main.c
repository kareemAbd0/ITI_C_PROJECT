#include <stdio.h>
#include "headers/file_handler.h"

int main(void) {
    read_users_file();
    read_books_file();
    read_borrowed_books_file();
    // Book b = {"2","Programming","Mazen","2025",1};
    // book_data[book_count] = b;
    // book_count++;
    write_books_file();
    // Borrowed_book br = {"491817892","300",5};
    // borrowed_books_data[borrowed_book_count++] = br;
    write_borrowed_books_file();
    Users u = {"400","Karim","123456",1};
    user_data[user_count++] = u;
    write_users_file();
    // read_books_file();
    return 0;
}