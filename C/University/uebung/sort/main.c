#include <stdio.h>

void exchange(int *i, int *j) {
    int temp = *i;
    *i = *j;
    *j = temp;
}

bubble_sort(int *arr, int l, int r) {
    int i,j, val;
    for (i = l; i < r; ++i) {
        for (j = r; j >= i; --j) {
            if (arr[j - 1] > arr[j]) {
                exchange(&arr[j], &arr[j - 1]);
            }
        }
    }
}

int main() {

    int array[] = {
    42, 17, 99, 5, 81, 
    23, 67, 11, 75, 34, 
    55, 1, 88, 12, 60, 
    3, 72, 45, 90, 27, 
    14, 69, 39, 8, 51, 
    93, 20, 78, 4, 30
};
    int size = sizeof(array)/sizeof(*array) - 1;

    bubble_sort(array, 0, size);

    printf("Sortiertes Array: ");
    for (int i = 0; i < size; ++i) {
        printf("%d, ", array[i]);
    }



    return 0;
}