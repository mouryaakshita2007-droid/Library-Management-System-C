#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "books.h"
#include "members.h"
#include "utils.h"

int login() {
    char user[20], pass[20];

    printf("\n===== LOGIN =====\n");
    printf("Username: ");
    scanf("%s", user);

    printf("Password: ");
    scanf("%s", pass);

    if (strcmp(user, "admin") == 0 && strcmp(pass, "1234") == 0)
        return 1;
    else
        return 2;
}

void menu(int role) {
    printf("\n===== LIBRARY SYSTEM =====\n");

    if (role == 1) {
        printf("1.Add Book\n2.Display\n3.Search\n4.Add Member\n5.Issue\n6.Return\n7.Undo\n8.Delete\n9.Exit\n");
    } else {
        printf("1.Display\n2.Search\n3.Issue\n4.Return\n5.Exit\n");
    }

    printf("Enter choice: ");
}

int main() {
    int choice, role;

    loadBooks();
    loadMembers();

    role = login();

    while (1) {
        menu(role);
        scanf("%d", &choice);

        if (role == 1) {
            switch (choice) {
                case 1: addBook(); break;
                case 2: displayBooks(); break;
                case 3: searchBook(); break;
                case 4: addMember(); break;
                case 5: issueBook(); break;
                case 6: returnBook(); break;
                case 7: pop(); break;
                case 8: deleteBook(); break;
                case 9:
                    saveBooks();
                    saveMembers();
                    exit(0);
            }
        } else {
            switch (choice) {
                case 1: displayBooks(); break;
                case 2: searchBook(); break;
                case 3: issueBook(); break;
                case 4: returnBook(); break;
                case 5:
                    saveBooks();
                    exit(0);
            }
        }
    }
}