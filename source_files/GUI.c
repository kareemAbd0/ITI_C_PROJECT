#include "../headers/GUI.h"
//#include <conio.h>
#include <stdio.h>
#include <windows.h>


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



const char* empty_array[]={" "};



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
    "you are late",
};

const char* Books_number_message[] = {
    "Number of books",
    "",""
}; /*if books are added or deleted*/




void gotoxy(int x, int y) {
    COORD coord = {0, 0};
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void ShowConsoleCursor(int showFlag) {
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = showFlag;
    SetConsoleCursorInfo(out, &cursorInfo);
}

// Combined static + interactive box
int display_combined_box(const char* static_lines[], int static_count, const char* options[], int option_count) {
    char ch;
    int pos = 1;
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    ShowConsoleCursor(0);

    int content_width = 33;
    int box_left = 39;
    int box_top = 5;
    int total_lines = static_count + option_count;
    int box_bottom = box_top + total_lines + 1;

    // Draw top border
    gotoxy(box_left, box_top);
    printf("%c", 201);
    for (int i = 0; i < content_width; i++) printf("%c", 205);
    printf("%c", 187);

    // Draw all lines (static + menu options)
    for (int i = 0; i < total_lines; i++) {
        gotoxy(box_left, box_top + 1 + i);
        printf("%c", 186);
        for (int j = 0; j < content_width; j++) printf(" ");
        printf("%c", 186);
    }

    // Draw bottom border
    gotoxy(box_left, box_bottom);
    printf("%c", 200);
    for (int i = 0; i < content_width; i++) printf("%c", 205);
    printf("%c", 188);

    do {
        // Print static lines normally
        SetConsoleTextAttribute(console, 15);
        for (int i = 0; i < static_count; i++) {
            gotoxy(box_left + 1, box_top + 1 + i);
            printf(" %-*s", content_width - 1, static_lines[i]);
        }

        // Print options (with selection)
        for (int i = 0; i < option_count; i++) {
            gotoxy(box_left + 1, box_top + 1 + static_count + i);
            SetConsoleTextAttribute(console, (pos == i + 1) ? 240 : 15);
            printf(" %d] %-*s", i + 1, content_width - 5, options[i]);
        }

        ch = getchar();
        if (ch == -32) ch = getchar();

        if (ch == 72) {  // Up
            pos--;
            if (pos < 1) pos = option_count;
        } else if (ch == 80) {  // Down
            pos++;
            if (pos > option_count) pos = 1;
        }

    } while (ch != 13);

    SetConsoleTextAttribute(console, 15);
    return pos;
}


