#include <stdio.h>
#define MAXLINE 50

int ist_balanciert(char s[]) {
    /* auszufüllen */
}

int main () {
    char s[MAXLINE+1];
    printf("Geben Sie einen String ein, der nur aus '(' und ')' besteht: \n");
    scanf("%s", s);

    if (ist_balanciert(s)) {
        printf("1 \n");
    } else {
        printf("0 \n");
    }

    return 0;
}