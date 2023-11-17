#include "PalindromicTrees.h"
using namespace std;

bool isPalindromicTree(Node* root) {
    (void) root;
    return false;
}

/* * * * * Test Cases Below This Point * * * * */
#include "GUI/SimpleTest.h"

PROVIDED_TEST("Works for simple examples.") {
    EXPECT(isPalindromicTree(nullptr));

    Node* tree;

    tree = toTree("137");
    EXPECT(isPalindromicTree(tree));
    freeTree(tree);

    tree = toTree(R"(  4  )",
                  R"( / \ )",
                  R"(1   2)");
    EXPECT(!isPalindromicTree(tree));
    freeTree(tree);

    tree = toTree(R"(  4  )",
                  R"( / \ )",
                  R"(2   1)");
    EXPECT(!isPalindromicTree(tree));
    freeTree(tree);

    tree = toTree(R"(  4  )",
                  R"( / \ )",
                  R"(1   1)");
    EXPECT(isPalindromicTree(tree));
    freeTree(tree);
}

PROVIDED_TEST("Works on the examples in the problem statement.") {
    Node* tree;

    tree = toTree(R"(        3        )",
                  R"(       / \       )",
                  R"(      /   \      )",
                  R"(     /     \     )",
                  R"(    /       \    )",
                  R"(   2         2   )",
                  R"(  / \       / \  )",
                  R"( 5   4     4   5 )",
                  R"(    / \   / \    )",
                  R"(   1   2 2   1   )");
    EXPECT(isPalindromicTree(tree));
    freeTree(tree);

    tree = toTree(R"(       3        )",
                  R"(      / \       )",
                  R"(     /   \      )",
                  R"(    /     \     )",
                  R"(   1       1   )",
                  R"(  / \     / \  )",
                  R"( 1   2   1   2 )");
    EXPECT(!isPalindromicTree(tree));
    freeTree(tree);
}
