static void exch(int *elems, int i, int j) 
{
    int temp = elems[i];
    elems[i] = elems[j];
    elems[j] = temp;
}

/* 
 * partition() - this is a very very funny function. every character
 * in this function is filled with details. I really love it.
 */
static int paritition(int *elems, int lo, int hi)
{
    int l, g, pivot;

    /* Select the first element as pivot */
    pivot = elems[lo];

    for (l = lo, g = hi;;) {
        /* find the first element that is greater than pivot 
         * we want start from lo + 1, because lo is pivot.
         * so we use ++l and initial l = lo
         */
        while (elems[++l] < pivot) {
            /* check if l is out of range */
            if (l >= hi) 
                break;
        }

        /* find the first element that is less than pivot.
         * there is some difference between this and the above.
         * we start form hi, because hi is the vaild index.
         * if the elems[hi] is greater than pivot, it should be
         * stay here, and use --g to find the next element and judge
         * if it is less than pivot. 
         */
        while (elems[g] > pivot) 
            /* This is a little tricky, we have no need to check
             * if g is out of range, because g never be less than
             * lo. think about it, if g is less than lo, it means
             * elems[g] <= pivot.
             */
            g--;

        /* This judgement is very important, if l >= g, it means
         * l has found an element that is already in the correct 
         * position and is greater than pivot, and g has found an
         * element that is already in the correct position and is
         * less than pivot. so we should not exchange them. so we
         * break the loop.
         */
        if (l >= g)
            break;
        exch(elems, l, g);
    }

    /* now, all the elements in the range [lo + 1, hi] are divided
     * into two parts, the left part is less than pivot, and the
     * right part is greater than pivot.so we just need to put the 
     * pivot in the correct position.
     *
     * That is very interesting, g is pointing to the element that
     * is less than pivot, and l is pointing to the element that is
     * greater than pivot. 
     *
     * if we exchange elems[lo] and elems[l], the greater element
     * will be put in lo position. This result in not all elements
     * in the left of pivot are less than it.
     *
     * and if we exchange elems[lo] and elems[g], the less element
     * will be put in lo position. that will not change the property
     * that all the elements in the left of pivot are less than it,
     * and all the elements in the right of pivot are greater than it.
     */
    exch(elems, lo, g);
    return g;
}

static void sort(int *elems, int lo, int hi) 
{
    int pivot;
    if (lo >= hi)
        return;

    pivot = paritition(elems, lo, hi);
    sort(elems, lo, pivot - 1);
    sort(elems, pivot + 1, hi);
}

void quick_sort(int *elems, int len)
{
    if (!elems)
        return;
    sort(elems, 0, len - 1);
}
