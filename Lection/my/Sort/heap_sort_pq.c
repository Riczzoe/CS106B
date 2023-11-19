#include <stdio.h> 
#define HEAP_MAX_LEN    1010

int heap[HEAP_MAX_LEN];
int size;

static void heap_init()
{
    for (int i = 0; i < HEAP_MAX_LEN; i++) {
        heap[i] = 0;
    }
    size = 0;
}

static void exch(int i, int j)
{
    int tmp = heap[i];
    heap[i] = heap[j];
    heap[j] = tmp;
}

static int less(int i, int j)
{
    return heap[i] < heap[j];
}

/*
 * swim() - if the heap order is violated beacuse node k is larger than
 * its parent, exchange it with its parent. After the exchange, the node
 * is larger than both its children (one is the old parent, and the other
 * is smaller than the old parent because it was a child of the old parent).
 * But the node may still be larger than its new parent, so fix that 
 * violation by same way, and so forth, moving up the heap until reaching
 * a lager key.
 */
static void swim(int k)
{
    while (k > 1 && less(k / 2, k)) {
        exch(k, k / 2);
        k /= 2;
    }
}

/*
 * sink() - if the heap order is violated because node k is smaller than
 * one or both of its children, exchange it with the larger of its two
 * children. After the exchange, This switch may cause a violation at the
 * child; fix that violation in the same way, and so forth, moving down
 * the heap until reaching a node with both children smaller(or equal).
 */
static void sink(int k)
{
    int left_heap, max_heap;
    while (k <= size / 2) {
        max_heap = left_heap = 2 * k;
        if (left_heap < size && less(left_heap, left_heap + 1))
            max_heap = left_heap + 1;
        if (!less(k, max_heap))
            break;
        exch(k, max_heap);
        k = max_heap;
    }
}

/*
 * insert() - add the new key at the end of the array, increment the size
 * of the heap, and then swim up through the heap with that key to restore
 * the heap condition.
 */
static void insert(int key) 
{
    heap[++size] = key;
    swim(size);
}

/*
 * del_max() - exchange the root with the node at the end, decrement the
 * size of the heap, and then sink down through the heap with the new root
 * to restore the heap condition.
 */
static void del_max()
{
    exch(size, 1);
    size--;
    sink(1);
}

void heap_sort_pq(int *elems, int len)
{
    int i;

    heap_init();
    for (i = 0; i < len; i++) {
        insert(elems[i]);
    }
    for (i = 0; i < len ; i++) {
        del_max();
    }

    for (i = 0; i < len; i++) {
        elems[i] = heap[i + 1];
    }
}


