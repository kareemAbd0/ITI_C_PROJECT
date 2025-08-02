//
// Created by kareem on 8/2/25.
//

#ifndef ACCOUNTS_H
#define ACCOUNTS_H

#include"file_handler.h"


//searches if the user exists in the runtime array,checks password, goes to gui user menu if user and gui admin if admin
int login(Users *user_data);

//will add user to the runtime array, if the user already exists it will return -1, retruns to main menu upon success
int sign_up(Users *user_data);

//helper function to check if the user is admin or not
int is_admin(Users *user_data);




#endif //ACCOUNTS_H
