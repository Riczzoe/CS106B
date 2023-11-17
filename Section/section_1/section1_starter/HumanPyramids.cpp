#include "HumanPyramids.h"
#include "error.h"
using namespace std;

int peopleInPyramidOfHeight(int n) {
    (void) n;
    return 0;
}

/* * * * * Test Cases Below This Point * * * * */
#include "GUI/SimpleTest.h"

PROVIDED_TEST("Works for small numbers.") {
    EXPECT_EQUAL(peopleInPyramidOfHeight(1), 1);
    EXPECT_EQUAL(peopleInPyramidOfHeight(2), 3);
    EXPECT_EQUAL(peopleInPyramidOfHeight(3), 6);
}

PROVIDED_TEST("Reports an error on invalid inputs.") {
    EXPECT_ERROR(peopleInPyramidOfHeight(-1));
    EXPECT_ERROR(peopleInPyramidOfHeight(-137));
    EXPECT_NO_ERROR(peopleInPyramidOfHeight(0));
}
