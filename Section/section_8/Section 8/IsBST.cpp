#include "IsBST.h"
using namespace std;

bool isBST(Node* root) {
    (void) root;
    return false;
}

/* * * * * Test Cases Below This Point * * * * */
#include "GUI/SimpleTest.h"

PROVIDED_TEST("Works on simple trees.") {
    EXPECT(isBST(nullptr));

    Node* tree;

    tree = toTree("137");
    EXPECT(isBST(tree));
    freeTree(tree);

    tree = toTree(R"(   137   )",
                  R"(  /      )",
                  R"( 42      )");
    EXPECT(isBST(tree));
    freeTree(tree);

    tree = toTree(R"(   137   )",
                  R"(  /      )",
                  R"(642      )");
    EXPECT(!isBST(tree));
    freeTree(tree);

    tree = toTree(R"(   137   )",
                  R"(      \  )",
                  R"(      271)");
    EXPECT(isBST(tree));
    freeTree(tree);

    tree = toTree(R"(   137   )",
                  R"(      \  )",
                  R"(      27 )");
    EXPECT(!isBST(tree));
    freeTree(tree);

    tree = toTree(R"(   137   )",
                  R"(  /   \  )",
                  R"( 42   271)");
    EXPECT(isBST(tree));
    freeTree(tree);

    tree = toTree(R"(   137   )",
                  R"(  /   \  )",
                  R"(942   271)");
    EXPECT(!isBST(tree));
    freeTree(tree);

    tree = toTree(R"(   137   )",
                  R"(  /   \  )",
                  R"( 42   27 )");
    EXPECT(!isBST(tree));
    freeTree(tree);

    tree = toTree(R"(   937   )",
                  R"(  /   \  )",
                  R"( 42   271)");
    EXPECT(!isBST(tree));
    freeTree(tree);
}

PROVIDED_TEST("Works on more complex trees.") {
    Node* tree;

    tree = toTree(R"(      1       )",
                  R"(     / \      )",
                  R"(    /   2     )",
                  R"(   /   / \    )",
                  R"(  3   4   5   )",
                  R"( / \   \   \  )",
                  R"(6   7   8   9 )");
    EXPECT(!isBST(tree));
    freeTree(tree);

    tree = toTree(R"(      7       )",
                  R"(     / \      )",
                  R"(    /   13    )",
                  R"(   /   / \    )",
                  R"(  3   9   15  )",
                  R"( / \   \   \  )",
                  R"(1   5   11  17)");
    EXPECT(isBST(tree));
    freeTree(tree);
}
