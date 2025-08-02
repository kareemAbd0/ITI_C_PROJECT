//
// Created by kareem on 8/2/25.
//


#include <string.h>
#include"../headers/file_handler.h"
#include "../headers/GUI.h"
#include "../headers/accounts.h"
#include <stdio.h>




void strip_newline(char *str){
    int len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
	str[len - 1] = '\0';
    }
}



int login(Users *my_user_data) {

	int option = display_combined_box(empty_array, 0, login_screen, 4);

	const char *static_username_line[] = {"enter username",};
	const char *static_password_line[] = {"enter password",};
	const char *static_notfound_line[] = {"username or password incorrect",};
	char username[20];
	char password[20];

	while (option != 4){
		if (option == 1) {

			display_combined_box(static_username_line,1, empty_array, 0);
			fgets(username, sizeof(username),stdin);
			strip_newline(username); 
			display_combined_box(empty_array, 0, login_screen, 4);


		}else if (option == 2) {
			display_combined_box(static_password_line,1, empty_array, 0);
			fgets(password, sizeof(password), stdin);
			strip_newline(password);
			display_combined_box(empty_array, 0, login_screen, 4);
		}else if (option == 3) {

			strcpy(my_user_data->username, username);
			strcpy(my_user_data->password, password);


			for (int i = 0; i < user_count; i++) {

				if (strcmp(my_user_data->username, user_data[i].username) == 0) {

					if (strcmp(my_user_data->password, user_data[i].password) == 0) {

						int admin_status = user_data[i].is_admin;
						if (admin_status == 0) {

							return	display_combined_box(empty_array, 0, User_main_screen, 4);


						} else if (admin_status == 1) {

							return  display_combined_box(empty_array, 0, Admin_main_screen, 4);

						}


					}else{
						option = display_combined_box(static_notfound_line, 1, login_screen, 4);
						continue;
					}
				}
			}

			option = display_combined_box(static_notfound_line, 1, login_screen, 4);

		}
	}     

	return display_combined_box(empty_array, 0, start_menu, 3);

}




