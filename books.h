#ifndef BOOKS_H
#define BOOKS_H

struct Date {
    int day, month, year;
};

struct Book {
    int id;
    char title[50];
    int available;
    struct Date issueDate;   // NEW
};

extern struct Book books[100];
extern int count;

void addBook();
void displayBooks();
void searchBook();
void deleteBook();
void issueBook();
void returnBook();
void loadBooks();
void saveBooks();

#endif