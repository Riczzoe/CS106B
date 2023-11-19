#include <stdio.h>
#include "sort.h"

#define RADIX       10
// #define THRESHOLD   10  /* threshold for small subarrays insertion sort */
#define MAX         1010
int THRESHOLD = 2;

static int msd_aux[1010] = {0};

static int find_max(int *elems, int len)
{
    int i, max = elems[0];

    for (i = 0; i < len; i++) {
        if (elems[i] > elems[max]) 
            max = i;
    }
    return max;
}

/*
 * get_number_at() - get the number at the specific significant
 */
static int get_number_at(int n, int s) {
    /* if want get the number at the last significant(s < RADIX), 
     * return n % RADIX
     */
    return s >= RADIX ? n / s % RADIX : n % RADIX;
}

static void better_counting_sort(int *elems, int len, int significant)
{
    int i;
    int count[RADIX + 1] = {0};
    int aux[len];

    // compute frequency counts
    for (i = 0; i < len; i++) 
        count[get_number_at(elems[i], significant) + 1]++;

    // transform counts ro index
    for (i = 0; i < RADIX; i++) 
        count[i + 1] += count[i];

    // distribute the elements
    for (i = 0; i < len; i++) 
        aux[count[get_number_at(elems[i], significant)]++] = elems[i];

    // copy back
    for (i = 0; i < len; i++)
        elems[i] = aux[i];
}

/*
 * static void counting_sort(int *elems, int len, int significant) 
 * {
 *     int counts[RADIX] = {0};
 *     int start_point[RADIX] = {0};
 *     int aux[len];
 *     int i, digit;
 * 
 *     for (i = 0; i < len; i++) {
 *         digit = (elems[i] / significant) % RADIX;
 *         counts[digit]++;
 *     }
 * 
 *     for (i = 1; i < RADIX; i++) 
 *         start_point[i] = start_point[i - 1] + counts[i - 1];
 * 
 *     for (i = 0; i < len; i++) {
 *         digit = (elems[i] / significant) % RADIX;
 *         aux[start_point[digit]] = elems[i];
 *         start_point[digit]++;
 *     }
 *     
 *     for (i = 0; i < len; i++) 
 *         elems[i] = aux[i];
 * }
 */

void radix_sort(int *elems, int len)
{
    int max, significant;
    max = elems[find_max(elems, len)];

    for (significant = 1; max / significant > 0; significant *= RADIX) {
        better_counting_sort(elems, len, significant);
    }
}

static void counting_sort_msd(int *elems, int start, int len, int significant)
{
    /* if len <= THRESHOLD, use insertion sort
     */
    if (len <= THRESHOLD) {
        insertion_sort(elems + start, len);
        return;
    }

    int count[RADIX + 2] = {0};
    int i, number, prev = elems[start];
    int allsame = 1;    /* Judge if all the numbers are the same */

    /* get the frequency of each number */
    for (i = 0; i < len; i++) {
        number = get_number_at(elems[start + i], significant);
        count[number + 2]++;
        if (allsame && prev != elems[start + i]) 
            allsame = 0;
        prev = elems[start + i];
    }

    if (allsame) 
        return;

    /* transform counts to index */
    for (i = 0; i < RADIX; i++) 
        count[i + 2] += count[i + 1];

    /* distribute the elements */
    for (i = 0; i < len; i++) {
        number = get_number_at(elems[start + i], significant);
        msd_aux[count[number + 1]++] = elems[start + i];
    }

    /* copy back */
    for (i = 0; i < len; i++) 
        elems[start + i] = msd_aux[i];

    /* recursively sort for each digit */
    for (i = 0; i < RADIX; i++) 
        counting_sort_msd(elems + start, count[i], count[i + 1] - count[i],
                                 significant / RADIX);
}

void radix_sort_msd(int *elems, int len) 
{
    int max, significant;
    max = elems[find_max(elems, len)];

    if (len > 100) 
        THRESHOLD = 10;
        
    significant = 1;
    while (max / significant >= 10) 
        significant *= 10;
    counting_sort_msd(elems, 0, len, significant);
}
