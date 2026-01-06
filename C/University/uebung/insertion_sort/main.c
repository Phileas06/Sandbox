#include <stdio.h>

void insertion_sort(int *arr, int l, int r) {
    int i, j, current;

    for (i = l + 1; i < r; ++i) {
        current = arr[i];
        for (j = i - 1; j >= l; --j) {
            if (arr[j] > current) {
                arr[j+1] = arr[j];
            } else break;
        }
        arr[j+1] = current;

    }
}




int main() {
    int arr[] = {1,56,4564,6,856,64,43,23,42,65,7,56,745,23,25,3,879,78,54643,534534,23432};

    int size = sizeof(arr) / sizeof(*arr);

    insertion_sort(arr, 0 , size);


    printf("Geordnete Liste: ");
    for (int i = 0; i < size; ++i) {
        printf("%d, ", arr[i]);
    }

    return 0;
}