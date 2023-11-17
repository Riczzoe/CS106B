#include "Treequality.h"
using namespace std;

bool areEqual(Node* one, Node* two) {
    (void) one;
    (void) two;
    error("areEqual function has not yet been implemented.");
}

/* * * * * Test Cases Below This Point * * * * */
#include "GUI/SimpleTest.h"

PROVIDED_TEST("Works when one or both trees are empty.") {
    Node* empty = nullptr;
    Node* nonempty = toTree(R"(   137   )",
                            R"(  /   \  )",
                            R"( 42  271 )");

    EXPECT( areEqual(empty, empty));
    EXPECT(!areEqual(empty, nonempty));
    EXPECT(!areEqual(nonempty, empty));
    EXPECT( areEqual(nonempty, nonempty));

    freeTree(nonempty);
}

PROVIDED_TEST("Works when two trees have the same shape and different contents.") {
    Node* one = toTree(R"(   137   )",
                       R"(  /   \  )",
                       R"( 42  271 )",
                       R"( \     / )",
                       R"(  1   2  )");

    Node* two = toTree(R"(   137   )",
                       R"(  /   \  )",
                       R"( 42  271 )",
                       R"( \     / )",
                       R"(  1   3  )");

    EXPECT( areEqual(one, one));
    EXPECT(!areEqual(one, two));
    EXPECT(!areEqual(two, one));
    EXPECT( areEqual(two, two));

    freeTree(one);
    freeTree(two);
}
