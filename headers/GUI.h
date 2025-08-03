#ifndef GUI_H_INCLUDED
#define GUI_H_INCLUDED

extern const char* start_menu[];
extern const char* login_screen[];
extern const char* Sign_up_screen[];
extern const char* Admin_main_screen[];
extern const char* User_main_screen[];
extern const char* Book_List_Screen[];
extern const char* Return_List_Screen[];
extern const char* book_properties_Screen[];
extern const char* empty_array[];
extern const char* Are_you_sure[];
extern const char* Hi_message_admin[];
extern const char* Hi_message_user[];
extern const char* Are_You_sure_noselection[];
extern const char* Return_message[];
extern const char* Books_number_message[];

void gotoxy(int x, int y) ;
void ShowConsoleCursor(int showFlag) ;
int display_combined_box(const char* static_lines[], int static_count, const char* options[], int option_count) ;




#endif // GUI_H_INCLUDED