#include <stdio.h>
#include <limits.h>

int primfaktorzerlegung(int zahl, int faktoren[], int vielfachheiten[]) {
    int anzahl = 0;

    /* auszufüllen */

    int p = 2;
    int n = zahl;
    int vorkommen = 0;

    int check = 2;

    /* Checken ob Zahl eine primzahl ist */
    if (zahl == 1 || zahl == 2) {
        faktoren[0] = zahl;
        vielfachheiten[0] = 1;
        return 1;
    }

    while ((check*check) <= n) {
        if (n % check == 0) {
            break;
        }
        if ((check+1)*(check+1) > n ) {
            faktoren[0] = zahl;
            vielfachheiten[0] = 1;
            return 1;
        }
        check++;
    }
    /* Ende vom check */

    do {
        if (n % p == 0) {
            n = n/p;
            faktoren[anzahl] = p;
            vorkommen++;
        }
        else {
            if (p == 2)
                p = 3;
            else {
                p = p + 2;
            }
            vielfachheiten[anzahl] = vorkommen;
            anzahl++;
            vorkommen = 0;
        }
    } while ((p*p) <= n);

    if (n > 1) {
        faktoren[anzahl] = n;
        vielfachheiten[anzahl] = 1;
        anzahl++;
    }

    return anzahl;
}

void primfaktorzerlegung_ausgeben(int zahl, int faktoren[], int vielfachheiten[], int anzahl) {
    int start = 1;
    for (int i = 0; i < anzahl; i++) {
        if (!start) {
            printf(" * ");
        } else {
            start = 0;
        }
        printf("%d", faktoren[i]);
        if (vielfachheiten[i] > 1) {
            printf("^%d", vielfachheiten[i]);
        }
    }
    printf("\n");
}

int main(void) {
    int zahl;
    printf("Geben Sie eine ganze Zahl für die Primfaktorzerlegung ein\n");
    scanf("%d", &zahl);
    printf("Primfaktorzerlegung\n");

    // Das Array faktoren hat genug Platz für alle Primfaktoren der Zahl.
    // Erläuterung dazu kommt später.
    int faktoren[sizeof(int) * CHAR_BIT];
    int vielfachheiten[sizeof(int) * CHAR_BIT];
    int anzahl = primfaktorzerlegung(zahl, faktoren, vielfachheiten);
    primfaktorzerlegung_ausgeben(zahl, faktoren, vielfachheiten, anzahl);

    return 0;
}