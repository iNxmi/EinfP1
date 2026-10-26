#include <stdio.h>
#include <limits.h>

int primfaktorzerlegung(int zahl, int faktoren[], int vielfachheiten[]) {
    int anzahl = 0;

    /* auszufüllen */

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