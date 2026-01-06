#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct queue {
    int elems[MAX];
    int start, end;
} Queue, *queueptr;

void initQueue(queueptr q) {
    q->start = 0;
    q->end = 1;
};

int isEmpty(queueptr q) {
    return (q->end == q->start);
}

void push(queueptr q, int data) {
    if (q->start == q->end) { //Queue voll!
        printf("Queue voll!");
        return;
    }

    q->elems[q->end] = data;
    q->end = (q->end + 1) % MAX;
}

int pop(queueptr q) {


    q->start = (q->start + 1) % MAX;

    if (isEmpty(q)) {
        printf("Queue leer!");   
        return INT_MIN;
    }

    int val = q->elems[q->start];

    return val;
}

int main() {

    queueptr q = malloc(sizeof(Queue));
    initQueue(q);

    push(q, 10);
    push(q, 110);
    push(q, 0);
    push(q, 20);
    push(q, 30);

    int val = pop(q);
    printf("%d\n", val);
    val = pop(q);
    printf("%d\n", val);
    val = pop(q);
    printf("%d\n", val);
    val = pop(q);
    printf("%d\n", val);
    val = pop(q);
    printf("%d\n", val);
    val = pop(q);
    printf("%d\n", val);


    

    return 0;
}