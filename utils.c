#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"

struct Stack {
    char action[50];
    struct Stack* next;
};

struct Queue {
    int memberId;
    struct Queue* next;
};

struct Stack* top = NULL;
struct Queue *front = NULL, *rear = NULL;

void push(char action[]) {
    struct Stack* newNode = malloc(sizeof(struct Stack));
    strcpy(newNode->action, action);
    newNode->next = top;
    top = newNode;
}

void pop() {
    if (!top) {
        printf("Nothing to undo!\n");
        return;
    }
    printf("Undo: %s\n", top->action);
    struct Stack* temp = top;
    top = top->next;
    free(temp);
}

void enqueue(int id) {
    struct Queue* newNode = malloc(sizeof(struct Queue));
    newNode->memberId = id;
    newNode->next = NULL;

    if (!rear) {
        front = rear = newNode;
        return;
    }
    rear->next = newNode;
    rear = newNode;
}

void dequeue() {
    if (!front) return;
    struct Queue* temp = front;
    front = front->next;
    free(temp);
}