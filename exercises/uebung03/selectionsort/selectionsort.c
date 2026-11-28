#include <stdlib.h>
#include "selectionsort.h"
/* In selectionsort.c the function selectionsort is defined
Therefore, in this case here, it is not strictly necessary
to include selectionsort.h which declares the function (assigns memory).
Nevertheless, it is good practice to always include the header file
for consistency, error checking and maintainability.*/

void selectionsort(int n, int *arr) {
    //die indizes in der aufgabe waren bait, weil die mit 1 und nicht mit 0 anfangen, 1 minute lebenszeit verschwendet lul
    for (int i = 0; i < n - 1 ; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        if (min != i) {
            int swap = arr[i];
            arr[i] = arr[min];
            arr[min] = swap;
        }
    }
}
