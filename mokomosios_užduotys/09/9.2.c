#include <stdio.h>
#include <stdlib.h>

typedef struct Stack{
    int *ptr;
    int size;
} Stack;

void initStack(Stack *stack);
void printStack(Stack *stack);
int getStackSize(Stack *stack);
void push(Stack *stack, int value);
int top(Stack *stack);
int pop(Stack *stack);
void destroyStack(Stack *stack);

int main(){
    Stack stack;
    stack.size = 5;
    initStack(&stack);
    printf("stack: \n");
    printStack(&stack);
    printf("stack size: %d\n", getStackSize(&stack));
    push(&stack, 754);
    printf("stack: \n");
    printStack(&stack);
    printf("top stack element: %d\n", top(&stack));
    printf("stack size: %d\n", getStackSize(&stack));
    pop(&stack);
    printf("stack: \n");
    printStack(&stack);
    destroyStack(&stack);
    printf("stack: \n");
    printStack(&stack);
    printf("top stack element: %d\n", top(&stack));

    return 0;
}

void initStack(Stack *stack){
    stack->ptr = (int*) calloc(stack->size, sizeof(int));
    if(stack->ptr == NULL){
        printf("Memory allocation failed!\n");
    }
}

void printStack(Stack *stack){
    if(stack->size == 0){
        printf("Stack has no elements.\n");
    }
    else{
        for(int i = 0; i < stack->size; ++i){
            printf("%d\n", stack->ptr[i]);
        }
    }
}

int getStackSize(Stack *stack){
    return stack->size;
}

void push(Stack *stack, int value){
    int *temp = (int*) realloc(stack->ptr, ++stack->size * sizeof(int));
    if(temp == NULL){
        printf("Memory reallocation failed! Value couldn't be pushed to stack.\n");
        --stack->size;
        return;
    }
    stack->ptr = temp;
    stack->ptr[stack->size - 1] = value;
}

int top(Stack *stack){
    if(stack->ptr == NULL){
        return 0;
    }
    return stack->ptr[stack->size - 1];
}

int pop(Stack *stack){
    int value = top(stack);
    stack->ptr = (int*) realloc(stack->ptr, --stack->size * sizeof(int));
    return value;
}

void destroyStack(Stack *stack){
    free(stack->ptr);
    stack->ptr = NULL;
    stack->size = 0;
}