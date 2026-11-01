#include <stdio.h>
#define MAXLINE 50

int ist_balanciert(char s[]) {
    int counter = 0;

    int index = 0;
    char character = s[index];
    while (character != '\0') {
        if (character == '(') {
            counter++;
        } else if (character == ')') {
            if (counter <= 0)
                return 0;

            counter--;
        }

        index++;
        character = s[index];
    }

    return counter == 0;
}

int main () {
    char s[MAXLINE + 1];
    printf("Geben Sie einen String ein, der nur aus '(' und ')' besteht: \n");
    scanf("%s", s);

    if (ist_balanciert(s)) {
        printf("1 \n");
    } else {
        printf("0 \n");
    }

    return 0;
}