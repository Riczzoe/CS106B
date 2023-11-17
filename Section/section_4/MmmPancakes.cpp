#include "MmmPancakes.h"
using namespace std;

Optional<Vector<int>> sortStack(Stack<double> pancakes, int numFlips) {
    (void) pancakes;
    (void) numFlips;
    return Nothing;
}

/* * * * * Test Cases Below This Point * * * * */
#include "GUI/SimpleTest.h"

PROVIDED_TEST("Works on simple examples.") {
    EXPECT_EQUAL(sortStack({ 3, 2, 1 }, 0), { });
    EXPECT_EQUAL(sortStack({ 3, 2, 1 }, 1), { });
    EXPECT_EQUAL(sortStack({ 1, 2, 3 }, 0), Nothing);
    EXPECT_EQUAL(sortStack({ 1, 2, 3 }, 1), { 3 });
}

PROVIDED_TEST("Works on the example from the problem description.") {
    EXPECT_EQUAL(sortStack({ 7, 6, 1, 2, 5, 4, 3 }, 2), { 3, 5 });
}

PROVIDED_TEST("Works on a trickier example.") {
    Stack<double> values = { 0, 1, 3, 6, 2, 7, 13, 20, 12 };
    EXPECT_EQUAL(sortStack(values, 6), Nothing);
    EXPECT_EQUAL(sortStack(values, 7), { 3, 2, 4, 5, 7, 6, 9 });
}
