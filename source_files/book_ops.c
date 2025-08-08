#include <stdio.h>
#include <string.h>
#include "../headers/book_ops.h"
#include "../headers/file_handler.h"
//
// Created by kareem on 8/2/25.
//

void strip_new_line(char *str)
{
    int len = strlen(str);
    if (len > 0 && str[len - 1] == '\n')
    {
        str[len - 1] = '\0';
    }
}

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

int  add_book(){

    if(book_count >= MAX_BOOKS)
    {
        return -1;
    }

    char isbn[20];
    char title[50];
    char author[50];
    char published_year[5];
    int number_of_copies;

    printf("enter isbn of book : \n");
    fgets(isbn, sizeof(isbn), stdin);
    strip_new_line(isbn);
    printf("enter title of book : \n");
    fgets(title, sizeof(title), stdin);
    strip_new_line(title);
    printf("enter author of book : \n");
    fgets(author, sizeof(author), stdin);
    strip_new_line(author);
    printf("enter Published Year of book : \n");
    fgets(published_year, sizeof(published_year), stdin);
    strip_new_line(published_year);
    printf("enter number of copies : \n");
    scanf("%d",&number_of_copies);

    Book b;
    strcpy(b.isbn,isbn);
    strcpy(b.title,title);
    strcpy(b.author,author);
    strcpy(b.published_year,published_year);
    b.number_copies = number_of_copies;

    return book_add(&b);

}

    
int  delete_book(Book books[],int size,  char isbn[]){
    return book_delete(isbn);
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