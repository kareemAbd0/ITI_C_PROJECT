//
// Created by kareem on 8/2/25.
//


#include <string.h>
#include"../headers/file_handler.h"
#include "../headers/GUI.h"
#include "../headers/accounts.h"
#include <stdio.h>


int login(Users *my_user_data) {

    int option = display_combined_box(empty_array, 0, login_screen, 3);

    const char *static_username_line[] = {"enter username",};
    const char *static_password_line[] = {"enter password",};
    char username[20];

    if (option == 1) {

        display_combined_box(static_username_line,1, empty_array, 1);
        fgets(username, sizeof(username),stdin);
        strncpy(my_user_data->username, username, sizeof(my_user_data->username) - 1);
        int option = display_combined_box(empty_array, 0, login_screen, 3);


    }else if (option == 2) {



        fgets(my_user_data->password, sizeof(my_user_data->password), stdin);
    } else if (option == 3) {


    }

    for (int i = 0; i < user_count; i++) {

        if (strcmp(my_user_data->username, user_data[i].username) == 0) {

            if (strcmp(my_user_data->password, user_data[i].password) == 0) {

                int admin_status = user_data[i].is_admin;
                if (admin_status == 0) {

                    display_combined_box(empty_array, 1, User_main_screen, 4);

                } else if (admin_status == 1) {

                    display_combined_box(empty_array, 1, Admin_main_screen, 4);

                } else {

                    return -1;

                }
            }else{}
        }
    }
}
