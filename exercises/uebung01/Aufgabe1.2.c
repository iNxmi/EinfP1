/*************************************
* Beispielprogramm zur Vorlesung
* Einfuehrung in die Programmierung I
* Andreas Paffenholz
* TU Darmstadt, Wintersemester 2024/25
* (c) 2020-
* Collatz-Folge
* 
* Uebersetzen mit
* gcc collatz.c -o collatz
* Ausfuehren mit
* ./collatz
**************************************/

#include <stdio.h>

void collatz_folge(int c) {
    int laenge = 1;
    int gerade = 0;
    int ungerade = 0;

    printf("Die Collatzfolge zu %d ist\n%d ", c, c);

    /* Startwert mitzaehlen */
    if (c % 2 == 0) {
        gerade++;
    } else {
        ungerade++;
    }

    while (c != 1) {
        if (c % 2 == 0) {
            c = c / 2;
            gerade++;
        } else {
            c = 3 * c + 1;
            ungerade++;
        }
        laenge++;
        printf("%d ", c);
    }
    printf("\n");

    printf("Laenge: %d\n", laenge);
    printf("Gerade: %d\n", gerade);
    printf("Ungerade: %d\n", ungerade);
}

int main(void) {
    int startwert = 0;

    printf("Positive ganze Zahl: ");
    if (scanf("%d", &startwert) != 1 || startwert <= 0) {
        printf("Ungueltige Eingabe.\n");
        return 1;
    }

    collatz_folge(startwert);

    return 0;
}
