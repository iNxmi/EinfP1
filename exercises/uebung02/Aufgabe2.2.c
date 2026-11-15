#include <stdio.h>

int euclid(int a, int b)
{
    int swap = 0;
    while (1) {
        if (b <= a) {
            swap = a;
            a = b;
            b = swap;
        }
        
        if (b % a == 0) {
            return a;
        }
        b = b % a;
    }
}

void differenz(int zaehler_1, int nenner_1, int zaehler_2, int nenner_2) {
    int zaehler_diff = zaehler_1 * nenner_2 - zaehler_2 * nenner_1;
    int nenner_diff = nenner_1 * nenner_2;

    if (nenner_diff < 0) {
        zaehler_diff = -zaehler_diff;
        nenner_diff = -nenner_diff;
    }

    if (zaehler_diff == 0) {
        printf("0 1\n");
        return;
    }

    int abs_zaehler = zaehler_diff;
    if (abs_zaehler < 0) {
        abs_zaehler = -abs_zaehler;
    }

    int ggt = euclid(abs_zaehler, nenner_diff);
    zaehler_diff = zaehler_diff / ggt;
    nenner_diff = nenner_diff / ggt;

    printf("%d %d\n", zaehler_diff, nenner_diff);
}

int main(void)
{
    int zaehler_1, nenner_1, zaehler_2, nenner_2;

    printf("Zaehler und Nenner des ersten Bruchs (durch Leerzeichen getrennt):\n");
    if (scanf("%d %d", &zaehler_1, &nenner_1) != 2) {
        printf("Invalide Eingabe.\n");
        return 0;
    }
    printf("Zaehler und Nenner des zweiten Bruchs (durch Leerzeichen getrennt):\n");
    if (scanf("%d %d", &zaehler_2, &nenner_2) != 2) {
        printf("Invalide Eingabe.\n");
        return 0;
    }

    if (nenner_1 == 0 || nenner_2 == 0) {
        printf("Nenner darf nicht gleich 0 sein.\n");
        return 0;
    }

    differenz(zaehler_1, nenner_1, zaehler_2, nenner_2);

    return 0;
}