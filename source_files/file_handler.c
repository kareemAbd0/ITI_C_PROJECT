//
// Created by kareem on 8/2/25.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "../headers/file_handler.h"



int user_count = 0;
int book_count = 0;
int borrowed_book_count = 0;

Users user_data[MAX_ACCOUNTS];
Book book_data[MAX_BOOKS];
Borrowed_book borrowed_books_data[MAX_BORROWED_BOOKS];

char* convert_lower(char* str);


int add_user(Users* user)
{

    if(user_count >= MAX_ACCOUNTS)
    {
        return -1;
    }

    user_data[user_count++] = *user;


    return write_endline_user_file();
}

int delete_user(char* id)
{
    int deleted_user_index = -1;
    for(int i = 0; i < user_count; i++)
    {
        if(strcmp(id,user_data[i].id) == 0)
        {
            deleted_user_index = i;
            break;
        }
    }

    /*could not find id*/
    if(deleted_user_index == -1)
    {
        return -1;
    }
    else
    {
        for(int i = deleted_user_index; i < user_count - 1; i++)
        {
            user_data[i] = user_data[i + 1];
        }
        user_count--;
        return write_users_file();
    }
}

int add_book(Book* book)
{
    if (book_count >= MAX_BOOKS)
    {
        return -1;
    }

    book_data[book_count++] = *book;

    return write_endline_book_file();
}

int delete_book(char* isbn)
{
    int deleted_book_index = -1;
    for (int i = 0; i < book_count; i++)
    {
        if (strcmp(isbn, book_data[i].isbn) == 0)
        {
            deleted_book_index = i;
            break;
        }
    }

    if (deleted_book_index == -1)
    {
        return -1;
    }
    else
    {
        for (int i = deleted_book_index; i < book_count - 1; i++)
        {
            book_data[i] = book_data[i + 1];
        }
        book_count--;
        return write_books_file();
    }
}

int add_borrowed_book(Borrowed_book* borrowed_book)
{
    if (borrowed_book_count >= MAX_BORROWED_BOOKS)
    {
        return -1;
    }

    borrowed_books_data[borrowed_book_count++] = *borrowed_book;

    return write_endline_borrowed_book_file();
}

int delete_borrowed_book(Borrowed_book* borrowed_book)
{
    int deleted_index = -1;

    for (int i = 0; i < borrowed_book_count; i++)
    {
        if (strcmp(borrowed_book->isbn, borrowed_books_data[i].isbn) == 0 &&
            strcmp(borrowed_book->borrower_id, borrowed_books_data[i].borrower_id) == 0)
        {
            deleted_index = i;
            break;
        }
    }

    if (deleted_index == -1)
    {
        return -1;
    }

    for (int i = deleted_index; i < borrowed_book_count - 1; i++)
    {
        borrowed_books_data[i] = borrowed_books_data[i + 1];
    }

    borrowed_book_count--;
    return write_borrowed_books_file();
}

int write_endline_user_file()
{
    FILE* user_file = fopen("data\\users.txt", "a+");
    if (user_file == NULL)
    {
        printf("Could not open users file for writing\n");
        return -1;
    }

    fseek(user_file, 0, SEEK_END);

    int i = user_count - 1;

    char admin[20];
    if(user_data[i].is_admin == 1)
    {
        strcpy(admin,"admin");
    }
    else
    {
        strcpy(admin,"user");
    }
    fprintf(user_file, "%s,%s,%s,%s\n",
        user_data[i].id,
        user_data[i].username,
        user_data[i].password,
        admin);

    
    fclose(user_file);

    return 1;

}

int write_endline_book_file()
{
    FILE* book_file = fopen("data\\books.txt", "a+");
    if (book_file == NULL)
    {
        printf("Could not open books file for writing\n");
        return -1;
    }

    fseek(book_file, 0, SEEK_END);

    int i = book_count - 1;
    fprintf(book_file, "%s,%s,%s,%s,%d\n",
        book_data[i].isbn,
        book_data[i].title,
        book_data[i].author,
        book_data[i].published_year,
        book_data[i].number_copies);

    fclose(book_file);
    return 1;
}

