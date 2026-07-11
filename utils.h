#ifndef UTILS_H
#define UTILS_H

void push(char action[]);
void pop();
void enqueue(int id);
void dequeue();

extern struct Queue *front;

#endif