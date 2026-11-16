#include <stdio.h>          /* <> für Header der Standardbibliothek */

#include "selectionsort.h"  /* "" für eigene Header im selben Verzeichnis */

void print_array(int n, const int *arr) {
    for (int i = 0; i < n; i++) {
        printf("%d\n", arr[i]);
    }
}

int main(void) {
    int arr[] = {200, 34, -51, 16, 12, 123, 54, -34, 0};
    int n = sizeof(arr) / sizeof(arr[0]);

    selectionsort(n, arr);
    print_array(n, arr);

    return 0;
}
