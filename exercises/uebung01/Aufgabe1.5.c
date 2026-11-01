#include <stdio.h>

void binärdarstellung(int zahl) {

    int potenzwert = 1;
    int exponent = 0;

    if (zahl == 0) {
        printf("0");
    }
    else {
        while (potenzwert*2 <= zahl) {
            potenzwert = potenzwert*2;
            exponent++;
        }
        for (int i = 0; i <= exponent; i++) {
            if (zahl-potenzwert >= 0) {
                zahl = zahl - potenzwert;
                potenzwert = potenzwert/2;
                printf("1");
            }
            else {
                potenzwert = potenzwert/2;
                printf("0");
            }
        }
    }
}

int main() {
    int zahl;
    printf("Gib eine natürliche Zahl ein: ");
    scanf("%u", &zahl);

    binärdarstellung(zahl);

    return 0;
}
