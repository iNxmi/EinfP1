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

    printf("Die Collatzfolge zu %d ist\n%d ", c, c);

    while ( c != 1 ) {
        if ( c % 2 == 0 ) {
            c = c/2;
        } else {
            c = 3*c+1;
        }                    
        printf("%d ",c);
    }
    printf("\n");
}

int main(void) {
    int startwert = 0;
 
    printf("Positive ganze Zahl: ");
    scanf("%d",&startwert);

    collatz_folge(startwert); 

    return 0;
}
