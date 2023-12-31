#include "ProteinSynthesis.h"
using namespace std;

string toProtein(const string& rna, const Map<string, char>& codonMap) {
    string threeLetter;
    if (rna.length() % 3 != 0) {
        error("RNA string has a bad length.");
    }
    if (rna.length() == 0) {
        return "";
    }

    threeLetter = rna.substr(0, 3);
    if (!codonMap.containsKey(threeLetter)) {
        error("RNA string has bad codon.");
    }
    return codonMap.get(threeLetter) + toProtein(rna.substr(3), codonMap);
}

/* * * * * Test Cases Below This Point * * * * */
#include "GUI/SimpleTest.h"

/*** Tests for toProtein ***/

PROVIDED_TEST("toProtein works on empty strands.") {
    /* Should work when there's nothing in the coding map. */
    EXPECT_EQUAL(toProtein("", {}), "");

    /* Should also work when there is something in the coding map. */
    EXPECT_EQUAL(toProtein("", standardCodonMap()), "");
}

PROVIDED_TEST("toProtein reports errors on invalid inputs.") {
    /* Should fail if the input string has a bad length. */
    EXPECT_ERROR(toProtein("AAAAAAAAAA", standardCodonMap()));

    /* Should fail if the input string has a bad codon. */
    EXPECT_ERROR(toProtein("GUACAMOLE", standardCodonMap()));
}

PROVIDED_TEST("toProtein converts the examples from the assignment description.") {
    EXPECT_EQUAL(toProtein("GACAUAAAAGAUAUCAAG", standardCodonMap()), "DIKDIK");
    EXPECT_EQUAL(toProtein("CAGUGAUAGAAGAAGGCU", standardCodonMap()), "QUOKKA");
}

PROVIDED_TEST("toProtein can convert all codons.") {
    Map<string, char> codonMap = standardCodonMap();

    /* Build the input and output strings. */
    string rna, protein;
    for (string codon: codonMap) {
        rna     += codon;
        protein += codonMap[codon];
    }

    /* Confirm it works. */
    EXPECT_EQUAL(toProtein(rna, codonMap), protein);
}

PROVIDED_TEST("toProtein works with nonstandard codons.") {
    Map<string, char> notRealCodons = {
        { "CS1", 'A' },
        { "06B", '+' }
    };

    EXPECT_EQUAL(toProtein("CS106B", notRealCodons), "A+");
}
