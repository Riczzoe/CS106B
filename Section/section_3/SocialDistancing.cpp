#include "SocialDistancing.h"
using namespace std;

Set<string> safeArrangementsOf(int lineLength, int numPeople) {
    (void) lineLength;
    (void) numPeople;
    return {};
}

/* * * * * Test Cases Below This Point * * * * */
#include "GUI/SimpleTest.h"

PROVIDED_TEST("Handles one person in small lines.") {
    EXPECT_EQUAL(safeArrangementsOf(0, 1), { });
    EXPECT_EQUAL(safeArrangementsOf(1, 1), {"P"});
    EXPECT_EQUAL(safeArrangementsOf(2, 1), {"P.", ".P"});
    EXPECT_EQUAL(safeArrangementsOf(3, 1), {"P..", ".P.", "..P"});
    EXPECT_EQUAL(safeArrangementsOf(4, 1), {"P...", ".P..", "..P.", "...P"});
}

PROVIDED_TEST("Handles common impossible varieties.") {
    EXPECT_EQUAL(safeArrangementsOf(0, 40000), { });
    EXPECT_EQUAL(safeArrangementsOf(4, 0), {"...."});
    EXPECT_EQUAL(safeArrangementsOf(10, 10), { });
}

PROVIDED_TEST("Handles two people in small lines.") {
    EXPECT_EQUAL(safeArrangementsOf(0, 2), { });
    EXPECT_EQUAL(safeArrangementsOf(1, 2), { });
    EXPECT_EQUAL(safeArrangementsOf(2, 2), { });
    EXPECT_EQUAL(safeArrangementsOf(3, 2), { });
    EXPECT_EQUAL(safeArrangementsOf(4, 2), { "P..P" });
}

PROVIDED_TEST("Handles no people in small lines.") {
    EXPECT_EQUAL(safeArrangementsOf(0, 0), {""});
    EXPECT_EQUAL(safeArrangementsOf(1, 0), {"."});
    EXPECT_EQUAL(safeArrangementsOf(2, 0), {".."});
    EXPECT_EQUAL(safeArrangementsOf(3, 0), {"..."});
    EXPECT_EQUAL(safeArrangementsOf(4, 0), {"...."});
}

PROVIDED_TEST("Handles three people in small lines.") {
    EXPECT_EQUAL(safeArrangementsOf(0, 3), { });
    EXPECT_EQUAL(safeArrangementsOf(1, 3), { });
    EXPECT_EQUAL(safeArrangementsOf(2, 3), { });
    EXPECT_EQUAL(safeArrangementsOf(3, 3), { });
    EXPECT_EQUAL(safeArrangementsOf(4, 3), { });
}

PROVIDED_TEST("Handles three people in medium-sized lines.") {
    EXPECT_EQUAL(safeArrangementsOf(7, 3), { "P..P..P" });
    EXPECT_EQUAL(safeArrangementsOf(8, 3), { "P..P..P.",
                                             "P..P...P",
                                             "P...P..P",
                                             ".P..P..P" });
}

PROVIDED_TEST("Handles two people in a big line.") {
    EXPECT_EQUAL(safeArrangementsOf(8, 2), {
                     "P..P....",
                     "P...P...",
                     "P....P..",
                     "P.....P.",
                     "P......P",
                     ".P..P...",
                     ".P...P..",
                     ".P....P.",
                     ".P.....P",
                     "..P..P..",
                     "..P...P.",
                     "..P....P",
                     "...P..P.",
                     "...P...P",
                     "....P..P"
                 });
}

PROVIDED_TEST("Handles four people in medium-sized lines.") {
    EXPECT_EQUAL(safeArrangementsOf(12, 4), {
                     "P..P..P..P..",
                     "P..P..P...P.",
                     "P..P..P....P",
                     "P..P...P..P.",
                     "P..P...P...P",
                     "P..P....P..P",
                     "P...P..P..P.",
                     "P...P..P...P",
                     "P...P...P..P",
                     "P....P..P..P",
                     ".P..P..P..P.",
                     ".P..P..P...P",
                     ".P..P...P..P",
                     ".P...P..P..P",
                     "..P..P..P..P"
                 });
}

PROVIDED_TEST("Stress test: Handles ten people in a reasonably-sized line. (This should take at most a few seconds.)") {
    EXPECT_EQUAL(safeArrangementsOf(32, 10).size(), 1001);
}

PROVIDED_TEST("Stress test: Handles ten people in the smallest possible line") {
    EXPECT_EQUAL(safeArrangementsOf(28, 10), {"P..P..P..P..P..P..P..P..P..P"});
}
