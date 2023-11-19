#ifndef SORT_H
#define SORT_H

#define SELECTION_SORT      0
#define INSERTION_SORT      1
#define SHELL_SORT          2
#define MERGE_SORT          3
#define MERGE_SORT_DT       4
#define HEAP_SORT_PQ        5
#define HEAP_SORT           6
#define QUICK_SORT          7
#define RADIX_SORT          8
#define RADIX_SORT_MSD      9

void selection_sort(int *elems, int len);
void insertion_sort(int *elems, int len);
void shell_sort(int *elems, int len);
void merge_sort(int *elems, int len);
void merge_sort_dt(int *elems, int len);
void heap_sort_pq(int *elems, int len);
void heap_sort(int *elems, int len);
void quick_sort(int *elems, int len);
void radix_sort(int *elems, int len);
void radix_sort_msd(int *elems, int len);

#endif // SORT_H
