#include "HumanPyramids.h"
#include "error.h"
#include "grid.h"
using namespace std;

bool outOfBound(int row, int col) {
    return row < 0 || col > row;
}

double weightOnBackOfRecursion(Grid<double>& table, int row, int col);

double getWeightFromTable(Grid<double>& table, int row, int col) {
    double weight;

    if (table.get(row , col) != 0) {
        return table.get(row, col);
    }
    weight = weightOnBackOfRecursion(table, row, col);
    table.set(row, col, weight);
    return weight;
}

/* TODO: Refer to HumanPyramids.h for more information about what this function should do.
 * Then, delete this comment.
 */

double weightOnBackOfRecursion(Grid<double>& table, int row, int col) {
    int newCol;
    double weight, wt1, wt2;

    if (outOfBound(row, col)) {
        error("Out of bounds.");
    }
    if (row == 0) {
        return 0;
    }
    if (table.get(row, col) != 0) {
        return table.get(row, col);
    }

    if (col == 0 || col == row) {
        newCol = col == 0 ? 0 : row - 1;
        weight = getWeightFromTable(table, row - 1, newCol);
        weight = weight / 2 + 80;
        table.set(row, col, weight);
        return weight;
    }

    wt1 = getWeightFromTable(table, row - 1, col);
    wt2 = getWeightFromTable(table, row - 1, col - 1);
    weight =(wt1 + wt2) / 2 + 160;
    table.set(row, col, weight);
    return weight;
}

double weightOnBackOf(int row, int col) {
    if (outOfBound(row, col)) {
        error("Out of bounds.");
    }
    Grid<double> table(row + 1, col + 1, 0);

    return weightOnBackOfRecursion(table, row, col);
}





/* * * * * * Test Cases * * * * * */
#include "GUI/SimpleTest.h"

STUDENT_TEST("Milestone 1: Check Person M from the handout.") {
    /* Person M is located at row 4, column 2. */
    EXPECT_EQUAL(weightOnBackOf(4, 2), 500);
}

STUDENT_TEST("Milestone 1: Check Person A from the handout.") {
    /* Person M is located at row 0, column 0. */
    EXPECT_EQUAL(weightOnBackOf(0, 0), 0);
}


/* * * * * * Test cases from the starter files below this point. * * * * * */

PROVIDED_TEST("Milestone 1: Check Person E from the handout.") {
    /* Person E is located at row 2, column 1. */
    EXPECT_EQUAL(weightOnBackOf(2, 1), 240);
}

PROVIDED_TEST("Milestone 1: Function reports errors in invalid cases.") {
    EXPECT_ERROR(weightOnBackOf(-1, 0));
    EXPECT_ERROR(weightOnBackOf(10, 11));
    EXPECT_ERROR(weightOnBackOf(-1, 10));
}

PROVIDED_TEST("Milestone 2: Memoization is implemented (should take under a second)") {
    /* TODO: Yes, we are asking you to make a change to this test case! Delete the
     * line immediately after this one - the one that starts with SHOW_ERROR - once
     * you have implemented memoization to test whether it works correctly.
     */

    /* This will take a LONG time to complete if memoization isn't implemented.
     * We're talking "heat death of the universe" amounts of time. :-)
     *
     * If you did implement memoization but this test case is still hanging, make
     * sure that in your recursive function (not the wrapper) that your recursive
     * calls are to your new recursive function and not back to the wrapper. If you
     * call the wrapper again, you'll get a fresh new memoization table rather than
     * preserving the one you're building up in your recursive exploration, and the
     * effect will be as if you hadn't implemented memoization at all.
     */
    EXPECT(weightOnBackOf(100, 50) >= 10000);
}
