#include <stdlib.h>
#include "sort.h"

#define MIN(a, b) ((a) < (b) ? (a) : (b))

void selection_sort(int *elems, int len) 
{
    int i, j, min, temp;
    
    if (!elems)
        return;

    for (i = 0; i < len; i++) {
        min = i;
        for (j = i + 1; j < len; j++) {
            if (elems[j] < elems[min]) {
                min = j;
            }
        }
        temp = elems[i];
        elems[i] = elems[min];
        elems[min] = temp;
    }
}

void insertion_sort(int *elems, int len)
{
    int i, j, temp;

    if (!elems)
        return;

    for (i = 1; i < len; i++) {
        for (j = i; j > 0 && elems[j] < elems[j - 1]; j--) {
                temp = elems[j];
                elems[j] = elems[j - 1];
                elems[j - 1] = temp;
        }
    }
}

void shell_sort(int *elems, int len)
{
    int stride = 1;
    int i, j, temp;

    while (stride < len / 3)
        stride = stride * 3 + 1;

    while (stride > 0) {
        for (i = stride; i < len; i++) {
            for (j = i; j >= stride && elems[j] < elems[j - stride]; j -= stride) {
                temp = elems[j];
                elems[j] = elems[j - stride];
                elems[j - stride] = temp;
            }
        }
        stride /= 3;
    }

}

/*
 * merge() - Merge elems[lo..mid] with elems[mid+1..hi]
 */
static void merge(int *elems, int *aux, int lo, int mid, int hi)
{
    int i = lo, j = mid + 1, k;

    for (k = lo; k <= hi; k++) 
        aux[k] = elems[k];

    /* merge back to elems[lo..hi] */
    for (k = lo; k <= hi; k++) {
        if (i > mid)
            elems[k] = aux[j++];
        else if (j > hi)
            elems[k] = aux[i++];
        else if (aux[i] < aux[j]) 
            elems[k] = aux[i++];
        else
            elems[k] = aux[j++];

    }
}

/*
 * _merge_sort() - sort elems[lo..hi] using aux as auxiliary array
 */
static void _merge_sort(int *elems, int *aux, int lo, int hi)
{
    int mid;
    if (lo >= hi)
        return;

    mid = (lo + hi) / 2;
    _merge_sort(elems, aux, lo, mid);       /* sort left half */
    _merge_sort(elems, aux, mid + 1, hi);   /* sort right half */
    merge(elems, aux, lo, mid, hi);                 /* merge results */
}

void merge_sort(int *elems, int len)
{
    /* auxiliar array for merge sort */
    int *aux = malloc(sizeof(int) * len);
    _merge_sort(elems, aux, 0, len - 1);
    free(aux);
}

/*
 * merge_sort_dt() - dowm-top merge sort
 */
void merge_sort_dt(int *elems, int len)
{
    int size, lo;
    int *aux = malloc(sizeof(int) * len);

    for (size = 1; size < len; size += size) {
        for (lo = 0; lo < len - size; lo += size + size)
            merge(elems, aux, lo, lo + size - 1, MIN(lo + 2 * size - 1, len - 1));
    }
    free(aux);
}
