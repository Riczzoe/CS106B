#include "WinSumLoseSum.h"
using namespace std;

Set<int> numbersMadeFrom(const Set<int>& values) {
    (void) values;
    return {};
}

bool canMakeTarget(const Set<int>& values, int target) {
    (void) values;
    (void) target;
    return false;
}

/* * * * * Test Cases Below This Point * * * * */
#include "GUI/SimpleTest.h"

PROVIDED_TEST("numbersMadeFrom works on small sets of numbers.") {
    EXPECT_EQUAL(numbersMadeFrom({ }), {
                     0 // Can make 0 by adding up nothing
                 });
    EXPECT_EQUAL(numbersMadeFrom({ 1 }), {
                     0, 1
                 });
    EXPECT_EQUAL(numbersMadeFrom({ 1, 3 }), {
                     0, 1, 3, 4
                 });
    EXPECT_EQUAL(numbersMadeFrom({ 1, 2, 4 }), {
                     0, 1, 2, 3, 4, 5, 6, 7
                 });
    EXPECT_EQUAL(numbersMadeFrom({ 1, 2, 3 }), {
                     0, 1, 2, 3, 4, 5, 6
                 });
    EXPECT_EQUAL(numbersMadeFrom({ 1, 3, 4 }), {
                     0, 1, 3, 4, 5, 7, 8
                 });
}

/* We want our test cases to work for canMakeTarget both if you are on part (ii)
 * or on part (iii) of this problem. To do this, we've set things up so that you
 * can use this function, which will call the right version of canMakeTarget based
 * on which version you've written.
 */
namespace {
    /* Dispatch as appropriate. */
    bool invoke(bool callback(const Set<int>&, int, Set<int>&),
                const Set<int>& values, int target, Set<int>& solution) {
        return callback(values, target, solution);
    }
    bool invoke(bool callback(const Set<int>&, int),
                const Set<int>& values, int target, Set<int>&) {
        return callback(values, target);
    }

    /* Suppress compiler warnings. */
    bool quiet1(const Set<int>&, int, Set<int>&) {
        return false;
    }
    bool quiet2(const Set<int>&, int) {
        return false;
    }
    void quietPlease() {
        Set<int> dummy;
        (void) dummy;
        (void) invoke(quiet1, dummy, 137, dummy);
        (void) invoke(quiet2, dummy, 137, dummy);
    }

    bool testCanMakeTarget(const Set<int>& values, int target, Set<int>& solution) {
        quietPlease();
        return invoke(canMakeTarget, values, target, solution);
    }
}

PROVIDED_TEST("canMakeTarget works for small sets of numbers, with no outparameter.") {
    Set<int> unused;

    /* Can make 0, but not others. */
    EXPECT( testCanMakeTarget({ },  0, unused));
    EXPECT(!testCanMakeTarget({ },  1, unused));
    EXPECT(!testCanMakeTarget({ }, -1, unused));

    /* Can make 0 and 137, but not others. */
    EXPECT( testCanMakeTarget({ 137 },   0, unused));
    EXPECT( testCanMakeTarget({ 137 }, 137, unused));
    EXPECT(!testCanMakeTarget({ 137 },   1, unused));
    EXPECT(!testCanMakeTarget({ 137 },  -1, unused));

    /* Can make 0, 1, 2, and 3, but not others. */
    EXPECT( testCanMakeTarget({ 1, 2 },  0, unused));
    EXPECT( testCanMakeTarget({ 1, 2 },  1, unused));
    EXPECT( testCanMakeTarget({ 1, 2 },  2, unused));
    EXPECT( testCanMakeTarget({ 1, 2 },  3, unused));
    EXPECT(!testCanMakeTarget({ 1, 2 }, 71, unused));
    EXPECT(!testCanMakeTarget({ 1, 2 }, -1, unused));

    /* Can make 0, 1, 3, 4, 5, 7, and 8, but not others. */
    EXPECT(!testCanMakeTarget({ 1, 3, 4 }, -1, unused));
    EXPECT( testCanMakeTarget({ 1, 3, 4 },  0, unused));
    EXPECT( testCanMakeTarget({ 1, 3, 4 },  1, unused));
    EXPECT(!testCanMakeTarget({ 1, 3, 4 },  2, unused));
    EXPECT( testCanMakeTarget({ 1, 3, 4 },  3, unused));
    EXPECT( testCanMakeTarget({ 1, 3, 4 },  4, unused));
    EXPECT( testCanMakeTarget({ 1, 3, 4 },  5, unused));
    EXPECT(!testCanMakeTarget({ 1, 3, 4 },  6, unused));
    EXPECT( testCanMakeTarget({ 1, 3, 4 },  7, unused));
    EXPECT( testCanMakeTarget({ 1, 3, 4 },  8, unused));
    EXPECT(!testCanMakeTarget({ 1, 3, 4 },  9, unused));
}