int write_endline_borrowed_book_file()
{
    FILE* borrowed_book_file = fopen("data\\borrowed_books.txt", "a+");
    if (borrowed_book_file == NULL)
    {
        printf("Could not open borrowed_books file for writing\n");
        return -1;
    }

    fseek(borrowed_book_file, 0, SEEK_END);

    int i = borrowed_book_count - 1;
    char day[20];
    switch(borrowed_books_data[i].borrowed_day)
    {
        case 0:
            strcpy(day, "Sunday");
            break;
        case 1:
            strcpy(day, "Monday");
            break;
        case 2:
            strcpy(day, "Tuesday");
            break;
        case 3:
            strcpy(day, "Wednesday");
            break;
        case 4:
            strcpy(day, "Thursday");
            break;
        case 5:
            strcpy(day, "Friday");
            break;
        case 6:
            strcpy(day, "Saturday");
            break;
    }
    fprintf(borrowed_book_file, "%s,%s,%s\n",
        borrowed_books_data[i].isbn,
        borrowed_books_data[i].borrower_id,
        day);

    fclose(borrowed_book_file);
    return 1;
}


int write_endline_file(char *filename, char *string)
{
    FILE* file = fopen(filename, "a+");
    if (file == NULL)
    {
        printf("Could not open file for writing\n");
        return -1;
    }

    fseek(file, 0, SEEK_END);

    fprintf(file, "%s\n", string);
    
    fclose(file);

    return 1;
}

int write_users_file()
{
    FILE* user_file = fopen("data\\users.txt", "w");
    if (user_file == NULL)
    {
        printf("Could not open user file for writing\n");
        return -1;
    }

    for (int i = 0; i < user_count; i++)
    {
        char admin[20];
        if(user_data[i].is_admin == 1)
        {
            strcpy(admin,"admin");
        }
        else
        {
            strcpy(admin,"user");
        }
        fprintf(user_file, "%s,%s,%s,%s\n",
            user_data[i].id,
            user_data[i].username,
            user_data[i].password,
            admin);
    }

    fclose(user_file);

    return 1;
}
int write_books_file()
{
    FILE* book_file = fopen("data\\books.txt", "w");
    if (book_file == NULL)
    {
        printf("Could not open books file for writing\n");
        return -1;
    }

    for (int i = 0; i < book_count; i++)
    {
        fprintf(book_file, "%s,%s,%s,%s,%d\n",
            book_data[i].isbn,
            book_data[i].title,
            book_data[i].author,
            book_data[i].published_year,
            book_data[i].number_copies);
    }

    fclose(book_file);

    return 1;
}

int write_borrowed_books_file()
{
    FILE* borrowed_book_file = fopen("data\\borrowed_books.txt", "w");
    if (borrowed_book_file == NULL)
    {
        printf("Could not open Borrowed books file for writing\n");
        return -1;
    }

    for (int i = 0; i < borrowed_book_count; i++)
    {
        char day[20];
        switch(borrowed_books_data[i].borrowed_day)
        {
            case 0:
                strcpy(day, "Sunday");
                break;
            case 1:
                strcpy(day, "Monday");
                break;
            case 2:
                strcpy(day, "Tuesday");
                break;
            case 3:
                strcpy(day, "Wednesday");
                break;
            case 4:
                strcpy(day, "Thursday");
                break;
            case 5:
                strcpy(day, "Friday");
                break;
            case 6:
                strcpy(day, "Saturday");
                break;
        }
        fprintf(borrowed_book_file, "%s,%s,%s\n",
            borrowed_books_data[i].isbn,
            borrowed_books_data[i].borrower_id,
            day);
    }

    fclose(borrowed_book_file);

    return 1;
}

