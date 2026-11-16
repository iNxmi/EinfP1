#include "mat_mult.h"
#include "unity.h"

enum {
    DIM = 4,
    GROESSE = DIM * DIM
};

void setUp(void) {
}

void tearDown(void) {
}

// Vergleicht das berechnete Produkt A * B mit dem erwarteten Ergebnis.
static void check_product(const int A[GROESSE], const int B[GROESSE],
                          const int expected[GROESSE]) {
    int C[GROESSE] = {0};
    mat_mult(DIM, DIM, DIM, A, B, C);
    TEST_ASSERT_EQUAL_INT_ARRAY(expected, C, GROESSE);
}

void test_matmult_1(void) {
    const int A[GROESSE] = {
        1, 0, 0, 0,
        0, 1, 0, 0,
        0, 0, 1, 0,
        0, 0, 0, 1
    };
    const int B[GROESSE] = {
        3, 1, 2, 0,
        3, 0, 1, 2,
        4, 1, 2, 2,
        0, 4, 3, 1
    };
    check_product(A, B, B);
}

void test_matmult_2(void) {
    const int A[GROESSE] = {
        3, 1, 2, 0,
        3, 0, 1, 2,
        4, 1, 2, 2,
        0, 4, 3, 1
    };
    const int expected[GROESSE] = {
        20, 5, 11, 6,
        13, 12, 14, 4,
        23, 14, 19, 8,
        24, 7, 13, 15
    };
    check_product(A, A, expected);
}

void test_matmult_3(void) {
    const int A[GROESSE] = {
        83, 86, 77, 15,
        93, 35, 86, 92,
        49, 21, 62, 27,
        90, 59, 63, 26
    };
    const int expected[GROESSE] = {
        20010, 12650, 19506, 11626,
        23468, 16457, 21299, 9329,
        11488, 7844, 11124, 5043,
        18384, 12662, 17548, 9155
    };
    check_product(A, A, expected);
}

void test_matmult_4(void) {
    const int A[GROESSE] = {
        383, 886, 777, 915,
        793, 335, 386, 492,
        649, 421, 362, 27,
        690, 59, 763, 926
    };
    const int expected[GROESSE] = {
        1984910, 1017250, 1619006, 1654626,
        1159368, 1006357, 1260599, 1356429,
        835988, 870044, 818424, 835743,
        1445184, 1006962, 1541648, 1538455
    };
    check_product(A, A, expected);
}

void test_matmult_1x1(void) {
    const int A[1] = {3};
    const int B[1] = {2};
    int C[1] = {0};
    mat_mult(1, 1, 1, A, B, C);
    TEST_ASSERT_EQUAL_INT(6, C[0]);
}

void test_matmult_identity(void) {
    const int E[GROESSE] = {
        1, 0, 0, 0,
        0, 1, 0, 0,
        0, 0, 1, 0,
        0, 0, 0, 1
    };
    check_product(E, E, E);
}

void test_matmult_triangular(void) {
    const int A[GROESSE] = {
        1, 1, 1, 1,
        0, 1, 1, 1,
        0, 0, 1, 1,
        0, 0, 0, 1
    };
    const int B[GROESSE] = {
        1, 0, 0, 0,
        1, 1, 0, 0,
        1, 1, 1, 0,
        1, 1, 1, 1
    };
    const int expected[GROESSE] = {
        4, 3, 2, 1,
        3, 3, 2, 1,
        2, 2, 2, 1,
        1, 1, 1, 1
    };
    check_product(A, B, expected);
}

void test_matmult_non_square(void) {
    // (2 x 3) * (3 x 1)
    const int A[6] = {
        1, 2, 3,
        4, 5, 6
    };
    const int B[3] = {
        1,
        0,
        -1
    };
    const int expected[2] = {-2, -2};
    int C[2] = {0};
    mat_mult(2, 3, 1, A, B, C);
    TEST_ASSERT_EQUAL_INT_ARRAY(expected, C, 2);
}
