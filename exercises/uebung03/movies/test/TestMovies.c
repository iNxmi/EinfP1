#include "unity.h"
#include "generate_list.h"

#include <stdio.h>
#include <string.h>

enum { MOVIE_COUNT = 250 };

typedef struct {
    char title[70];
    int year;
    double rating;
    int length;
    char age[20];
    char genre[30];
} Movie;

/* Independent reference data, loaded directly from the supplied input file. */
static Movie original[MOVIE_COUNT];

void setUp(void) {
    FILE *input = fopen("movies.in", "r");
    TEST_ASSERT_NOT_NULL_MESSAGE(input, "Cannot open movies.in");
    for (int i = 0; i < MOVIE_COUNT; i++) {
        Movie *m = &original[i];
        int fields = fscanf(input, "%69s %d %lf %d %19s %29s",
                            m->title, &m->year, &m->rating,
                            &m->length, m->age, m->genre);
        TEST_ASSERT_EQUAL_INT_MESSAGE(6, fields, "Invalid entry in movies.in");
    }
    fclose(input);
}

void tearDown(void) {
}

static void assert_movie_matches_original(int i) {
    TEST_ASSERT_EQUAL_STRING(original[i].title, title[i]);
    TEST_ASSERT_EQUAL_INT(original[i].year, year[i]);
    TEST_ASSERT_TRUE_MESSAGE(original[i].rating == rating[i],
                             "Incorrect movie rating");
    TEST_ASSERT_EQUAL_INT(original[i].length, length[i]);
    TEST_ASSERT_EQUAL_STRING(original[i].age, age[i]);
    TEST_ASSERT_EQUAL_STRING(original[i].genre, genre[i]);
}

/* A permutation ensures that no movie is omitted or duplicated. */
static void assert_position_is_permutation(void) {
    int seen[MOVIE_COUNT] = {0};
    for (int i = 0; i < MOVIE_COUNT; i++) {
        int p = position[i];
        TEST_ASSERT_TRUE_MESSAGE(p >= 0 && p < MOVIE_COUNT,
                                 "position contains an invalid index");
        TEST_ASSERT_EQUAL_INT_MESSAGE(0, seen[p],
                                      "position contains a duplicate movie");
        seen[p] = 1;
    }
}

static void assert_sorted_by_rating(void) {
    assert_position_is_permutation();
    for (int i = 1; i < MOVIE_COUNT; i++) {
        TEST_ASSERT_TRUE_MESSAGE(rating[position[i - 1]] >= rating[position[i]],
                                 "Ratings must be sorted in descending order");
    }
}

static void assert_sorted_by_rating_then_length(void) {
    assert_sorted_by_rating();
    for (int i = 1; i < MOVIE_COUNT; i++) {
        int previous = position[i - 1];
        int current = position[i];
        if (rating[previous] == rating[current]) {
            TEST_ASSERT_TRUE_MESSAGE(length[previous] <= length[current],
                                     "Equal ratings require ascending runtime");
        }
    }
}

/* Check the entire file, including order, content and formatting. */
static void assert_output_matches_position(void) {
    FILE *output = fopen("movies_ordered.out", "r");
    TEST_ASSERT_NOT_NULL_MESSAGE(output, "movies_ordered.out was not created");

    char actual[512];
    char expected[512];
    for (int i = 0; i < MOVIE_COUNT; i++) {
        int p = position[i];
        TEST_ASSERT_TRUE_MESSAGE(p >= 0 && p < MOVIE_COUNT,
                                 "Invalid position index while checking output");
        const Movie *m = &original[p];
        snprintf(expected, sizeof expected, "%s %d %.1f %d %s %s\n",
                 m->title, m->year, m->rating, m->length, m->age, m->genre);
        TEST_ASSERT_NOT_NULL_MESSAGE(fgets(actual, sizeof actual, output),
                                     "movies_ordered.out contains too few lines");
        TEST_ASSERT_EQUAL_STRING_MESSAGE(expected, actual,
                                         "Wrong movie, fields, or formatting in output");
    }
    TEST_ASSERT_NULL_MESSAGE(fgets(actual, sizeof actual, output),
                             "movies_ordered.out contains extra lines");
    fclose(output);
}

void test_read_movies(void) {
    read_movies();
    for (int i = 0; i < MOVIE_COUNT; i++) {
        assert_movie_matches_original(i);
        TEST_ASSERT_EQUAL_INT_MESSAGE(i, position[i],
                                      "position must initially be the identity");
    }
}

void test_compare_rating(void) {
    read_movies();
    for (int i = 0; i < MOVIE_COUNT; i += 7) {
        for (int j = 0; j < MOVIE_COUNT; j += 11) {
            int expected = (original[i].rating < original[j].rating) ? 1 :
                           (original[i].rating > original[j].rating) ? -1 : 0;
            TEST_ASSERT_EQUAL_INT_MESSAGE(expected, compare_rating(i, j),
                                          "compare_rating returned an incorrect result");
        }
    }
}

void test_compare_length(void) {
    read_movies();
    for (int i = 0; i < MOVIE_COUNT; i += 7) {
        for (int j = 0; j < MOVIE_COUNT; j += 11) {
            int expected = (original[i].length > original[j].length) ? 1 :
                           (original[i].length < original[j].length) ? -1 : 0;
            TEST_ASSERT_EQUAL_INT_MESSAGE(expected, compare_length(i, j),
                                          "compare_length returned an incorrect result");
        }
    }
}

void test_sort_movies_by_rating(void) {
    read_movies();
    sort_movies(compare_rating);
    assert_sorted_by_rating();
}

void test_sort_movies_with_tiebreaker(void) {
    read_movies();
    sort_movies_tie(compare_rating, compare_length);
    assert_sorted_by_rating_then_length();
}

void test_write_movies_respects_position(void) {
    read_movies();
    for (int i = 0; i < MOVIE_COUNT; i++) {
        position[i] = MOVIE_COUNT - 1 - i;
    }
    write_movies();
    assert_output_matches_position();
}

void test_complete_movie_output(void) {
    read_movies();
    sort_movies(compare_rating);
    sort_movies_tie(compare_rating, compare_length);
    assert_sorted_by_rating_then_length();
    write_movies();
    assert_output_matches_position();
}
