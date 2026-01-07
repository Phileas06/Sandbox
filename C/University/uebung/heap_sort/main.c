#include <stdio.h>

void exchange (int *a, int*b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}




void heap_sort(int *arr, int N) { //N ist größtes Element
    int i;
    for (i = N/2; i > 0; i--) { //Heap aufbauen
        sink(arr, i, N);
    }

    for (i = N; i > 1; i--) {
        exchange(arr[1], arr[i]); //Min ans aktuelle Heap-Ende setzen
    }
}

int main() {
    int arr[] = {0, 1234,2134,45,6,746,754,3245,2345,56,7678,567,456,24,2,34132,412,5425};

    size_t size = sizeof(arr) / sizeof(*arr);

    heap_sort(arr, 0, size-1);

    //Ausgeben
    printf("Sortiertes Array: ");
    for (int i = 0; i <= size; i++) {
        printf("%d, ", arr[i]);
    }

    return 0;
}