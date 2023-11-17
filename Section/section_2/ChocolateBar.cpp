#include "ChocolateBar.h"
using namespace std;

int numWaysToEat(int numSquares) {
    (void) numSquares;
    return 0;
}

void printWaysToEat(int numSquares) {
    (void) numSquares;
}

Set<Vector<int>> waysToEat(int numSquares) {
    (void) numSquares;
    return {};
}

/* * * * * Test Cases Below This Point * * * * */
#include "GUI/SimpleTest.h"

PROVIDED_TEST("numWaysToEat works on simple inputs.") {
    EXPECT_EQUAL(numWaysToEat(1), 1); // 1
    EXPECT_EQUAL(numWaysToEat(2), 2); // 2, 1 + 1
    EXPECT_EQUAL(numWaysToEat(3), 3); // 2 + 1, 1 + 2, 1 + 1 + 1
}

PROVIDED_TEST("numWaysToEat works on large inputs.") {
    EXPECT_EQUAL(numWaysToEat(13), 377);   // Lots of ways to do this!
    EXPECT_EQUAL(numWaysToEat(21), 17711); // Lots of ways to do this!
}

PROVIDED_TEST("numWaysToEat works on small inputs.") {
    EXPECT_EQUAL(numWaysToEat(0), 1); // Do nothing
}

PROVIDED_TEST("numWaysToEat reports errors on invalid inputs.") {
    EXPECT_ERROR(numWaysToEat(-1));
    EXPECT_ERROR(numWaysToEat(-137));
}

namespace {
    /* Utility function to get back a Set<Vector<int>> from what was printed
     * to cout. Calls error if any duplicates were found.
     */
    Set<Vector<int>> decode(const StreamCatcher& catcher) {
        Set<Vector<int>> result;
        istringstream extractor(catcher.output());

        /* Read each line one at a time. */
        for (string line; getline(extractor, line); ) {
            Vector<int> value;
            istringstream converter(line);
            converter >> value;

            if (!converter) {
                SHOW_ERROR("Something was printed to cout that wasn't a Vector<int>.");
            }

            /* Make sure there's nothing else there. */
            char leftover;
            if (converter >> leftover) {
                SHOW_ERROR("Something was printed to cout that wasn't a Vector<int>.");
            }

            /* Make sure it's unique. */
            if (result.contains(value)) {
                SHOW_ERROR("Sequence " + line + " was produced twice.");
            }
            result += value;
        }
        return result;
    }
}

PROVIDED_TEST("printWaysToEat works for n = 3.") {
    /* Divert cout so we can see what's printed. */
    StreamCatcher catcher;
    printWaysToEat(3);

    EXPECT_EQUAL(decode(catcher), {
                     {2, 1},
                     {1, 2},
                     {1, 1, 1}
                 });
}

PROVIDED_TEST("printWaysToEat works for n = 4.") {
    /* Divert cout so we can see what's printed. */
    StreamCatcher catcher;
    printWaysToEat(4);

    EXPECT_EQUAL(decode(catcher), {
                     {2, 2},
                     {2, 1, 1},
                     {1, 2, 1},
                     {1, 1, 2},
                     {1, 1, 1, 1}
                 });
}

PROVIDED_TEST("printWaysToEat works for n = 0.") {
    /* Divert cout so we can see what's printed. */
    StreamCatcher catcher;
    printWaysToEat(0);

    EXPECT_EQUAL(decode(catcher), { { } });
}

PROVIDED_TEST("printWaysToEat reports errors for n < 0.") {
    StreamCatcher catcher;
    EXPECT_ERROR(printWaysToEat(-137));
    EXPECT_EQUAL(decode(catcher), { }); // Nothing should have been printed.
}

PROVIDED_TEST("waysToEat works for n = 3.") {
    EXPECT_EQUAL(waysToEat(3), {
                     {2, 1},
                     {1, 2},
                     {1, 1, 1}
                 });
}

PROVIDED_TEST("waysToEat works for n = 4.") {
    EXPECT_EQUAL(waysToEat(4), {
                     {2, 2},
                     {2, 1, 1},
                     {1, 2, 1},
                     {1, 1, 2},
                     {1, 1, 1, 1}
                 });
}

PROVIDED_TEST("waysToEat works for n = 0.") {
    EXPECT_EQUAL(waysToEat(0), { { } });
}

PROVIDED_TEST("waysToEat reports errors for n < 0.") {
    EXPECT_ERROR(waysToEat(-137));
}
