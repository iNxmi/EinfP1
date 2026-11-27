#include<stdio.h>
#include<stdlib.h>
#include"generate_list.h"

#define NUMBER_OF_MOVIES 250
#define LINE_LENGTH 256
#define TITLE_LENGTH 70
#define AGE_LENGTH 20
#define GENRE_LENGTH 30

enum {
    TITLE = 0,
    YEAR = 1,
    RATING = 2,
    LENGTH = 3,
    AGE = 4,
    GENRE = 5
};

char title[NUMBER_OF_MOVIES][TITLE_LENGTH] = {0};
int year[NUMBER_OF_MOVIES] = {0};
double rating[NUMBER_OF_MOVIES] = {0};
int length[NUMBER_OF_MOVIES] = {0};
char age[NUMBER_OF_MOVIES][AGE_LENGTH] = {0};
char genre[NUMBER_OF_MOVIES][GENRE_LENGTH] = {0};
int position[NUMBER_OF_MOVIES] = {0};

void read_movies(void) {
    FILE *file_pointer = fopen("movies.in", "r");
    if (file_pointer == NULL) {
        fprintf(stderr, "Can't open input file!\n");
        exit(1);
    }

    for (size_t index_movie = 0; index_movie < NUMBER_OF_MOVIES; index_movie++) {
        char line[LINE_LENGTH] = {0};
        if (fgets(line, LINE_LENGTH, file_pointer) == NULL)
            break;

        int category = TITLE;

        size_t index_title = 0;
        size_t index_age = 0;
        size_t index_genre = 0;

        int is_after_decimal_rating = 0;
        double divisor_rating = 10.0;

        for (size_t index_character = 0; index_character < LINE_LENGTH; index_character++) {
            const char character = line[index_character];

            if (character == '\n' || character == '\0')
                break;

            if (character == ' ') {
                category++;
                continue;
            }

            if (category == TITLE) {
                title[index_movie][index_title] = character;
                index_title++;
            } else if (category == YEAR) {
                const int digit = character - '0';
                year[index_movie] = year[index_movie] * 10 + digit;
            } else if (category == RATING) {
                //https://stackoverflow.com/questions/22030021/how-to-convert-a-string-to-a-float-character-by-character-using-java

                if (character == '.') {
                    is_after_decimal_rating = 1;
                    continue;
                }

                const int digit = character - '0';
                if (is_after_decimal_rating) {
                    rating[index_movie] += (double) digit / divisor_rating;
                    divisor_rating *= 10.0;
                    continue;
                }

                rating[index_movie] = rating[index_movie] * 10.0 + (double) digit;
            } else if (category == LENGTH) {
                const int digit = character - '0';
                length[index_movie] = length[index_movie] * 10 + digit;
            } else if (category == AGE) {
                age[index_movie][index_age] = character;
                index_age++;
            } else if (category == GENRE) {
                genre[index_movie][index_genre] = character;
                index_genre++;
            }
        }

        position[index_movie] = (int) index_movie;
    }

    fclose(file_pointer);
}

void write_movies(void) {
    FILE *file_pointer = fopen("movies.out", "w");
    if (file_pointer == NULL) {
        fprintf(stderr, "Can't open output file!\n");
        exit(1);
    }

    for (size_t index_position = 0; index_position < NUMBER_OF_MOVIES; index_position++) {
        const size_t index_movie = position[index_position];

        fprintf(file_pointer, "%s %d %g %d %s %s\n",
            title[index_movie],
            year[index_movie],
            rating[index_movie],
            length[index_movie],
            age[index_movie],
            genre[index_movie]
        );
    }

    fclose(file_pointer);
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
void sort_movies(int (*compare)(int, int)) {
    // TODO
}

// Sortierung mit zweiter Vergleichsfunktionen als Tie-Breaker
void sort_movies_tie(int (*compare1)(int, int), int (*compare2)(int, int)) {
    // TODO
}

int main() {
    read_movies();
    write_movies();
}
