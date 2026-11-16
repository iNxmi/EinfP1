# Tests for the movie sorting exercise (using the same Unity framework as mat_mult).
# Run "make" or "make test" in the movies directory.
# Run "make SOURCE=sol_progs_movies.c test" to test the sample solution.

CC = gcc
CFLAGS += -std=c11 -Wall -Wextra
SOURCE ?= progs_movies.c
UNITY_ROOT = test/Unity

# Separate binary names avoid accidentally testing a stale solution build.
TARGET = TESTMovies_$(basename $(notdir $(SOURCE))).out
TEST_FILES = $(UNITY_ROOT)/unity.c test/TestMovies.c test/test_runners/TestMovies_Runner.c

.PHONY: all test clean ci
all: test

$(TARGET): $(SOURCE) generate_list.h $(TEST_FILES)
	$(CC) $(CPPFLAGS) $(CFLAGS) -I. -I$(UNITY_ROOT) -DUNITY_OUTPUT_COLOR \
		$(SOURCE) $(TEST_FILES) -o $@

test: $(TARGET)
	./$(TARGET)

# For automated evaluation: warnings are errors and tests must all pass.
ci: CFLAGS += -Werror
ci: clean test

clean:
	rm -f TESTMovies_*.out movies_ordered.out
