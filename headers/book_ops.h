#ifndef BOOK_OPS_H
#define BOOK_OPS_H

#include "file_handler.h"


//keep day pf the week in mind, at the end show day of return from gui,adds book to borrowed books runtime array,
int borrow_book(Book books[], int size,char title[]);

//gui returns book, will remove book from borrowed books runtime array
int return_book(Book books[] ,int size,char title[]);

//admin function, will add book to books runtime array
int  add_book();
//admin function, will delete book from books runtime array
int  delete_book(Book books[] ,int size,  char isbn[]);

//will search for book in books runtime array,returns number of books found
int search_book_by_isbn(char *isbn,Book books[], int size);
int search_book_by_title(char *title,Book *books, int size);
void search_book_by_author(char *author,Book *books, int size, int indicies[]);
void search_book_by_year(char* year,Book *books, int size, int indicies[]);






#endif //BOOK_OPS_H