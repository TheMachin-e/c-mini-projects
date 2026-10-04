# Student Record Management System

A simple **Student Record Management System written in C** using a singly linked list.

The project was created to practice C programming concepts such as structures, pointers, dynamic memory allocation, linked lists, file handling, modular programming, and Makefiles.

## Features

- Add student records
- Display all student records
- Delete records
- Modify student records
- Save records to a file
- Load records from a file
- Delete all records
- Sort records
- Reverse the linked list
- Reuse deleted roll numbers
- Basic input validation
- Modular source files
- Build using Makefile

## Project Structure

```text
students_record_management_system/
├── Makefile
├── README.md
└── src/
    ├── stud_main.c
    ├── stud_add.c
    ├── stud_show.c
    ├── stud_del.c
    ├── stud_file.c
    └── student.h

## Concepts Practiced

1. **Structures and `typedef`**
2. **Pointers and pointer-to-pointer**
3. **Singly linked lists**
4. **Dynamic memory allocation**
   - `malloc()`
   - `calloc()`
   - `free()`
5. **File handling**
   - `fopen()`
   - `fprintf()`
   - `fscanf()`
   - `fclose()`
6. **Input validation**
7. **Functions and modular programming**
8. **Header files and include guards**
9. **Makefiles**
10. **Object files and linking**
11. **Basic Git workflow**

## Future Improvements

1. Improve `scanf()` input handling and handle invalid input without getting stuck in input loops.
2. Replace problematic `scanf()` usage with safer input handling using `fgets()` and appropriate parsing.
3. Handle malformed or corrupted records in `student.dat`.
4. Improve error handling for file operations.
5. Add better validation for names, roll numbers, and percentages.
6. Implement linked-list sorting using **merge sort**.
7. Improve the user interface and menu formatting.
8. Add search functionality by name and roll number.
9. Prevent duplicate roll numbers.
10. Add confirmation before deleting all records.
11. Improve memory allocation failure handling.
12. Add automatic header dependency generation to the Makefile.
13. Add more comprehensive testing for edge cases.
