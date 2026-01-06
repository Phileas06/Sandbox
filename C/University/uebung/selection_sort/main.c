#include <stdio.h>

void exchange(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selection_sort(int *arr, size_t l, size_t r)
{
    int i, j, min;

    for (i = l; i < r - 1; i++)
    {
        min = i;
        for (j = i + 1; j < r; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            };
        }
        exchange(&arr[min], &arr[i]);
    }
}

int main()
{
    int arr[] = {12342314, 234123, 42, 435, 5, 7564, 7324, 52345, 6547, 34, 122341, 456, 6547, 4578657, 8959867, 86547245, 43234124, 1};

    size_t size = sizeof(arr) / sizeof(*arr);

    selection_sort(arr, 0, size);

    // Ausgeben:
    printf("Sortiertes Array: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ,", arr[i]);
    }

    return 0;
}