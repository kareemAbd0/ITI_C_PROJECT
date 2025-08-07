#include <string.h>
#include <stdio.h>
#include <stdlib.h>
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
                strcpy(current_user_id,user_data[i].id);
                return 1;
            }
            else
            {
                //return 0 for user
                strcpy(current_user_id,user_data[i].id);
                return 0;
            }
        }
    }

    return -1;
}

int sign_up() {
    int prev_id;
    int id;
    char id_str[20];
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

    Users user;
    strcpy(user.username,username);
    strcpy(user.password,password);
    prev_id = atoi(user_data[user_count -1].id);
    id = prev_id + 100;
    itoa(id, id_str, 10);
    strcpy(user.id,id_str);
    user.is_admin = 0;

    user_add(&user);
    


    return 0;
}


