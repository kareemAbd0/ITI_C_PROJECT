#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include "headers/GUI.h"

#include "headers/file_handler.h"
#include "headers/accounts.h"
#include "headers/book_ops.h"

enum steps
{
    start_screen = 1,
    admin_screen,
    user_screen

};

int main(void)
{
    int screen_variable = 1;
    int option = 0, flag = 0;

    read_users_file();

    read_books_file();

    read_borrowed_books_file();

    strcpy(current_user_id, "-1");

    while (1)
    {

        if (screen_variable == start_screen)
        {
            option = display_combined_box(empty_array, 0, start_menu, 3);
            if (option == 1)
            {
                system("cls");
                flag = login();
                if (flag == 1)
                    screen_variable = admin_screen;
                else if (flag == 0)
                    screen_variable = user_screen;
            }
            else if (option == 2)
            {
                system("cls");
                flag = sign_up();
                screen_variable = start_screen;
            }
            else
            {

                return 0;
            }
            if (flag == -1)
            {
                screen_variable = start_screen;
                continue;
            }
        }
        else if (screen_variable == admin_screen)
        {
            option = 0;
            option = display_combined_box(Hi_message_admin, 2, Admin_main_screen, 4);
            if (option == 1)
            {
                // add book scenario
            }
            else if (option == 2)
            {
                // delete book scenario
            }
            else if (option == 3)
            {
                // search book scenario
            }
            else if (option == 4)
            {
                screen_variable = start_screen;
            }
        }
        else if (screen_variable == user_screen)
        {
            option = 0;
            option = display_combined_box(Hi_message_user, 2, User_main_screen, 4);
            if (option == 1)
            {
                system("cls");
                char titles[MAX_BOOKS][50];
                char *title_ptrs[MAX_BOOKS];

                for (int i = 0; i < book_count; i++)
                {
                    strcpy(titles[i], book_data[i].title);
                    title_ptrs[i] = titles[i];
                }

                int book_option = display_combined_box(Hi_message_user, 0, title_ptrs, book_count);
                int book_flag = borrow_book(book_data, book_count, book_data[book_option - 1].title);
                system("cls");
                if (book_flag == 0)
                {
                    printf("You have three days.\n");
                }
                else if (book_flag == -1)
                {
                    printf("No copies available.\n");
                }
                else if (book_flag == -2)
                {
                    printf("Book not found.\n");
                }
                getch();
                screen_variable = user_screen;
            }
            else if (option == 2)
            {
                system("cls");
                char titles[MAX_BOOKS][50];
                char *title_ptrs[MAX_BOOKS];

                int borrowed_book_user_count = 0;
                for (int i = 0; i < borrowed_book_count; i++)
                {
                    if(strcmp(borrowed_books_data[i].borrower_id,current_user_id) == 0)
                    {
                        for(int j = 0; j < book_count; j++)
                        {
                            if(strcmp(book_data[j].isbn,borrowed_books_data[i].isbn) == 0)
                            {
                                strcpy(titles[borrowed_book_user_count], book_data[j].title);
                                title_ptrs[borrowed_book_user_count] = titles[i];
                                borrowed_book_user_count++;
                                break;
                            }
                        }
                    } 
                }

                int book_option = display_combined_box(Hi_message_user, 0, title_ptrs, borrowed_book_user_count);
                int book_flag = return_book(book_data, book_count, title_ptrs[book_option - 1]);
                system("cls");
                if (book_flag == 0)
                {
                    printf("You have three days.\n");
                }
                else if (book_flag == -1)
                {
                    printf("No copies available.\n");
                }
                else if (book_flag == -2)
                {
                    printf("Book not found.\n");
                }
                getch();
                screen_variable = user_screen;
            }
            else if (option == 3)
            {
                // Search menu
                char *search_options[] = {"Search by Title", "Search by Author", "Search by Year", "Back"};
                int search_choice = display_combined_box(Hi_message_user, 0, search_options, 4);
                if (search_choice == 4)
                {
                    // Back
                    continue;
                }

                char search_term[50];
                int found_indices[MAX_BOOKS];
                int found_count = 0;

                system("cls");
                printf("Enter search term: ");
                fflush(stdout);
                fgets(search_term, sizeof(search_term), stdin);
                // Remove trailing newline
                size_t len = strlen(search_term);
                if (len > 0 && search_term[len - 1] == '\n')
                    search_term[len - 1] = '\0';

                if (search_choice == 1)
                { // By Title
                    int idx = search_book_by_title(search_term, book_data, book_count);
                    if (idx != -1)
                    {
                        found_indices[found_count++] = idx;
                    }
                }
                else if (search_choice == 2)
                { // By Author
                    // search_book_by_author fills found_indices
                    search_book_by_author(search_term, book_data, book_count, found_indices);
                    // Count how many were found (stop at first -1 or until book_count)
                    for (int i = 0; i < book_count; i++)
                    {
                        if (found_indices[i] >= 0 && found_indices[i] < book_count)
                            found_count++;
                        else
                            break;
                    }
                }
                else if (search_choice == 3)
                { // By Year
                    search_book_by_year(search_term, book_data, book_count, found_indices);
                    for (int i = 0; i < book_count; i++)
                    {
                        if (found_indices[i] >= 0 && found_indices[i] < book_count)
                            found_count++;
                        else
                            break;
                    }
                }

                if (found_count == 0)
                {
                    printf("No books found.\n");
                    getch();
                    continue;
                }

                // Prepare titles for display
                char found_titles[MAX_BOOKS][50];
                char *found_title_ptrs[MAX_BOOKS];
                for (int i = 0; i < found_count; i++)
                {
                    strcpy(found_titles[i], book_data[found_indices[i]].title);
                    found_title_ptrs[i] = found_titles[i];
                }

                int sel = display_combined_box(Hi_message_user, 0, found_title_ptrs, found_count);
                if (sel > 0 && sel <= found_count)
                {
                    int idx = found_indices[sel - 1];
                    char selected_isbn[20];
                    strcpy(selected_isbn, book_data[idx].isbn); // Remember ISBN
                    system("cls");
                    printf("Book Details:\n");
                    printf("Title: %s\n", book_data[idx].title);
                    printf("Author: %s\n", book_data[idx].author);
                    printf("Year: %s\n", book_data[idx].published_year);
                    printf("ISBN: %s\n", book_data[idx].isbn);
                    getch();
                }
            }
            else if (option == 4)
            {
                screen_variable = start_screen;
            }
        }
    }
    return 0;
}
