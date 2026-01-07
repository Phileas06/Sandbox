#include "stdio.h"

void insertion_sort(int *arr, int l, int r)
{
    int i, j, current;
    for (i = l + 1; i <= r; i++)
    {
        current = arr[i];
        for (j = i - 1; j >= l; j--)
        {
            if (arr[j] > current)
            {
                arr[j + 1] = arr[j];
            }
            else
                break;
        }
        arr[j + 1] = current;
    }
}

int main()
{
    int numbers[] = {42, 7, 120, 1, 33, 89, 4, 15, 22, 10};

    size_t size = sizeof(numbers) / sizeof(*numbers);

    insertion_sort(numbers, 0, size - 1);

    // Ausgeben
    printf("Unsortiertes Array");
    for (int i = 0; i < size; i++)
    {
        printf("%d, ", numbers[i]);
    }

    return 0;
}