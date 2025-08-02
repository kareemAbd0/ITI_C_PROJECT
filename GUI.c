#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include "GUI.h"
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

        ch = getch();
        if (ch == -32) ch = getch();

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


int main(void) {
    int selection = display_combined_box(
        Hi_message,
        sizeof(Hi_message) / sizeof(Hi_message[0]),
        Admin_main_screen,
        sizeof(Admin_main_screen) / sizeof(Admin_main_screen[0])
    );

    /** for only messages */
    /*int selection = display_combined_box(
        Return_message,
        sizeof(Return_message) / sizeof(Return_message[0]),
        empty_array,
        0
    );*/
    gotoxy(40, 17);
    printf("You selected option %d: %s\n", selection, Admin_main_screen[selection - 1]);

    return 0;
}


