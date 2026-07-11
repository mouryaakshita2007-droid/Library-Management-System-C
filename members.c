#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "members.h"

struct Member* head = NULL;

void addMember() {
    struct Member* newNode = malloc(sizeof(struct Member));

    printf("Enter Member ID: ");
    scanf("%d", &newNode->id);

    printf("Enter Name: ");
    scanf(" %[^\n]", newNode->name);

    newNode->next = head;
    head = newNode;

    printf("Member Added!\n");
}

void saveMembers() {
    FILE *fp = fopen("members.dat", "wb");
    if (!fp) return;

    struct Member *temp = head;
    while (temp) {
        fwrite(temp, sizeof(struct Member), 1, fp);
        temp = temp->next;
    }
    fclose(fp);
}

void loadMembers() {
    FILE *fp = fopen("members.dat", "rb");
    if (!fp) return;

    struct Member temp;
    while (fread(&temp, sizeof(struct Member), 1, fp)) {
        struct Member* newNode = malloc(sizeof(struct Member));
        *newNode = temp;
        newNode->next = head;
        head = newNode;
    }
    fclose(fp);
}