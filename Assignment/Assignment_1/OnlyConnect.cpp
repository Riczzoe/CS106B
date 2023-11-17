/* File: OnlyConnect.cpp
 *
 * TODO: Edit these comments to describe anything interesting or noteworthy in your implementation.
 *
 * TODO: Edit these comments to leave a puzzle for your section leader to solve!
 */
#include "OnlyConnect.h"
#include "strlib.h"
#include <cctype>
using namespace std;

bool isConsonants(char a) {
    bool isConsonants = false;
    if (isalpha(a)) {
        a = toUpperCase(a);
        switch (a) {
        case 'A':
        case 'E':
        case 'I':
        case 'O':
        case 'U':
            break;
        default:
            isConsonants = true;
        }
    }

    return isConsonants;
}

string onlyConnectize(string phrase) {
    if (phrase.empty()) {
        return "";
    }
    string resOfFristChar = isConsonants(phrase[0]) ? toUpperCase(string(1, phrase[0])) : "";
    return resOfFristChar + onlyConnectize(phrase.substr(1));
}

/* * * * * * Provided Test Cases * * * * * */
#include "GUI/SimpleTest.h"

PROVIDED_TEST("Handles single-character inputs.") {
    EXPECT_EQUAL(onlyConnectize("A"), "");
    EXPECT_EQUAL(onlyConnectize("Q"), "Q");
}

PROVIDED_TEST("Converts lower-case to upper-case.") {
    EXPECT_EQUAL(onlyConnectize("lowercase"), "LWRCS");
    EXPECT_EQUAL(onlyConnectize("uppercase"), "PPRCS");
}

STUDENT_TEST("Test Large case.") {
    EXPECT_EQUAL(onlyConnectize("ashdjkshdasbxbhshdkahsdbbxjkshdkbxkbxk hdksahkdb hsakhsa dkahsdhakshd ahdadahdka"),
                 "SHDJKSHDSBXBHSHDKHSDBBXJKSHDKBXKBXKHDKSHKDBHSKHSDKHSDHKSHDHDDHDK");
}

STUDENT_TEST("Test empty") {
    EXPECT_EQUAL(onlyConnectize("          "), "");
}

STUDENT_TEST("Test no alpha") {
    EXPECT_EQUAL(onlyConnectize(" }]{]  12   789792  343,  ./ ?';"), "");
}




