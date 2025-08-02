#include <stdio.h>
#include "headers/file_handler.h"
#include "headers/accounts.h"

int main(void) {
    printf("Hello, World!\n");

    Users *my_user_data = {0}; // Initialize user data
    login(my_user_data);
    return 0;
}