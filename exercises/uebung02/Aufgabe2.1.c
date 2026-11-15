#include <stdio.h>

int euclid(int a, int b)
{
    /* Auszufüllen */
    int swap = -1;
    while (true) {
        if (b <= a) {
            swap = a;
            a = b;
            b = swap;
        }
        if (a % b == 0) {
            return a;
        }
        b = b % a;
    }
}

int main (void) 
{
    
    int i,j,div;
    printf("Insert an integer\n");
    scanf("%d", &i);
    printf("Insert an integer\n");
    scanf("%d", &j);

    div = euclid(i,j);
    printf("%d\n",div); /* For a more compact notation we could remove div and directly insert euclid(i,j) in the printf statement*/
    return 0;
}