int read_users_file()
{
    FILE* user_file;
    int read;
    unsigned int len;
    char* line = NULL;

    read = 0;
    len = 0;

    user_file = fopen("data\\users.txt","r");
    if(user_file == NULL)
    {
        printf("Could Not Open Users File\n");
        return -1;
    }
    else
    {
        int line_index = 0;
        int user_index = 0;
        fseek(user_file, 0, SEEK_END);
        long size = ftell(user_file);

        if (size == 0)
        {
            printf("File is empty.\n");
            fclose(user_file);
            return -1;
        }
        rewind(user_file);
        while ((read = getline(&line, &len, user_file)) != -1)
        {
            int element_no = 1;
            int string_index = 0;
            line_index = 0;
            while(line[line_index] != '\0')
            {
                char string[100];
                while(line[line_index] != ',' && line[line_index] != '\0')
                {
                    if(line[line_index] != '\r' && line[line_index] != '\n')
                    {
                        string[string_index] = line[line_index];
                        string_index++;
                    }
                    line_index++;
                }
                if(line[line_index] != '\0')
                {
                    line_index++;
                }
                string[string_index] = '\0';
                string_index = 0;
                switch(element_no)
                {
                    case 1:
                        while(string[string_index] != '\0')
                        {
                            user_data[user_index].id[string_index] = string[string_index];
                            string_index++;
                        }
                        user_data[user_index].id[string_index] = '\0';
                        printf("%s\n", user_data[user_index].id);
                        break;
                    case 2:
                        while(string[string_index] != '\0')
                        {
                            user_data[user_index].username[string_index] = string[string_index];
                            string_index++;
                        }
                        user_data[user_index].username[string_index] = '\0';
                        printf("%s\n", user_data[user_index].username);
                        break;
                    case 3:
                        while(string[string_index] != '\0')
                        {
                            user_data[user_index].password[string_index] = string[string_index];
                            string_index++;
                        }
                        user_data[user_index].password[string_index] = '\0';
                        printf("%s\n", user_data[user_index].password);
                        break;
                    case 4:
                        printf("%s\n",string);
                        if(strcmp(string,"admin") == 0)
                        {
                            user_data[user_index].is_admin= 1;
                        }
                        else
                        {
                            user_data[user_index].is_admin= 0;
                        }
                        if(user_data[user_index].is_admin== 1)
                        {
                            printf("admin\n");
                        }
                        else
                        {
                            printf("user\n");
                        }
                        break;
                }
                element_no++;
                string_index = 0;
            }
            printf("User[%d] Finished\n", user_index);
            user_index++;
        }

        printf("Users loaded:\n");
        for (int i = 0; i < user_index; i++)
        {
            printf("Code: %s, Name: %s, Password: %s, Type: %s\n",
                user_data[i].id,
                user_data[i].username,
                user_data[i].password,
                user_data[i].is_admin ? "admin" : "user");
        }

        user_count = user_index;
    }

    return 1;
}

int read_books_file()
{
    FILE* book_file;
    int read;
    unsigned int len;
    char* line = NULL;

    read = 0;
    len = 0;

    book_file = fopen("data\\books.txt","r");
    if(book_file == NULL)
    {
        printf("Could Not Open Books File\n");
        return -1;
    }
    else
    {
        int line_index = 0;
        int book_index = 0;
        fseek(book_file, 0, SEEK_END);
        long size = ftell(book_file);
        if (size == 0)
        {
            printf("File is empty.\n");
            fclose(book_file);
            return -1;
        }
        rewind(book_file);
        while ((read = getline(&line, &len, book_file)) != -1)
        {
            int element_no = 1;
            int string_index = 0;
            line_index = 0;
            while(line[line_index] != '\0')
            {
                char string[100];
                while(line[line_index] != ',' && line[line_index] != '\0')
                {
                    if(line[line_index] != '\r' && line[line_index] != '\n')
                    {
                        string[string_index] = line[line_index];
                        string_index++;
                    }
                    line_index++;
                }
                if(line[line_index] != '\0')
                {
                    line_index++;
                }
                string[string_index] = '\0';
                string_index = 0;
                switch(element_no)
                {
                    case 1:
                        while(string[string_index] != '\0')
                        {
                            book_data[book_index].isbn[string_index] = string[string_index];
                            string_index++;
                        }
                        book_data[book_index].isbn[string_index] = '\0';
                        printf("%s\n", book_data[book_index].isbn);
                        break;
                    case 2:
                        while(string[string_index] != '\0')
                        {
                            book_data[book_index].title[string_index] = string[string_index];
                            string_index++;
                        }
                        book_data[book_index].title[string_index] = '\0';
                        printf("%s\n", book_data[book_index].title);
                        break;
                    case 3:
                        while(string[string_index] != '\0')
                        {
                            book_data[book_index].author[string_index] = string[string_index];
                            string_index++;
                        }
                        book_data[book_index].author[string_index] = '\0';
                        printf("%s\n", book_data[book_index].author);
                        break;
                    case 4:
                        while(string[string_index] != '\0')
                        {
                            book_data[book_index].published_year[string_index] = string[string_index];
                            string_index++;
                        }
                        book_data[book_index].published_year[string_index] = '\0';
                        printf("%s\n", book_data[book_index].published_year);
                        break;
                    case 5:
                        book_data[book_index].number_copies = atoi(string);
                        printf("%d\n", book_data[book_index].number_copies);
                        break;
                }
                element_no++;
                string_index = 0;
            }
            printf("Book[%d] Finished\n", book_index);
            book_index++;
        }

        book_count = book_index;

        printf("Books Loaded:\n");
        for (int i = 0; i < book_count; i++)
        {
            printf("Book[%d]: ISBN: %s, Title: %s, Author: %s, Year: %s, Copies: %d\n",
                i,
                book_data[i].isbn,
                book_data[i].title,
                book_data[i].author,
                book_data[i].published_year,
                book_data[i].number_copies);
        }
    }

    return 1;
}

