static void exch(int *elems, int i, int j)
{
    int tmp = elems[i];
    elems[i] = elems[j];
    elems[j] = tmp;
}

static int less(int *elems, int i, int j)
{
    return elems[i] < elems[j];
}

static int parent(int index) 
{
    return (index + 1) / 2 - 1;
}

static int left(int index)
{
    return 2 * index + 1;
}

static void sink(int *elems, int start, int end)
{
    int left_heap, max_heap;

    while (left(start) <= end) {
        max_heap = left_heap = left(start);
        if (left_heap < end && less(elems, left_heap, left_heap + 1))
            max_heap = left_heap + 1;
        if (!less(elems, start, max_heap))
            break;
        exch(elems, start, max_heap);
        start = max_heap;
    }

}

void heap_sort(int *elems, int len)
{
    int k;
    /* heapify */
    for (k = parent(len); k >= 0; k--) {
        sink(elems, k, len);
    }

    while (len > 0) {
        exch(elems, 0, --len);
        sink(elems, 0, len - 1);
    }
}
