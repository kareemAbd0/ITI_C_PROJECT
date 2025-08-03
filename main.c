#include <stdio.h>
#include <string.h>
#include "headers/GUI.h"

#include "headers/file_handler.h"
#include "headers/accounts.h"



int main(void) {
     while(1){
        main_menu:{
            int option = display_combined_box(empty_array,0,start_menu,3);
            if(option == 1){
                goto login;
            }else if(option == 2){
                goto sign_up;
            }else{
                return 0;
            }
        }

        login:{
            int option = display_combined_box(empty_array,0,login_screen,4);
            if(option == 4) {
                goto main_menu;
            }
        }

        sign_up:{
            int option = display_combined_box(empty_array,0,Sign_up_screen,4);
            goto main_menu;
        }


     }
    return 0;
}