int read_borrowed_books_file()
{
    FILE* borrowed_book_file;
    int read;
    unsigned int len;
    char* line = NULL;

    read = 0;
    len = 0;

    borrowed_book_file = fopen("data\\borrowed_books.txt","r");
    if(borrowed_book_file == NULL)
    {
        printf("Could Not Open Borrowed Books File\n");
        return -1;
    }
    else
    {
        int line_index = 0;
        int borrowed_book_index = 0;
        fseek(borrowed_book_file, 0, SEEK_END);
        long size = ftell(borrowed_book_file);

        if (size == 0)
        {
            printf("File is empty.\n");
            fclose(borrowed_book_file);
            return -1;
        }
        rewind(borrowed_book_file);
        while ((read = getline(&line, &len, borrowed_book_file)) != -1)
        {
            int element_no = 1;
            int string_index = 0;
            line_index = 0;
            while(line[line_index] != '\0')
            {
                char string[100];
                while(line[line_index] != ',' && line[line_index] != '\0')
                {
                    if(line[line_index] != '\r' && line[line_index] != '\n')
                    {
                        string[string_index] = line[line_index];
                        string_index++;
                    }
                    line_index++;
                }
                if(line[line_index] != '\0')
                {
                    line_index++;
                }
                string[string_index] = '\0';
                string_index = 0;
                switch(element_no)
                {
                    case 1:
                        while(string[string_index] != '\0')
                        {
                            borrowed_books_data[borrowed_book_index].isbn[string_index] = string[string_index];
                            string_index++;
                        }
                        borrowed_books_data[borrowed_book_index].isbn[string_index] = '\0';
                        printf("%s\n", borrowed_books_data[borrowed_book_index].isbn);
                        break;
                    case 2:
                        while(string[string_index] != '\0')
                        {
                            borrowed_books_data[borrowed_book_index].borrower_id[string_index] = string[string_index];
                            string_index++;
                        }
                        borrowed_books_data[borrowed_book_index].borrower_id[string_index] = '\0';
                        printf("%s\n", borrowed_books_data[borrowed_book_index].borrower_id);
                        break;
                    case 3:
                        if(strcmp("sunday", convert_lower(string)) == 0)
                        {
                            borrowed_books_data[borrowed_book_index].borrowed_day = 0;
                            printf("%s\n", "Sunday");
                        }
                        else if(strcmp("monday", convert_lower(string)) == 0)
                        {
                            borrowed_books_data[borrowed_book_index].borrowed_day = 1;
                            printf("%s\n", "Monday");
                        }
                        else if(strcmp("tuesday", convert_lower(string)) == 0)
                        {
                            borrowed_books_data[borrowed_book_index].borrowed_day = 2;
                            printf("%s\n", "Tuesday");
                        }
                        else if(strcmp("wednesday", convert_lower(string)) == 0)
                        {
                            borrowed_books_data[borrowed_book_index].borrowed_day = 3;
                            printf("%s\n", "Wednesday");
                        }
                        else if(strcmp("thursday", convert_lower(string)) == 0)
                        {
                            borrowed_books_data[borrowed_book_index].borrowed_day = 4;
                            printf("%s\n", "Thursday");
                        }
                        else if(strcmp("friday", convert_lower(string)) == 0)
                        {
                            borrowed_books_data[borrowed_book_index].borrowed_day = 5;
                            printf("%s\n", "Friday");
                        }
                        else if(strcmp("saturday", convert_lower(string)) == 0)
                        {
                            borrowed_books_data[borrowed_book_index].borrowed_day = 6;
                            printf("%s\n", "Saturday");
                        }
                        break;
                }
                element_no++;
                string_index = 0;
            }
            printf("Borrowed_Book[%d] Finished\n", borrowed_book_index);
            borrowed_book_index++;
        }

        borrowed_book_count = borrowed_book_index;
    }

    return 1;
}



char* convert_lower(char* str)
{
    int length = strlen(str);
    char c[length + 1];

    for (int i = 0; i < length; i++)
    {
        if (str[i] <= 'Z' || str[i] >= 'A')
        {
            c[i] = tolower((char)str[i]);
        }
    }
    c[length] = '\0';
    char* text = c;
    return text;
}
