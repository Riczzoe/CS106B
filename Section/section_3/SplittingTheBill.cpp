#include "SplittingTheBill.h"
using namespace std;

void listPossiblePayments(int total, const Set<string>& people) {
    (void) total;
    (void) people;
}

/* * * * * Test Cases Below This Point * * * * */
#include "GUI/SimpleTest.h"
#include "Demos/SubsequenceTesting.h"

PROVIDED_TEST("Works with one person.") {
    Set<string> people = { "A" };
    EXPECT(outputMatches(listPossiblePayments(137, people), {
                             "A 137",
                         }));
}

PROVIDED_TEST("Works with one dollar and three people.") {
    Set<string> people = { "A", "B", "C" };
    EXPECT(outputMatches(listPossiblePayments(1, people), {
                             "A 1 B 0 C 0",
                             "A 0 B 1 C 0",
                             "A 0 B 0 C 1"
                         }));
}

PROVIDED_TEST("Works with two dollars and three people.") {
    Set<string> people = { "A", "B", "C" };
    EXPECT(outputMatches(listPossiblePayments(2, people), {
                             "A 2 B 0 C 0",
                             "A 1 B 1 C 0",
                             "A 1 B 0 C 1",
                             "A 0 B 2 C 0",
                             "A 0 B 1 C 1",
                             "A 0 B 0 C 2"
                         }));
}

PROVIDED_TEST("Works with four dollars and three people.") {
    Set<string> people = { "A", "B", "C" };

    EXPECT(outputMatches(listPossiblePayments(4, people), {
                             "A 0 B 0 C 4",
                             "A 0 B 1 C 3",
                             "A 0 B 2 C 2",
                             "A 0 B 3 C 1",
                             "A 0 B 4 C 0",
                             "A 1 B 0 C 3",
                             "A 1 B 1 C 2",
                             "A 1 B 2 C 1",
                             "A 1 B 3 C 0",
                             "A 2 B 0 C 2",
                             "A 2 B 1 C 1",
                             "A 2 B 2 C 0",
                             "A 3 B 0 C 1",
                             "A 3 B 1 C 0",
                             "A 4 B 0 C 0"
                         }));
}

