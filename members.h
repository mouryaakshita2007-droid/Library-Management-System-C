#ifndef MEMBERS_H
#define MEMBERS_H

struct Member {
    int id;
    char name[50];
    struct Member* next;
};

extern struct Member* head;

void addMember();
void saveMembers();
void loadMembers();

#endif