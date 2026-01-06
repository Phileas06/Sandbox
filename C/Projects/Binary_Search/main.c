#include <stdio.h>

int binary_search(int Array[], int gesucht,  int r, int l, int* zaehler) {

    int currentIndex;
    while (r >= l) {
        (*zaehler)++;
        currentIndex = l + (r-l)/2;
        if (Array[currentIndex] == gesucht) {
            return currentIndex;
        }
        if (Array[currentIndex] < gesucht) {
            l = currentIndex + 1;
        } else {
            r = currentIndex - 1;
        }
    }

    return -1;
}

int main() {
    int zaehler = 0;
    int Array[] = {2,5,9,18,23,34,36,99};
int index = binary_search(Array, 99, 0, sizeof(Array) / sizeof(Array[0]), &zaehler);

    printf("Gefunden: %d", Array[index]);
    return 0;
}