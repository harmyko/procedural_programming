#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct Node{
    void *data;
    struct Node *next;
} Node;

typedef struct List{
    Node *head;
    int size;
} List;

List *createList();
void insertElement(List *list, void *data, int pos);
void deleteElement(List *list, int pos);
int getSize(List *list);
void *getElement(List *list, int pos);
void destroyList(List *list);

#endif