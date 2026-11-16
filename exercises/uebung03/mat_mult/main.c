#include <stdio.h>
#include "mat_mult.h"

// Liest eine n x m-Matrix zeilenweise von der Standardeingabe ein.
int read_matrix(int n, int m, int D[]) {
    for (int i = 0; i < n; i++) {
        printf("Bitte geben Sie die %d. Zeile der Matrix an\n", i + 1);
        for (int j = 0; j < m; j++) {
            printf("%d-ter Eintrag:\n", j + 1);
            if (scanf("%d", &D[i * m + j]) != 1) {
                return 1;
            }
        }
    }
    return 0;
}

// Gibt eine n x m-Matrix zeilenweise auf der Standardausgabe aus.
void write_matrix(int n, int m, const int D[]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", D[i * m + j]);
        }
        printf("\n");
    }
}

// Liest eine positive Dimension ein. Gibt 0 bei Erfolg zurück.
int read_dimension(const char *name, int *dimension) {
    printf("Bitte geben Sie %s an: ", name);
    if (scanf("%d", dimension) != 1 || *dimension <= 0) {
        return 1;
    }
    return 0;
}

int main(void) {
    int n = 0;
    int m = 0;
    int o = 0;
    printf("Dieses Programm multipliziert eine nxm-Matrix A mit einer mxo-Matrix B:\n");
    if (read_dimension("n", &n) != 0 || read_dimension("m", &m) != 0
        || read_dimension("o", &o) != 0) {
        printf("Ungültige Dimension!\n");
        return 1;
    }

    // Arrays variabler Länge können nicht bei der Deklaration initialisiert werden.
    int A[n * m];
    printf("Bitte geben Sie A an:\n");
    if (read_matrix(n, m, A) != 0) {
        printf("Eingabe fehlgeschlagen!\n");
        return 1;
    }

    int B[m * o];
    printf("Bitte geben Sie B an:\n");
    if (read_matrix(m, o, B) != 0) {
        printf("Eingabe fehlgeschlagen!\n");
        return 1;
    }

    printf("Matrix A wurde eingelesen als:\n");
    write_matrix(n, m, A);
    printf("Matrix B wurde eingelesen als:\n");
    write_matrix(m, o, B);

    int C[n * o];
    mat_mult(n, m, o, A, B, C);

    printf("Das Produkt der beiden Faktoren ist:\n");
    write_matrix(n, o, C);
    return 0;
}
