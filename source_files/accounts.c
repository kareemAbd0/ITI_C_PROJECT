#include <string.h>
#include <stdio.h>
#include "../headers/file_handler.h"
#include "../headers/GUI.h"
#include "../headers/accounts.h"

void strip_newline(char *str)
{
    int len = strlen(str);
    if (len > 0 && str[len - 1] == '\n')
    {
        str[len - 1] = '\0';
    }
}

int login()
{

    char username[STRING_SIZE], password[STRING_SIZE];
    printf("please enter your username: \n");
    fgets(username, sizeof(username), stdin);
    strip_newline(username);

    printf("please enter your password: \n");
    fgets(password, sizeof(username), stdin);
    strip_newline(password);

    for (int i = 0; i < user_count; i++)
    {

        if (strcmp(username, user_data[i].username) == 0 &&
            strcmp(password, user_data[i].password) == 0)
        {

            if (user_data[i].is_admin)
            {
                //return 1 for admin
                return 1;
            }
            else
            {
                //return 0 for user
                return 0;
            }
        }
    }

    return -1;
}

int sign_up() {

    char username[STRING_SIZE], password[STRING_SIZE];
    printf("enter new username: \n");
    fgets(username, sizeof(username), stdin);
    strip_newline(username);

    for (int i = 0; i < user_count; i++) {

        if (strcmp(username, user_data[i].username) == 0) {

            return -1;
        }
    }

    printf("enter new password: \n");
    fgets(password, sizeof(password), stdin);
    strip_newline(password);

    strcpy(user_data[user_count].username, username);
    strcpy(user_data[user_count].password, password);
    user_data[user_count].is_admin = 0;
    user_count++;

    return 0;
}


