#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "linked_list.h"

int main(){
    List *list = NULL;

    assert((list = createList()) != NULL);
    printf("createList function successful\n");

    int *element1 = (int *)malloc(sizeof(int));
    int *element2 = (int *)malloc(sizeof(int));
    int *element3 = (int *)malloc(sizeof(int));

    if(element1 == NULL || element2 == NULL || element3 == NULL){
        printf("Memory allocation failed.\n");
        return 1;
    }

    *element1 = 123;
    *element2 = 12;
    *element3 = 3;

    insertElement(list, element1, 0);
    assert(getSize(list) == 1);
    insertElement(list, element2, 1);
    assert(getSize(list) == 2);
    insertElement(list, element3, 2);
    assert(getSize(list) == 3);
    printf("insertElement and getSize functions successful\n");

    assert(getElement(list, 2) == element3);
    assert(getElement(list, 1) == element2);
    assert(getElement(list, 0) == element1);
    printf("getElement function successful\n");

    deleteElement(list, 1);
    assert(getElement(list, 1) == element3);
    printf("deleteElement function successful\n");

    destroyList(list);
    printf("destroyList function successful\n");

    return 0;
}