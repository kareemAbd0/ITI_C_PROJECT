#include <stdio.h>
#include <string.h>
#include "../headers/book_ops.h"
#include "../headers/file_handler.h"
//
// Created by kareem on 8/2/25.
//

int borrow_book(Book books[], int size, char title[]){
    for(int i=0;i< size;i++){
        if(strcmp(books[i].title, title)==0){
            if(books[i].number_copies>0){
                if(borrowed_book_count < MAX_BORROWED_BOOKS)
                {
                    books[i].number_copies--;
                    Borrowed_book br;
                    strcpy(br.isbn,books[i].isbn);
                    strcpy(br.borrower_id,current_user_id);
                    br.borrowed_day = 1;
                    borrowed_book_add(&br);
                    write_books_file();
                    return 0;
                }
            }
            return -1;
        }
    }
    return -2;
}

int return_book(Book books[], int size, char title[]){
    char isbn[20];
    for(int i=0;i< size;i++){
        if(strcmp(books[i].title, title)==0){
                books[i].number_copies++;
                strcpy(isbn,books[i].isbn);
                break;
        }
    }
    for(int i = 0; i < borrowed_book_count;i++)
    {
        if(strcmp(borrowed_books_data[i].isbn,isbn) == 0)
        {
            borrowed_book_delete(&borrowed_books_data[i]);
            write_books_file();
            return 0;
        }
    }
    return -1;
}

int  add_book(Book books[],int size, Book book){
    for(int i=0;i< size;i++){
        if(strcmp(books[i].isbn, book.isbn)==0){
            books[i].number_copies+=book.number_copies;
            return 0;
        }
    }
    /*
    for(int i=0;i< size;i++){
        if(books[i].isbn == '0'){
            books[i] = book;
            return 0;
        }
    }*/
    return -1;
}

    
int  delete_book(Book books[],int size,  char isbn[]){
    for(int i=0;i< size;i++){
        if(strcmp(books[i].isbn, isbn)==0){
            *books[i].isbn = '0';
        return 0;
        }
    }
    return -1;
}

int search_book_by_isbn(char *isbn,Book books[], int size){
    for(int i=0;i< size;i++){
        if(strcmp(books[i].isbn, isbn)==0){
            return i;
        }
    }
    return -1;
}

int search_book_by_title(char *title,Book *books, int size){
    for(int i=0;i< size;i++){
        if(strcmp(books[i].title, title)==0){
            return i;
        }
    }
    return -1;
}

void search_book_by_author(char *author,Book *books, int size, int indicies[]){
    int counter = 0;
    for(int i=0;i< size;i++){
        if(strcmp(books[i].author, author) == 0){
            indicies[counter++] = i;
        }
    }
    // Mark end of results
    if (counter < size) 
    indicies[counter] = -1;
}

void search_book_by_year(char* year,Book *books, int size, int indicies[]){
    int counter = 0;
    for(int i=0;i< size;i++){
        if(strcmp(books[i].published_year,year)==0){
            indicies[counter] = i;
            counter ++;
        }
    }
}