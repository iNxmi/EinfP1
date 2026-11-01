#include <stdio.h>

int einfaches_querprodukt(int startzahl) {
    if (startzahl < 10){
        return startzahl;
    }

    int temporary = startzahl;

    int result = temporary % 10;
    temporary /= 10;

    while (temporary > 0) {
        const int digit = temporary % 10;
        result *= digit;

        temporary /= 10;
    }

    return result;
}

int totales_querprodukt(int zahl) {
    int result = zahl;

    while (result >= 10) {
        result = einfaches_querprodukt(result);
        printf("Totales Querprodukt zwischenergebnis: %d\n", result);
    }

    return result;
}

int main () {
    int startzahl;

    printf("Start zahl: ");
    if (scanf("%d", &startzahl) != 1 || startzahl < 0) {
        printf("Ungueltige Eingabe.\n");
        return 1;
    }

    printf("Das totale Querprodukt der Ziffern ist %d \n", totales_querprodukt(startzahl));
    return 0;
}

