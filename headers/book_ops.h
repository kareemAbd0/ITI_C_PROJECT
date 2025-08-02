#ifndef BOOK_OPS_H
#define BOOK_OPS_H

#include "file_handler.h"


//keep day pf the week in mind, at the end show day of return from gui,adds book to borrowed books runtime array,
int borrow_book(Book *book_data);

//gui returns book, will remove book from borrowed books runtime array
int return_book(Book *book_data);

//admin function, will add book to books runtime array
int  add_book(Book *book_data);
//admin function, will delete book from books runtime array
int  delete_book(Book *book_data);

//will search for book in books runtime array,returns number of books found
int search_book_by_isbn(char *isbn,Book *book_data_out);
int search_book_by_title(char *title,Book *book_data_out);
int search_book_by_author(char *author,Book **book_data_out);
int search_book_by_year(int year,Book **book_data_out);






#endif //BOOK_OPS_H
