
//
// Created by kareem on 8/2/25.
//

#ifndef ACCOUNTS_H
#define ACCOUNTS_H
#include "file_handler.h"

#define STRING_SIZE 20


//searches if the user exists in the runtime array,checks password, returns 1 if admin 0 if user -1 if not found
int login();

//will add user to the runtime array, if the user already exists it will return -1, return 0 if succsess
int sign_up();





#endif //ACCOUNTS_H
