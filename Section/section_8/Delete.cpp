#include "Delete.h"
using namespace std;

void removeFrom(Node*& root, int value) {
    (void) root;
    (void) value;
}

/* * * * * Test Cases Below This Point * * * * */
#include "GUI/SimpleTest.h"
#include "Treequality.h"
/* NOTE: These tests assume you have implemented the areEqual function from elsewhere in this
 * section handout.
 */

PROVIDED_TEST("Works in Case 1.") {
    Node* tree = toTree(R"(      7       )",
                        R"(     / \      )",
                        R"(    /   13    )",
                        R"(   /   / \    )",
                        R"(  3   9   15  )",
                        R"( / \   \   \  )",
                        R"(1   5   11  17)");

    Node* expected = toTree(R"(      7       )",
                            R"(     / \      )",
                            R"(    /   13    )",
                            R"(   /   / \    )",
                            R"(  3   9   15  )",
                            R"(   \   \   \  )",
                            R"(    5   11  17)");

    removeFrom(tree, 1);
    EXPECT(areEqual(tree, expected));
    freeTree(expected);

    expected = toTree(R"(      7       )",
                      R"(     / \      )",
                      R"(    /   13    )",
                      R"(   /   / \    )",
                      R"(  3   9   15  )",
                      R"(       \   \  )",
                      R"(        11  17)");
    removeFrom(tree, 5);
    EXPECT(areEqual(tree, expected));
    freeTree(tree);
    freeTree(expected);
}

PROVIDED_TEST("Works in Case 2.") {
    Node* tree = toTree(R"(      7       )",
                        R"(     / \      )",
                        R"(    /   13    )",
                        R"(   /   / \    )",
                        R"(  3   9   15  )",
                        R"( /     \   \  )",
                        R"(1       11  17)");

    Node* expected = toTree(R"(      7       )",
                            R"(     / \      )",
                            R"(    /   13    )",
                            R"(   /   / \    )",
                            R"(  3  11   15  )",
                            R"( /         \  )",
                            R"(1           17)");

    removeFrom(tree, 9);
    EXPECT(areEqual(tree, expected));
    freeTree(expected);

    expected = toTree(R"(      7       )",
                      R"(     / \      )",
                      R"(    /   13    )",
                      R"(   /   / \    )",
                      R"(  1  11   15  )",
                      R"(           \  )",
                      R"(            17)");
    removeFrom(tree, 3);
    EXPECT(areEqual(tree, expected));

    freeTree(tree);
    freeTree(expected);
}

PROVIDED_TEST("Works in Case 3.1.") {
    Node* tree = toTree(R"(      7       )",
                        R"(     / \      )",
                        R"(    /   13    )",
                        R"(   /   / \    )",
                        R"(  3  11   15  )",
                        R"(    /  \   \  )",
                        R"(   9    12  17)");

    Node* expected = toTree(R"(      3       )",
                            R"(       \      )",
                            R"(        13    )",
                            R"(       / \    )",
                            R"(     11   15  )",
                            R"(    /  \   \  )",
                            R"(   9    12  17)");

    removeFrom(tree, 7);
    EXPECT(areEqual(tree, expected));
    freeTree(expected);

    expected = toTree(R"(      3       )",
                      R"(       \      )",
                      R"(        12    )",
                      R"(       / \    )",
                      R"(     11   15  )",
                      R"(    /      \  )",
                      R"(   9        17)");
    removeFrom(tree, 13);
    EXPECT(areEqual(tree, expected));
    freeTree(expected);

    freeTree(tree);
}

PROVIDED_TEST("Works in Case 3.2") {
    Node* tree = toTree(R"(      7       )",
                        R"(     / \      )",
                        R"(    /   13    )",
                        R"(   /   / \    )",
                        R"(  3  11   15  )",
                        R"( /  /      \  )",
                        R"(1  9        17)");

    Node* expected = toTree(R"(      7       )",
                            R"(     / \      )",
                            R"(    /   11    )",
                            R"(   /   / \    )",
                            R"(  3   9   15  )",
                            R"( /         \  )",
                            R"(1           17)");

    removeFrom(tree, 13);
    EXPECT(areEqual(tree, expected));
    freeTree(expected);
    freeTree(tree);
}
