#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
#include <string.h>
#include <unistd.h>

char *sort_names[] = {
    "Selection Sort",
    "Insertion Sort",
    "Shell Sort",
    "Merge Sort",
    "Merge Sort Down Top",
    "Heap Sort (Priority Queue)",
    "Heap Sort",
    "Quick Sort",
    "Radix Sort",
    "Radix Sort MSD",
};

void (*sort_functions[])(int *, int) = {
    selection_sort,
    insertion_sort,
    shell_sort,
    merge_sort,
    merge_sort_dt,
    heap_sort_pq,
    heap_sort,
    quick_sort,
    radix_sort,
    radix_sort_msd,
};

static int is_sorted(int *arr, int len) 
{
    for (int i = 1; i < len; i++) {
        if (arr[i] < arr[i - 1])
            return 0;
    }
    return 1;
}

void print_result(const char* subTest, int passed) 
{
    if (passed) {
        printf("\033[32m\u2713\033[0m %s Passed\n", subTest);
    } else {
        printf("\033[31m\u2717\033[0m %s Failed\n", subTest);
    }
}

static int sort_and_check(int *arr, int len, const char *subTest, 
        void (*sort)(int *, int)) {
    if (arr && len > 0) {
        sort(arr, len);
    }
    int sorted = is_sorted(arr, len);
    print_result(subTest, sorted);
    return sorted;
}

int _test_sort(void (*sort)(int *, int), char *name) 
{
    int passed = 1;
    printf("\033[32m--------------------------\n");
    printf("Testing\033[31m %s\n", name);
    printf("\033[32m--------------------------\033[0m\n");

    /* int test1[] = {5, 4, 3, 2, 1}; */
    int test1[] = {79, 117, 26, 33, 567, 32, 1, 39, 10};
    int test2[] = {1, 2, 3, 4, 5};
    int test3[] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
    int test4[] = {7, 7, 7, 7, 7, 7, 7, 7, 7};
    int test5[] = {1, 2, 3, 4, 5, 5, 4, 3, 2, 1};
    int *test6 = NULL;
    int test7[] = {42};
    
    int len1 = sizeof(test1) / sizeof(test1[0]);
    int len2 = sizeof(test2) / sizeof(test2[0]);
    int len3 = sizeof(test3) / sizeof(test3[0]);
    int len4 = sizeof(test4) / sizeof(test4[0]);
    int len5 = sizeof(test5) / sizeof(test5[0]);
    int len7 = sizeof(test7) / sizeof(test7[0]);
    int len8 = 1000;

    int results[8];
    results[0] = sort_and_check(test1, len1, "Test 1 (Reverse Order)", sort);
    results[1] = sort_and_check(test2, len2, "Test 2 (Already Sorted)", sort);
    results[2] = sort_and_check(test3, len3, "Test 3 (Random Order)", sort);
    results[3] = sort_and_check(test4, len4, "Test 4 (All Same)", sort);
    results[4] = sort_and_check(test5, len5, "Test 5 (Palindromic Array)", sort);
    results[5] = sort_and_check(test6, 0, "Test 6 (Empty Array)", sort);
    results[6] = sort_and_check(test7, len7, "Test 7 (Single Element)", sort);

    int *test8 = (int *)malloc(len8 * sizeof(int));
    for (int i = 0; i < len8; i++) {
        test8[i] = rand() % 5000;  
    }
    results[7] = sort_and_check(test8, len8, "Test 8 (Large Random Array)", sort);
    free(test8);  // free dynamically allocated memory

    for (int i = 0; i < 8; i++) {
        if (results[i])
            continue;
        passed = 0;
        break;
    }

    return passed;
}

void final_result(int *result, int *funcs, int len)
{
    int maxWidth = 0;

    printf("\n\033[32m--------------------------\n");
    printf("Final Result\n");
    printf("--------------------------\033[0m\n");

    for (int i = 0; i < len; i++) {
        int currentWidth = strlen(sort_names[funcs[i]]);
        if (currentWidth > maxWidth) {
            maxWidth = currentWidth;
        }
    }


    for (int i = 0; i < len; i++) {
        printf("%s ", result[i] ? "\033[32m\u2713\033[0m" : 
                                  "\033[31m\u2717\033[0m");
        printf("%-*s\t%s\n", maxWidth, sort_names[funcs[i]],
                               result[i] ? "Passed" : "Failed");
    }
}

void test_sort(int *funcs, int len)
{
    int i;
    int results[len];

    for (i = 0; i < len; i++) {
        if (i)
            printf("\n");
        results[i] = _test_sort(sort_functions[funcs[i]],
                                sort_names[funcs[i]]);
    }

    final_result(results, funcs, len);
}

