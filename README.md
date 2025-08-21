# ITI_C_PROJECT

## Overview

This is a C-based library management system developed as part of the ITI program. The project allows users to manage books, user accounts, and borrowing operations through a simple command-line interface.

## Features

- User account management (create, delete, authenticate)
- Book management (add, remove, search, list)
- Borrow and return books
- Persistent data storage using text files
- Simple text-based GUI

## Project Structure

```
main.c
headers/
    accounts.h
    application.h
    book_ops.h
    file_handler.h
    GUI.h
source_files/
    accounts.c
    application.c
    book_ops.c
    file_handler.c
    GUI.c
data/
    books.txt
    borrowed_books.txt
    users.txt
```

- `main.c`: Entry point of the application.
- `headers/`: Header files for each module.
- `source_files/`: Implementation files for each module.
- `data/`: Text files for storing books, users, and borrowed books data.

## How to Build

1. Make sure you have a C compiler (e.g., GCC) installed.
2. Compile the project using the following command in PowerShell:

   ```
   gcc main.c source_files/*.c -o library_app
   ```

3. Run the application:

   ```
   .\library_app.exe
   ```

## Usage

Follow the on-screen instructions to:
- Log in or create a new user account
- Add, search, or remove books
- Borrow or return books

## License

This project is for educational purposes.
