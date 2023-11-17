#include "LinkedListMechanics.h"
using namespace std;

int sumOfElementsIn(Cell* list) {
    (void) list;
    return -1;
}

Cell* lastElementOf(Cell* list) {
    (void) list;
    return nullptr;
}

/* * * * * Test Cases Below This Point * * * * */
#include "GUI/SimpleTest.h"

PROVIDED_TEST("sumOfElementsIn works on simple cases.") {
    Cell* list = nullptr;
    EXPECT_EQUAL(sumOfElementsIn(list), 0);

    list = makeList(1);
    EXPECT_EQUAL(sumOfElementsIn(list), 1);
    freeList(list);

    list = makeList(1, 2, 3);
    EXPECT_EQUAL(sumOfElementsIn(list), 6);
    freeList(list);

    list = makeList(1, 2, 3, 4);
    EXPECT_EQUAL(sumOfElementsIn(list), 10);
    freeList(list);
}

PROVIDED_TEST("lastElementOf works in simple cases.") {
    Cell* list = nullptr;
    EXPECT_ERROR(lastElementOf(list));

    list = makeList(1);
    EXPECT_EQUAL(lastElementOf(list), list);
    freeList(list);

    list = makeList(1, 2, 3);
    EXPECT_EQUAL(lastElementOf(list), list->next->next);
    freeList(list);
}
