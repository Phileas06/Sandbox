#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    struct Node* next;
    int data;
} *nodeptr, Node;

typedef struct List {
    nodeptr first, last;
} *listptr, List;

void initList(listptr L) {
    L->first = NULL;
    L->last = NULL;
}

nodeptr newNode(int data) {
    nodeptr np = malloc(sizeof(Node));
    if (np == NULL) return NULL; //Fehler bei der Speichervergabe

    return np;
}

int isEmpty(listptr L) {
    return (L->first == NULL && L->last == NULL);
}

void push(listptr L, int data) {
    nodeptr np = newNode(data);
    if (np == NULL) return;

    np->data = data;
    np->next = L->first;
    L->first = np;
}

int pop(listptr L) {
    if (isEmpty(L)) return INT_MIN;

    nodeptr np = L->first;
    int data = L->first->data;

    if (np == L->last) {
        L->first = L->last = NULL;
    } else {
        L->first = L->first->next;
    }

    free(np);

    return data;
}



int main() {

    List L;
    listptr lPtr = &L;
    initList(lPtr);

    push(lPtr, 1);
    push(lPtr, 3);
    push(lPtr, 6);
    push(lPtr, 4);
    push(lPtr, 0);
    push(lPtr, 3);

    printf("%d\n", pop(lPtr));
    printf("%d\n", pop(lPtr));
    printf("%d\n", pop(lPtr));
    printf("%d\n", pop(lPtr));
    printf("%d\n", pop(lPtr));
    printf("%d\n", pop(lPtr));
    printf("%d\n", pop(lPtr));
    printf("%d\n", pop(lPtr));


    return 0;
}