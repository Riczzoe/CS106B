#include "LicensePlateGame.h"
#include "strlib.h"
using namespace std;

bool wordMatchesPlate(string word, string plate) {
    (void) word;
    (void) plate;
    return false;
}

/* * * * * Test Cases Below This Point * * * * */
#include "GUI/SimpleTest.h"


PROVIDED_TEST("Works on a simple license plate.") {
    /* Literally the same. */
    EXPECT(wordMatchesPlate("8JSP137", "8JSP137"));

    /* Just the letters. */
    EXPECT(wordMatchesPlate("JSP", "8JSP137"));

    /* Extra letters added. */
    EXPECT(wordMatchesPlate("JASPER", "8JSP137"));

    /* Same letters, different order. */
    EXPECT(!wordMatchesPlate("SUPERMAJORITY", "8JSP137"));
}

PROVIDED_TEST("Is case-insensitive.") {
    EXPECT(wordMatchesPlate("KOOTENAY", "3KTY271"));
    EXPECT(wordMatchesPlate("kootenay", "3KTY271"));
    EXPECT(wordMatchesPlate("kOoTeNaY", "3KTY271"));
}

PROVIDED_TEST("Works if license plate doesn't have exactly three letters.") {
    EXPECT(wordMatchesPlate("GALACTOSE", "GC2020"));
    EXPECT(!wordMatchesPlate("CAGEY", "GC2020"));
    EXPECT(wordMatchesPlate("HYPOCHLORITE", "2YOHO"));
    EXPECT(!wordMatchesPlate("YAHOO", "2YOHO"));
    EXPECT(wordMatchesPlate("ANYTHINGGOES", ""));
}
