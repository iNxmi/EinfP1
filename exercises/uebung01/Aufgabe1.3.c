#include <stdio.h>

#define ANZAHL_WERTE 15
#define KLEINSTER_SCHEIN 500

/* Stückelungen in Cent, absteigend */
const int werte[ANZAHL_WERTE] = {50000, 20000, 10000, 5000, 2000, 1000, 500,
                                 200, 100, 50, 20, 10, 5, 2, 1};

// Berechnet das Wechselgeld und gibt die Anzahl der einzelnen Stückelungen zurück.
int wechselgeld_berechnen(int cents, int anzahlen[ANZAHL_WERTE]) {
    /* auszufüllen */
}

// Gibt das Wechselgeld und die Anzahl der einzelnen Stückelungen aus.
void wechselgeld_ausgeben(int rueckgeld, const int anzahlen[ANZAHL_WERTE], int gesamtzahl) {
    printf("Rückgeld: %d.%02d\n", rueckgeld / 100, rueckgeld % 100);
    for (int i = 0; i < ANZAHL_WERTE; i++) {
        if (anzahlen[i] > 0) {
            printf("%d x %s %d.%02d\n", anzahlen[i],
                   werte[i] >= KLEINSTER_SCHEIN ? "Schein:" : "Münze:",
                   werte[i] / 100, werte[i] % 100);
        }
    }
    printf("Gesamtzahl: %d\n", gesamtzahl);
}

int main(void) {
    int preis, gegeben;
    int anzahlen[ANZAHL_WERTE];

    printf("Zu bezahlender Betrag (in Cent): ");
    if (scanf("%d", &preis) != 1 || preis < 0) {
        printf("Ungültiger Preis.\n");
        return 1;       // Rückmeldung eines Fehlers
    }
    printf("Gegebener Betrag (in Cent): ");
    if ( /* auszufüllen */ ) {
        printf("Ungültiger Betrag.\n");
        return 1;
    }

    // Nicht genügend Geld gegeben
    if ( /* auszufüllen */) {
        /* auszufüllen */
    }

    int total = wechselgeld_berechnen( /* auszufüllen */ );
    wechselgeld_ausgeben(gegeben - preis, anzahlen, total);

    return 0;
}
