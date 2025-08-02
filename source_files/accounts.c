#include <string.h>
#include <stdio.h>
#include "../headers/file_handler.h"
#include "../headers/GUI.h"
#include "../headers/accounts.h"

void strip_newline(char *str) {
    int len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

int login(Users *my_user_data) {
    char username[20] = "";
    char password[20] = "";

    const char *static_username_line[] = {"Enter username:"};
    const char *static_password_line[] = {"Enter password:"};
    const char *static_notfound_line[] = {"Username or password incorrect."};

    int option = display_combined_box(empty_array, 0, login_screen, 4);

    while (option != 4) {
        if (option == 1) {
            // Input username
            display_combined_box(static_username_line, 1, empty_array, 0);
            fgets(username, sizeof(username), stdin);
            strip_newline(username);

        } else if (option == 2) {
            // Input password
            display_combined_box(static_password_line, 1, empty_array, 0);
            fgets(password, sizeof(password), stdin);
            strip_newline(password);

        } else if (option == 3) {
            // Attempt login
            strcpy(my_user_data->username, username);
            strcpy(my_user_data->password, password);

            int found = 0;
            for (int i = 0; i < user_count; i++) {
                if (strcmp(username, user_data[i].username) == 0 &&
                    strcmp(password, user_data[i].password) == 0) {
                    found = 1;

                    if (user_data[i].is_admin) {
                        return display_combined_box(empty_array, 0, Admin_main_screen, 4);
                    } else {
                        return display_combined_box(empty_array, 0, User_main_screen, 4);
                    }
                }
            }

            if (!found) {
                option = display_combined_box(static_notfound_line, 1, login_screen, 4);
                continue;
            }
        }

        option = display_combined_box(empty_array, 0, login_screen, 4);
    }

    // If user chose to go back
    return display_combined_box(empty_array, 0, start_menu, 3);
}
