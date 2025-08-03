#include <stdio.h>
#include <string.h>
#include "headers/GUI.h"

#include "headers/file_handler.h"
#include "headers/accounts.h"

enum steps
{
    start_screen = 1,admin_screen,user_screen

};

int main(void) 
{ 
    int screen_variable = 1;
    int option = 0,flag = 0;

     while(1){

        if(screen_variable == start_screen)
        {
         option = display_combined_box(empty_array,0,start_menu,3);
            if(option == 1){
                system("cls");
                flag = login();
                if(flag == 1)
                    screen_variable = admin_screen;
                else if(flag == 0)
                    screen_variable = user_screen;


            }else if(option == 2){
                system("cls");
                 flag = sign_up();
                 screen_variable = start_screen;
            }else
            {

                return 0;
            }
            if(flag == -1)
            {
                screen_variable = start_screen;
                continue;
            } 
        }
       else if(screen_variable == admin_screen)
        {
         option = 0;
         option = display_combined_box(Hi_message_admin,2,Admin_main_screen,4);
            if(option == 1)
            {
                //add book scenario
            }
            else if(option == 2)
            {
                //delete book scenario
            }
            else if(option == 3)
            {
                //search book scenario
            }
            else if(option == 4)
            {
                screen_variable = start_screen;
            }
        }
       else if(screen_variable == user_screen)
        {
         option = 0;
         option = display_combined_box(Hi_message_user,2,User_main_screen,4);
            if(option == 1)
            {
                //add book scenario
            }
            else if(option == 2)
            {
                //delete book scenario
            }
            else if(option == 3)
            {
                //search book scenario
            }
            else if(option == 4)
            {
                screen_variable = start_screen;
            }
        }
     }
    return 0;
}
