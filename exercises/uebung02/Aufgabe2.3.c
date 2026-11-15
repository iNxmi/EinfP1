#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double pi_approximieren(int anzahl) {

    //rand() hat immer den gleichen seed, weiß nicht obs im scope der aufgabe ist das auch zu ändern
    double x;
    double y;

    double t = 0;

    srand(time(NULL));

    for (int i = 0; i < anzahl; i++) {
          x = (double)rand() / (double)RAND_MAX;
          y = (double)rand() / (double)RAND_MAX;

          if ((x * x)+(y * y) <= 1) {
              t++;
          }
    }

    //Rechnung komisch wenn t ein int ist, weil dann int division
    return 4*(t/anzahl);
}

int main () {
    int anzahl;
    /* Auszufüllen */
    int N;
    double pi;
    printf("Insert an integer\n");
    scanf("%d", &N);

    pi = pi_approximieren(N);
    printf("%f\n",pi);
    return 0;
}