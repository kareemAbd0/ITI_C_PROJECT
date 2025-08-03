#include <stdio.h>
#include <string.h>
#include "headers/GUI.h"

#include "headers/file_handler.h"
#include "headers/accounts.h"


int main(void) {
    printf("Hello, World!\n");


    user_count = 5;
    

    strcpy(user_data[3].username, "kareem");
    strcpy(user_data[3].password, "pass");
    user_data[3].is_admin = 0;
  


            int result;

            //result = login();
            // if(result == -1){

            //     printf("incorrect username or password");
            // }else if (result == 1){


            //     printf("admin");

            // }else if (result == 0){

            //     printf("user");
            // }

            result = sign_up();

            if(result == -1){
                printf("user exists");
            }else if (result == 0){
                printf("sign up completed");
            }




        

            

   
    return 0;
}
