#include "UltimateAndPenultimate.h"
using namespace std;

Node* biggestNodeIn(Node* root) {
    (void) root;
    return nullptr;
}

Node* secondBiggestNodeIn(Node* root) {
    (void) root;
    return nullptr;
}

/* * * * * Test Cases Beow This Point * * * * */
#include "GUI/SimpleTest.h"

PROVIDED_TEST("biggestNodeIn works in simple cases.") {
    Node* tree;
    tree = toTree("137");
    EXPECT_EQUAL(biggestNodeIn(tree), tree);
    freeTree(tree);

    tree = toTree(R"(    137    )",
                  R"(   /       )",
                  R"(  42       )");
    EXPECT_EQUAL(biggestNodeIn(tree), tree);
    freeTree(tree);

    tree = toTree(R"(    42     )",
                  R"(      \    )",
                  R"(       137 )");
    EXPECT_EQUAL(biggestNodeIn(tree), tree->right);
    freeTree(tree);
}

PROVIDED_TEST("biggestNodeIn works for a more complex tree.") {
    Node* tree = toTree(R"(      7       )",
                        R"(     / \      )",
                        R"(    /   13    )",
                        R"(   /   / \    )",
                        R"(  3   9   15  )",
                        R"( / \   \   \  )",
                        R"(1   5   11  17)");
    EXPECT_EQUAL(biggestNodeIn(tree), tree->right->right->right);
    freeTree(tree);
}

PROVIDED_TEST("biggestNodeIn calls error() when appropriate.") {
    EXPECT_ERROR(biggestNodeIn(nullptr));
}

PROVIDED_TEST("secondBiggestNodeIn works in simple cases.") {
    Node* tree;
    tree = toTree(R"(    137    )",
                  R"(   /       )",
                  R"(  42       )");
    EXPECT_EQUAL(secondBiggestNodeIn(tree), tree->left);
    freeTree(tree);

    tree = toTree(R"(    42     )",
                  R"(      \    )",
                  R"(       137 )");
    EXPECT_EQUAL(secondBiggestNodeIn(tree), tree);
    freeTree(tree);
}

PROVIDED_TEST("secondBiggestNodeIn works for more complex trees.") {
    Node* tree;
    tree = toTree(R"(      7       )",
                  R"(     / \      )",
                  R"(    /   13    )",
                  R"(   /   / \    )",
                  R"(  3   9   15  )",
                  R"( / \   \   \  )",
                  R"(1   5   11  17)");
    EXPECT_EQUAL(secondBiggestNodeIn(tree), tree->right->right);
    freeTree(tree);

    tree = toTree(R"(      7       )",
                  R"(     / \      )",
                  R"(    /   13    )",
                  R"(   /   /      )",
                  R"(  3   9       )",
                  R"( / \   \      )",
                  R"(1   5   11    )");
    EXPECT_EQUAL(secondBiggestNodeIn(tree), tree->right->left->right);
    freeTree(tree);
}

PROVIDED_TEST("secondBiggestNodeIn reports errors on bad inputs.") {
    EXPECT_ERROR(secondBiggestNodeIn(nullptr));

    Node* tree;
    tree = toTree("137");
    EXPECT_ERROR(secondBiggestNodeIn(tree));
    freeTree(tree);
}
