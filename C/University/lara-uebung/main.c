#include <stdio.h>
#include <stdlib.h>


int main() {

    int *speicherPlatz = (int*)calloc(1, sizeof(int));

    printf("%d", *speicherPlatz);

    free(speicherPlatz);

    return 0;
}