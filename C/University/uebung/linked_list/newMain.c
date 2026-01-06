#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node, *nodeptr;

typedef struct List {
    nodeptr first, last;
} List, *listptr;


void initList(listptr L) {
    L->first = NULL;
    L->last = NULL;
}

nodeptr newNode(int data) {
    nodeptr np = (nodeptr)malloc(sizeof(Node));

    if (np == NULL) return NULL; //Prüfen ob Speichervergabe erfolgreich war


    np->data = data;
    np->next = NULL;
    return np;
}

void appendBehind(listptr L, int data) {
    nodeptr np = newNode(data);
    if (np == NULL) return;

    if (L->last == NULL) { // Liste ist leer
        L->first = np;
        L->last = np;
        return;
    }

    L->last->next = np;
    L->last = np;
}

void appendBegin(listptr L, int data) {
    nodeptr np = newNode(data);
    if (np == NULL) return;

    if (L->first == NULL) { // Liste ist leer
        L->first = np;
        L->last = np;
        return;
    }

    np->next = L->first;
    L->first = np;
}

int isEmpty(listptr L) {
    return (L->first == NULL && L->last == NULL);
}

void Delete(listptr L, int data) {
    nodeptr np1, np2;

    //Liste leer?
    if (isEmpty(L)) return;
    //Erstes Element?
    if (data == L->first->data) {
        nodeptr np = L->first;
        L->first = np->next;

        if (L->last == np) {
            //Liste jetzt leer
            L->first = L->last = NULL;
        }

        free(np);
        return;
    }

    np1 = L->first;
    np2 = np1->next;

    while (np2 != NULL) {
        if (np2->data == data) {
            np1->next = np2->next;

            if (L->last == np2) {
                L->last = np1;
            }
            free(np2);
            break;
        }
        np1 = np2;
        np2 = np2->next;
    }

}

int isIn(listptr L, int data) {
    if (isEmpty(L)) return 0;

    nodeptr np = L->first;
    while (np != NULL) {
        if (np->data == data) {
            return 1;
        }
        np = np->next;
    }

    return 0;
}

void insertBehind(listptr L, int find, int new) {
    if (isEmpty(L) || !isIn(L, find)) return;

    nodeptr np = L->first;
    while (np != NULL) {
        if (np->data == find) {
            nodeptr newNp = newNode(new);
            if (newNp == NULL) return;

            newNp->next = np->next;
            np->next = newNp;
            break;
        }
        np = np->next;
    }
}

int main() {

    List L;
    listptr lPtr = &L;
    initList(lPtr);

    appendBegin(lPtr, 5);
    appendBegin(lPtr, 4);
    appendBegin(lPtr, 3);
    appendBegin(lPtr, 2);
    appendBegin(lPtr, 1);

    Delete(lPtr, 2);

    insertBehind(lPtr, 3, 2);

    //Ausgeben
    nodeptr np = L.first;
    while (np != NULL) {
        printf(" > %d", np->data);
        np = np->next;
    }



    return 0;
}