#include <stdio.h>
#include <string.h>
#include "books.h"

int calculateDays(struct Date d);
struct Book books[100];
int count = 0;

// Add Book
void addBook() {
    printf("Enter Book ID: ");
    scanf("%d", &books[count].id);

    printf("Enter Book Title: ");
    scanf(" %[^\n]", books[count].title);

    books[count].available = 1;

    // Initialize issue date
    books[count].issueDate.day = 0;
    books[count].issueDate.month = 0;
    books[count].issueDate.year = 0;

    count++;

    printf("\n Book added successfully!\n");
}

// Display Books
void displayBooks() {
    if (count == 0) {
        printf("\nNo books available.\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        printf("\nID: %d | Title: %s | Status: %s",
               books[i].id,
               books[i].title,
               books[i].available ? "Available" : "Issued");
    }
}

// Search Book
void searchBook() {
    int id, found = 0;

    printf("Enter Book ID to search: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (books[i].id == id) {
            printf("\n Book Found!\n");
            printf("ID: %d\nTitle: %s\n", books[i].id, books[i].title);
            found = 1;
            break;
        }
    }

    if (found == 0) {
        printf("\n Book not found!\n");
    }
}

// Issue Book
void issueBook() {
    int id, found = 0;

    printf("Enter Book ID to issue: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (books[i].id == id) {
            found = 1;

            if (books[i].available == 1) {

                printf("Enter Issue Date (dd mm yyyy): ");
                scanf("%d %d %d",
                      &books[i].issueDate.day,
                      &books[i].issueDate.month,
                      &books[i].issueDate.year);

                books[i].available = 0;

                printf("\n Book issued successfully!\n");

            } else {
                printf("\n Book already issued!\n");
            }

            break;
        }
    }

    if (found == 0) {
        printf("\n Book not found!\n");
    }
}
// Return Book
int calculateDays(struct Date d) {
    return d.year * 365 + d.month * 30 + d.day;
}
void returnBook() {
    int id, found = 0;

    printf("Enter Book ID to return: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (books[i].id == id) {
            found = 1;

            if (books[i].available == 0) {
                struct Date returnDate;

                printf("Enter Return Date (dd mm yyyy): ");
                scanf("%d %d %d",
                      &returnDate.day,
                      &returnDate.month,
                      &returnDate.year);

                int issueDays = calculateDays(books[i].issueDate);
                int returnDays = calculateDays(returnDate);

                int totalDays = returnDays - issueDays;
                int fine = 0;

                if (totalDays > 7) {
                    int extra = totalDays - 7;
                    fine = (extra / 7) * 5;

                    if (extra % 7 != 0)
                        fine += 5;
                }

                books[i].available = 1;

                printf("\n Book returned successfully!\n");
                printf("Days kept: %d\n", totalDays);

                if (fine > 0)
                    printf(" Fine: Rs. %d\n", fine);
                else
                    printf("No fine.\n");

            } else {
                printf("\n This book was not issued!\n");
            }

            break;
        }
    }

    if (found == 0) {
        printf("\n Book not found!\n");
    }
}

// Delete Book
void deleteBook() {
    int id, found = 0;

    printf("Enter Book ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (books[i].id == id) {
            found = 1;

            for (int j = i; j < count - 1; j++) {
                books[j] = books[j + 1];
            }

            count--;
            printf("\n Book deleted successfully!\n");
            break;
        }
    }

    if (found == 0) {
        printf("\n Book not found!\n");
    }
}

// Dummy load/save (you can improve later)
void loadBooks() {
    count = 0;
}

void saveBooks() {
    printf("\nData saved.\n");
}