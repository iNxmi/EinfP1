#include<stdio.h>
#include"generate_list.h"

//Einlesen der movies.in Datei Sortieren nach ausgewählter Vergleichsfunktion
// und Ausgabe als movies_ordered.out
int main(void){
    read_movies();
    sort_movies(compare_rating);
    sort_movies_tie(compare_rating, compare_length);
    write_movies();

    return 0;
}
