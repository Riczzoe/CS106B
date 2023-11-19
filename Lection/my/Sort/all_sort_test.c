#include "sort.h"
#include "sort_test.h"

static void test_start_at(int start_at) {
    int need_test_func[] = {
        SELECTION_SORT, 
        INSERTION_SORT,
        SHELL_SORT,
        MERGE_SORT,
        MERGE_SORT_DT,
        HEAP_SORT_PQ,
        HEAP_SORT,
        QUICK_SORT,
        RADIX_SORT,
        RADIX_SORT_MSD,
    };
    test_sort(need_test_func + start_at, 
            sizeof(need_test_func) / sizeof(int) - start_at);
}

int main() 
{
    test_start_at(SELECTION_SORT);
    return 0;
}
