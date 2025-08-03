//
// Created by kareem on 8/2/25.
//

#ifndef FILE_HANDLER_H
#define FILE_HANDLER_H

#define MAX_ACCOUNTS 100
#define MAX_BOOKS 100
#define MAX_BORROWED_BOOKS 100


struct Users {
    char id[20];
    char username[20];
    char password[20];
    int is_admin; // 1 for admin, 0 for user
}typedef Users;

struct Book {
    char isbn[20];
    char title[50];
    char author[50];
    char published_year[5];
    int number_copies;
}typedef Book;

struct Borrowed_book {
    char isbn[20];
    char borrower_id[20];
    int borrowed_day; // day of the week, 0-6 (0=Sunday, 1=Monday, ..., 6=Saturday)
}typedef Borrowed_book;



extern int user_count;
extern int book_count;
extern int borrowed_book_count;

extern Users user_data[MAX_ACCOUNTS];
extern Book book_data[MAX_BOOKS];
extern Borrowed_book borrowed_books_data[MAX_BORROWED_BOOKS];


//add al the last element of array to the last line of text file
int  write_endline_file(char *filename, char **string,int size);

int write_users_file();
int write_books_file();
int write_borrowed_books_file();

int read_users_file();
int read_books_file();
int read_borrowed_books_file();



#endif //FILE_HANDLER_H
