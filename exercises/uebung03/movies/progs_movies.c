#include<stdio.h>
#include<stdlib.h>
#include"generate_list.h"

char title[250][70];
int year[250];
double rating[250];
int length[250];
char age[250][20];
char genre[250][30];
int position[250];

// Funktion liest 'movies.in' ein und befüllt die Arrays und position
void read_movies(void) {
    FILE *ifptr;
    ifptr = fopen("movies.in", "r");
    if (ifptr == NULL)
    {
        fprintf(stderr, "Can't open input file!\n");
        exit(1);
    }

    // TODO
}

//Funktion schreibt die Datei 'movies_ordered.out' und nutzt dabei die Reihenfolge von 'position'
void write_movies(void) {
    FILE *ofptr;
    ofptr = fopen("movies_ordered.out", "w");
    if (ofptr == NULL)
    {
        fprintf(stderr, "Can't open output file!\n");
        exit(1);
    }

    // TODO
}

// Vergleich nach Bewertung
int compare_rating(int i, int j) {
    // TODO
}

// Vergleich nach Länge
int compare_length(int i, int j) {
    // TODO
}

// Sortierung mit einem Vergleich, sie können hier ihre Lösung aus Aufgabe 3.1 nutzen
void sort_movies(int (*compare)(int,int)) {
    // TODO
}

// Sortierung mit zweiter Vergleichsfunktionen als Tie-Breaker
void sort_movies_tie(int (*compare1)(int, int), int (*compare2)(int, int)) {
    // TODO
}
