#ifndef GUI_H_INCLUDED
#define GUI_H_INCLUDED

/**********options*********/
  const char* start_menu[] = {
        "Login",
        "Sign up",
        "Exit",
    };

  const char* login_screen[] = {
        "Username:",
        "Password:",
        "back",
    };

  const char* Sign_up_screen[] = {
        "Username:",
        "Password:",
        "Repeat password:",
        "back",
    };

  const char* Admin_main_screen[] = {
        "add book",
        "delete book",
        "Search",
        "back",
    };

  const char* User_main_screen[] = {
        "borrow book",
        "return book",
        "Search",
        "back",
    };

  const char* Book_List_Screen[] = {
        "book1",
        "book2",
        "book3",
        "back",
    };

      const char* Return_List_Screen[] = {
        "book1",
        "book2",
        "book3",
        "back",
    };
      const char* book_properties_Screen[] = {
        "ISBM:",
        "Title:",
        "Auther:",
        "Public share:",
        "Number of copies:",
        "back",
    };



    const char* empty_array[]={NULL};





    const char* Are_you_sure[] =
    {
        "Yes",
        "No"
    };

/*************messages***************/

      const char* Hi_message [] =
    {
        "Hi Mohamed",
        "          "
    } ;
    const char* Are_You_sure_noselection [] =
    {
        "You have three days.",
        "Are you sure?",
        "  ","   "
    } ;
       const char* Return_message[] = {
        "thank you",
        "","","",
        "Fuck you",
    };

           const char* Books_number_message[] = {
        "Number of books",
        "",""
    }; /*if books are added or deleted*/

void gotoxy(int x, int y) ;
void ShowConsoleCursor(int showFlag) ;
int display_combined_box(const char* static_lines[], int static_count, const char* options[], int option_count) ;




#endif // GUI_H_INCLUDED
