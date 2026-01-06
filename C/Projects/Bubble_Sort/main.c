#include <stdio.h>

void insertion_sort(int Arr[], int l, int r) {
    int v, i, j;
    for (i = l; i <= r; i++) {
        v = Arr[i];
        for (j = i-1; j >= l; --j) {
            if (v < Arr[j]) {
                Arr[j + 1] = Arr[j];
            } else break;
        }
        Arr[j + 1] = v;
    }
}

int main() {

    int Array[] = {71, 21, 35, 72, 43, 25, 45, 80};

    insertion_sort(Array, 0, sizeof(Array)/sizeof(Array[0]) - 1);

    printf("Sortierter Array: ");
    for (int i = 0; i < sizeof(Array) / sizeof(Array[0]); i++) {
        printf("%d, ", Array[i]);
    }

    return 0;
}