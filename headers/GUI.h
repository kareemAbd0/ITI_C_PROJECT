#ifndef GUI_H_INCLUDED
#define GUI_H_INCLUDED

extern char* start_menu[];
extern char* login_screen[];
extern char* Sign_up_screen[];
extern char* Admin_main_screen[];
extern char* User_main_screen[];
extern char* Book_List_Screen[];
extern char* Return_List_Screen[];
extern char* book_properties_Screen[];
extern char* empty_array[];
extern char* Are_you_sure[];
extern char* Hi_message_admin[];
extern char* Hi_message_user[];
extern char* Are_You_sure_noselection[];
extern char* Return_message[];
extern char* Books_number_message[];

void gotoxy(int x, int y) ;
void ShowConsoleCursor(int showFlag) ;
int display_combined_box( char* static_lines[], int static_count,  char* options[], int option_count) ;




#endif // GUI_H_INCLUDED