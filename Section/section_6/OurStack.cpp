#include "OurStack.h"
#include "error.h"
using namespace std;

const int kInitialSize = 4;

OurStack::OurStack() {
    elems = new int[kInitialSize];
    logicalSize = 0;
    allocatedSize = kInitialSize;
}

OurStack::~OurStack() {
    delete[] elems;
}

void OurStack::push(int value) {
    if (logicalSize == allocatedSize) {
        grow();
    }
    elems[logicalSize] = value;
    logicalSize++;
}

int OurStack::peek() const {
    if (isEmpty()) {
        error("What is the sound of one hand clapping?");
    }
    return elems[logicalSize - 1];
}

int OurStack::pop() {
    int result = peek();
    logicalSize--;
    return result;
}

int OurStack::size() const {
    return logicalSize;
}

bool OurStack::isEmpty() const {
    return size() == 0;
}

void OurStack::grow() {
    int* newArr = new int[2 * allocatedSize];
    for (int i = 0; i < size(); i++) {
        newArr[i] = elems[i];
    }
    delete[] elems;
    elems = newArr;
    allocatedSize *= 2;
}

/* * * * * Test Cases Below This Point * * * * */
PROVIDED_TEST("Stack shrinks once it's less than 1/4 full.") {
    OurStack stack;

    /* Add 16 items to make the array have size 16. */
    for (int i = 0; i < 16; i++) {
        stack.push(i);
    }

    /* Confirm the internal state is correct. */
    EXPECT_EQUAL(stack.logicalSize,   16);
    EXPECT_EQUAL(stack.allocatedSize, 16);

    /* Write down the elements pointer. */
    int* oldElems = stack.elems;

    /* Now, remove 12 items. */
    for (int i = 15; i >= 4; i--) {
        EXPECT_EQUAL(stack.pop(), i);
    }

    /* Confirm we have the same pointer. */
    EXPECT_EQUAL(stack.elems, oldElems);

    /* Now pop once more. */
    EXPECT_EQUAL(stack.pop(), 3);

    /* Confirm we shrank. */
    EXPECT_EQUAL(stack.size(), 3);
    EXPECT_NOT_EQUAL(stack.elems, oldElems);
    EXPECT_EQUAL(stack.allocatedSize, 8);
    oldElems = stack.elems;

    /* Now drop to one element. */
    EXPECT_EQUAL(stack.pop(), 2);
    EXPECT_EQUAL(stack.elems, oldElems);
    EXPECT_EQUAL(stack.pop(), 1);
    EXPECT_NOT_EQUAL(stack.elems, oldElems);
    EXPECT_EQUAL(stack.allocatedSize, 4);
    oldElems = stack.elems;

    /* Drop to zero elements. We shouldn't shrink. */
    EXPECT_EQUAL(stack.pop(), 0);
    EXPECT_EQUAL(stack.elems, oldElems);
    EXPECT_EQUAL(stack.allocatedSize, 4);
}
