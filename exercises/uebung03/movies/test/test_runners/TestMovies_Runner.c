/* Unity test runner for the movies exercise. */
#include "unity.h"

extern void setUp(void);
extern void tearDown(void);
extern void test_read_movies(void);
extern void test_compare_rating(void);
extern void test_compare_length(void);
extern void test_sort_movies_by_rating(void);
extern void test_sort_movies_with_tiebreaker(void);
extern void test_write_movies_respects_position(void);
extern void test_complete_movie_output(void);

#define RUN_MOVIE_TEST(fn) run_test(fn, #fn, __LINE__)

static void run_test(UnityTestFunction fn, const char *name, UNITY_LINE_TYPE line) {
    Unity.CurrentTestName = name;
    Unity.CurrentTestLineNumber = line;
    Unity.NumberOfTests++;
    UNITY_CLR_DETAILS();
    UNITY_EXEC_TIME_START();
    if (TEST_PROTECT()) {
        setUp();
        fn();
    }
    if (TEST_PROTECT()) {
        tearDown();
    }
    UNITY_EXEC_TIME_STOP();
    UnityConcludeTest();
}

int main(void) {
    UnityBegin("test/TestMovies.c");
    RUN_MOVIE_TEST(test_read_movies);
    RUN_MOVIE_TEST(test_compare_rating);
    RUN_MOVIE_TEST(test_compare_length);
    RUN_MOVIE_TEST(test_sort_movies_by_rating);
    RUN_MOVIE_TEST(test_sort_movies_with_tiebreaker);
    RUN_MOVIE_TEST(test_write_movies_respects_position);
    RUN_MOVIE_TEST(test_complete_movie_output);
    return UnityEnd();
}
