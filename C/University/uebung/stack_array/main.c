#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct stack {
    int elems[MAX_SIZE];
    int top;
} Stack, *stackptr;

void initStack(stackptr stack) {
    stack->top = 0;
}

void push(stackptr stack, int data) {
    if (stack->top == MAX_SIZE) {
        printf("Stack voll!");
        return;
    }

    stack->elems[stack->top] = data;
    ++(stack->top);
}

int pop(stackptr stack) {
    if (stack->top == 0) { //Stack leer
        printf("Stack ist leer!");      
        return INT_MIN;
    }
    --(stack->top);
    return stack->elems[stack->top];
}




int main() {

    Stack myStack;

    stackptr myStackPtr = &myStack;
    initStack(myStackPtr);

    push(myStackPtr, 70);
    push(myStackPtr, 50);
    push(myStackPtr, 40);
    push(myStackPtr, 30);
    push(myStackPtr, 20);
    push(myStackPtr, 1);
    int val;
     val = pop(myStackPtr); 
    printf("%d", val);
     val = pop(myStackPtr); 
    printf("%d", val);
     val = pop(myStackPtr); 
    printf("%d", val);
     val = pop(myStackPtr); 
    printf("%d", val);
     val = pop(myStackPtr);
        printf("%d", val);

    printf("%d", val);

    return 0;
}