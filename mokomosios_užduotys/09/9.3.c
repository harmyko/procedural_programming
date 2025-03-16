#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

typedef struct Point{
    double x;
    double y;
} Point;

typedef struct Stack{
    Point *ptr;
    int size;
} Stack;

void initStack(Stack *stack);
void printStack(Stack *stack);
int getStackSize(Stack *stack);
void push(Stack *stack, Point point);
Point top(Stack *stack);
Point pop(Stack *stack);
void destroyStack(Stack *stack);
double distance(Point point);

int main(){
    srand(time(0));
    Stack stack;
    stack.size = 0;
    initStack(&stack);
    Point point[5];
    for(int i = 0; i < 5; ++i){
        point[i].x = (((double)rand() / RAND_MAX) - 0.5) * 200.0;
        point[i].y = (((double)rand() / RAND_MAX) - 0.5) * 200.0;
        push(&stack, point[i]);
    }
    printStack(&stack);
    destroyStack(&stack);

    return 0;
}

void initStack(Stack *stack){
    stack->ptr = (Point*) calloc(stack->size, sizeof(Point));
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
            printf("point (%.3lf, %.3lf) is %.3lf distance away from (0, 0)\n", stack->ptr[i].x, stack->ptr[i].y, distance(stack->ptr[i]));
        }
    }
}

double distance(Point point){
    return sqrt(point.x * point.x + point.y * point.y);
}

int getStackSize(Stack *stack){
    return stack->size;
}

void push(Stack *stack, Point point){
    Point *temp = (Point*) realloc(stack->ptr, ++stack->size * sizeof(Point));
    if(temp == NULL){
        printf("Memory reallocation failed! Value couldn't be pushed to stack.\n");
        --stack->size;
        return;
    }
    stack->ptr = temp;
    stack->ptr[stack->size - 1] = point;
}

Point top(Stack *stack){
    return stack->ptr[stack->size - 1];
}

Point pop(Stack *stack){
    Point point = top(stack);
    stack->ptr = (Point*) realloc(stack->ptr, --stack->size * sizeof(Point));
    return point;
}

void destroyStack(Stack *stack){
    free(stack->ptr);
    stack->ptr = NULL;
    stack->size = 0;
}