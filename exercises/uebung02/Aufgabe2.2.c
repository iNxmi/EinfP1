#include <stdio.h>

int euclid(int a, int b)
{
    /* Ersetzte return 1 mit Lösung zu Aufgabe 2.1 falls bearbeitet*/
    return 1
}

void differenz(int zaehler_1, int nenner_1, int zaehler_2, int nenner_2) {
    /* Auszufüllen */
}

int main(void)
{
    int zaehler_1, nenner_1, zaehler_2, nenner_2;

    printf("Zaehler und Nenner des ersten Bruchs (durch Leerzeichen getrennt):\n");
    scanf("%d %d", &zaehler_1, &nenner_1);
    printf("Zaehler und Nenner des zweiten Bruchs (durch Leerzeichen getrennt):\n");
    scanf("%d %d", &zaehler_2, &nenner_2);

    /* Auszufüllen; Abfangen von Spezialfälle */

    differenz(zaehler_1, nenner_1, zaehler_2, nenner_2);
    return 0;
}