#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

List *createList(){
    List* list = (List*)malloc(sizeof(List));
    list->head = NULL;
    list->size = 0;
    return list;
}

void insertElement(List *list, void *data, int pos){
    if(list == NULL){
        return;
    }

    if(pos < 0 || pos > list->size){
        return;
    }

    Node* newNode = (Node*)malloc(sizeof(Node));
    if(!newNode){
        return;
    }

    newNode->data = data;
    newNode->next = NULL;

    if(pos == 0){
        newNode->next = list->head;
        list->head = newNode;
    }
    else{
        Node* current = list->head;
        for(int i = 0; i < pos - 1; i++){
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
    list->size++;
}

void deleteElement(List *list, int pos){
    if(list == NULL || pos < 0 || pos >= list->size){
        return;
    }

    Node *temp;
    if(pos == 0){
        temp = list->head;
        list->head = list->head->next;
    }
    else{
        Node *current = list->head;

        for(int i = 0; i < pos - 1; ++i){
            current = current->next;
        }
        
        temp = current->next;
        current->next = temp->next;
    }

    if(temp->data != NULL){
        free(temp->data);
        temp->data == NULL;
    }

    free(temp);
    list->size--;
}

int getSize(List *list){
    if(list == NULL){
        return -1;
    }
    return list->size;
}

void *getElement(List *list, int pos){
    if(list == NULL){
        return NULL;
    }

    if(pos < 0 || pos >= list->size){
        return NULL;
    }

    if(!list){
        return NULL;
    }

    Node *current = list->head;
    for(int i = 0; i < pos; ++i){
        current = current->next;
    }

    return current->data;
}

void destroyList(List *list){
    if(list == NULL){
        return;
    }

    Node *current = list->head;
    while(current){
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    free(list);
}
