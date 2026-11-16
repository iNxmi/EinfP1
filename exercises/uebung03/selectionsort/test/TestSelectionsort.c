#include <stdlib.h>

#include "selectionsort.h"
#include "unity.h"


void setUp(void) {
}

void tearDown(void) {
}

void test_selectionsort_static1(void) {
    int n = 9;
    int arr[]={200, 34,-51,16,12,123,54,-34,0};
    int arrSorted[]={-51,-34,0,12,16,34,54,123,200};
    selectionsort(n,arr);
    TEST_ASSERT_EQUAL_INT_ARRAY_MESSAGE(arrSorted, arr, n, "Failed test on input {-51,-34,0,12,16,34,54,123,200}.");
}

void test_selectionsort_static2(void) {
    int n = 19;
    int arr[]={-67,23,54,67,1123,1123,54,-400,0,0,9001,0,0,0,1,1,1,1,1};
    int arrSorted[]={-400,-67,0,0,0,0,0,1,1,1,1,1,23,54,54,67,1123,1123,9001};
    selectionsort(n,arr);
    TEST_ASSERT_EQUAL_INT_ARRAY_MESSAGE(arrSorted, arr, n, "Failed test on input with duplicates.");
}

//initializes the array with random numbers
void init_arr(int n, int* arr) {
    for (int i = 0; i < n; i++) {
      arr[i] = rand()%(3*n);
    }
}

//tests if an array is sorted by comparing neighbouring elements
int test_arr(int n, int*arr) {
    for (int i = 1; i< n;i++) {
        if(arr[i]<arr[i-1])
            return 0;
    }
    return 1;
}

void test_selectionsort_random(void) {
    for (int k = 0; k<10;k++){
    int n = 100;
    int* arr;
    arr = (int*) malloc(n*sizeof(int));
    init_arr(n, arr);
    selectionsort(n,arr);
    TEST_ASSERT_MESSAGE(test_arr(n,arr),"Failed randomized test with n=100.");
    free(arr);
    }
  }