PROVIDED_TEST("Works with five dollars and five people.") {
    Set<string> people = { "A", "B", "C", "D", "E" };

    EXPECT(outputMatches(listPossiblePayments(5, people), {
                             "A 0 B 0 C 0 D 0 E 5",
                             "A 0 B 0 C 0 D 1 E 4",
                             "A 0 B 0 C 0 D 2 E 3",
                             "A 0 B 0 C 0 D 3 E 2",
                             "A 0 B 0 C 0 D 4 E 1",
                             "A 0 B 0 C 0 D 5 E 0",
                             "A 0 B 0 C 1 D 0 E 4",
                             "A 0 B 0 C 1 D 1 E 3",
                             "A 0 B 0 C 1 D 2 E 2",
                             "A 0 B 0 C 1 D 3 E 1",
                             "A 0 B 0 C 1 D 4 E 0",
                             "A 0 B 0 C 2 D 0 E 3",
                             "A 0 B 0 C 2 D 1 E 2",
                             "A 0 B 0 C 2 D 2 E 1",
                             "A 0 B 0 C 2 D 3 E 0",
                             "A 0 B 0 C 3 D 0 E 2",
                             "A 0 B 0 C 3 D 1 E 1",
                             "A 0 B 0 C 3 D 2 E 0",
                             "A 0 B 0 C 4 D 0 E 1",
                             "A 0 B 0 C 4 D 1 E 0",
                             "A 0 B 0 C 5 D 0 E 0",
                             "A 0 B 1 C 0 D 0 E 4",
                             "A 0 B 1 C 0 D 1 E 3",
                             "A 0 B 1 C 0 D 2 E 2",
                             "A 0 B 1 C 0 D 3 E 1",
                             "A 0 B 1 C 0 D 4 E 0",
                             "A 0 B 1 C 1 D 0 E 3",
                             "A 0 B 1 C 1 D 1 E 2",
                             "A 0 B 1 C 1 D 2 E 1",
                             "A 0 B 1 C 1 D 3 E 0",
                             "A 0 B 1 C 2 D 0 E 2",
                             "A 0 B 1 C 2 D 1 E 1",
                             "A 0 B 1 C 2 D 2 E 0",
                             "A 0 B 1 C 3 D 0 E 1",
                             "A 0 B 1 C 3 D 1 E 0",
                             "A 0 B 1 C 4 D 0 E 0",
                             "A 0 B 2 C 0 D 0 E 3",
                             "A 0 B 2 C 0 D 1 E 2",
                             "A 0 B 2 C 0 D 2 E 1",
                             "A 0 B 2 C 0 D 3 E 0",
                             "A 0 B 2 C 1 D 0 E 2",
                             "A 0 B 2 C 1 D 1 E 1",
                             "A 0 B 2 C 1 D 2 E 0",
                             "A 0 B 2 C 2 D 0 E 1",
                             "A 0 B 2 C 2 D 1 E 0",
                             "A 0 B 2 C 3 D 0 E 0",
                             "A 0 B 3 C 0 D 0 E 2",
                             "A 0 B 3 C 0 D 1 E 1",
                             "A 0 B 3 C 0 D 2 E 0",
                             "A 0 B 3 C 1 D 0 E 1",
                             "A 0 B 3 C 1 D 1 E 0",
                             "A 0 B 3 C 2 D 0 E 0",
                             "A 0 B 4 C 0 D 0 E 1",
                             "A 0 B 4 C 0 D 1 E 0",
                             "A 0 B 4 C 1 D 0 E 0",
                             "A 0 B 5 C 0 D 0 E 0",
                             "A 1 B 0 C 0 D 0 E 4",
                             "A 1 B 0 C 0 D 1 E 3",
                             "A 1 B 0 C 0 D 2 E 2",
                             "A 1 B 0 C 0 D 3 E 1",
                             "A 1 B 0 C 0 D 4 E 0",
                             "A 1 B 0 C 1 D 0 E 3",
                             "A 1 B 0 C 1 D 1 E 2",
                             "A 1 B 0 C 1 D 2 E 1",
                             "A 1 B 0 C 1 D 3 E 0",
                             "A 1 B 0 C 2 D 0 E 2",
                             "A 1 B 0 C 2 D 1 E 1",
                             "A 1 B 0 C 2 D 2 E 0",
                             "A 1 B 0 C 3 D 0 E 1",
                             "A 1 B 0 C 3 D 1 E 0",
                             "A 1 B 0 C 4 D 0 E 0",
                             "A 1 B 1 C 0 D 0 E 3",
                             "A 1 B 1 C 0 D 1 E 2",
                             "A 1 B 1 C 0 D 2 E 1",
                             "A 1 B 1 C 0 D 3 E 0",
                             "A 1 B 1 C 1 D 0 E 2",
                             "A 1 B 1 C 1 D 1 E 1",
                             "A 1 B 1 C 1 D 2 E 0",
                             "A 1 B 1 C 2 D 0 E 1",
                             "A 1 B 1 C 2 D 1 E 0",
                             "A 1 B 1 C 3 D 0 E 0",
                             "A 1 B 2 C 0 D 0 E 2",
                             "A 1 B 2 C 0 D 1 E 1",
                             "A 1 B 2 C 0 D 2 E 0",
                             "A 1 B 2 C 1 D 0 E 1",
                             "A 1 B 2 C 1 D 1 E 0",
                             "A 1 B 2 C 2 D 0 E 0",
                             "A 1 B 3 C 0 D 0 E 1",
                             "A 1 B 3 C 0 D 1 E 0",
                             "A 1 B 3 C 1 D 0 E 0",
                             "A 1 B 4 C 0 D 0 E 0",
                             "A 2 B 0 C 0 D 0 E 3",
                             "A 2 B 0 C 0 D 1 E 2",
                             "A 2 B 0 C 0 D 2 E 1",
                             "A 2 B 0 C 0 D 3 E 0",
                             "A 2 B 0 C 1 D 0 E 2",
                             "A 2 B 0 C 1 D 1 E 1",
                             "A 2 B 0 C 1 D 2 E 0",
                             "A 2 B 0 C 2 D 0 E 1",
                             "A 2 B 0 C 2 D 1 E 0",
                             "A 2 B 0 C 3 D 0 E 0",
                             "A 2 B 1 C 0 D 0 E 2",
                             "A 2 B 1 C 0 D 1 E 1",
                             "A 2 B 1 C 0 D 2 E 0",
                             "A 2 B 1 C 1 D 0 E 1",
                             "A 2 B 1 C 1 D 1 E 0",
                             "A 2 B 1 C 2 D 0 E 0",
                             "A 2 B 2 C 0 D 0 E 1",
                             "A 2 B 2 C 0 D 1 E 0",
                             "A 2 B 2 C 1 D 0 E 0",
                             "A 2 B 3 C 0 D 0 E 0",
                             "A 3 B 0 C 0 D 0 E 2",
                             "A 3 B 0 C 0 D 1 E 1",
                             "A 3 B 0 C 0 D 2 E 0",
                             "A 3 B 0 C 1 D 0 E 1",
                             "A 3 B 0 C 1 D 1 E 0",
                             "A 3 B 0 C 2 D 0 E 0",
                             "A 3 B 1 C 0 D 0 E 1",
                             "A 3 B 1 C 0 D 1 E 0",
                             "A 3 B 1 C 1 D 0 E 0",
                             "A 3 B 2 C 0 D 0 E 0",
                             "A 4 B 0 C 0 D 0 E 1",
                             "A 4 B 0 C 0 D 1 E 0",
                             "A 4 B 0 C 1 D 0 E 0",
                             "A 4 B 1 C 0 D 0 E 0",
                             "A 5 B 0 C 0 D 0 E 0",
                         }));
}

PROVIDED_TEST("Reports errors on invalid inputs.") {
    /* Negative money. */
    EXPECT_ERROR(listPossiblePayments(-1, { "A", "B", "C" }));

    /* No people. */
    EXPECT_ERROR(listPossiblePayments(0, {  }));

    /* Both. */
    EXPECT_ERROR(listPossiblePayments(-1, {  }));
}