PROVIDED_TEST("canMakeTarget works for small sets of numbers, with outparameter.") {
    Set<int> solution = { 1, 2, 3, 4, 5 };

    /* Can make 0, but not others. */
    EXPECT( testCanMakeTarget({ },  0, solution));
    EXPECT_EQUAL(solution, { });
    EXPECT(!testCanMakeTarget({ },  1, solution));
    EXPECT(!testCanMakeTarget({ }, -1, solution));

    /* Can make 0 and 137, but not others. */
    EXPECT( testCanMakeTarget({ 137 },   0, solution));
    EXPECT_EQUAL(solution, { });
    EXPECT( testCanMakeTarget({ 137 }, 137, solution));
    EXPECT_EQUAL(solution, { 137 });
    EXPECT(!testCanMakeTarget({ 137 },   1, solution));
    EXPECT(!testCanMakeTarget({ 137 },  -1, solution));

    /* Can make 0, 1, 2, and 3, but not others. */
    EXPECT( testCanMakeTarget({ 1, 2 },  0, solution));
    EXPECT_EQUAL(solution, { });
    EXPECT( testCanMakeTarget({ 1, 2 },  1, solution));
    EXPECT_EQUAL(solution, { 1 });
    EXPECT( testCanMakeTarget({ 1, 2 },  2, solution));
    EXPECT_EQUAL(solution, { 2 });
    EXPECT( testCanMakeTarget({ 1, 2 },  3, solution));
    EXPECT_EQUAL(solution, { 1, 2 });
    EXPECT(!testCanMakeTarget({ 1, 2 }, 71, solution));
    EXPECT(!testCanMakeTarget({ 1, 2 }, -1, solution));

    /* Can make 0, 1, 3, 4, 5, 7, and 8, but not others. */
    EXPECT(!testCanMakeTarget({ 1, 3, 4 }, -1, solution));
    EXPECT( testCanMakeTarget({ 1, 3, 4 },  0, solution));
    EXPECT_EQUAL(solution, { });
    EXPECT( testCanMakeTarget({ 1, 3, 4 },  1, solution));
    EXPECT_EQUAL(solution, { 1 });
    EXPECT(!testCanMakeTarget({ 1, 3, 4 },  2, solution));
    EXPECT( testCanMakeTarget({ 1, 3, 4 },  3, solution));
    EXPECT_EQUAL(solution, { 3 });
    EXPECT( testCanMakeTarget({ 1, 3, 4 },  4, solution));
    EXPECT( testCanMakeTarget({ 1, 3, 4 },  5, solution));
    EXPECT_EQUAL(solution, { 1, 4 });
    EXPECT(!testCanMakeTarget({ 1, 3, 4 },  6, solution));
    EXPECT( testCanMakeTarget({ 1, 3, 4 },  7, solution));
    EXPECT_EQUAL(solution, { 3, 4 });
    EXPECT( testCanMakeTarget({ 1, 3, 4 },  8, solution));
    EXPECT_EQUAL(solution, { 1, 3, 4 });
    EXPECT(!testCanMakeTarget({ 1, 3, 4 },  9, solution));
}
