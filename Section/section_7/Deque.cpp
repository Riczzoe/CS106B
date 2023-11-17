#include "Deque.h"
using namespace std;

Deque::Deque() {

}

Deque::~Deque() {

}

int Deque::size() const {
    return -1;
}

bool Deque::isEmpty() const {
    return false;
}

void Deque::pushFront(int value) {
    (void) value;
}

void Deque::pushBack(int value) {
    (void) value;
}

int Deque::peekFront() const {
    return -1;
}

int Deque::peekBack() const {
    return -1;
}

int Deque::popFront() {
    return -1;
}

int Deque::popBack() {
    return -1;
}

/* * * * * Test Cases Below This Point * * * * */
#include "GUI/SimpleTest.h"

PROVIDED_TEST("Basic correctness checks.") {
    Deque d;

    EXPECT_EQUAL(d.isEmpty(), true);
    EXPECT_EQUAL(d.size(),       0);
    EXPECT_ERROR(d.peekFront());
    EXPECT_ERROR(d.peekBack());
    EXPECT_ERROR(d.popFront());
    EXPECT_ERROR(d.popBack());

    d.pushFront(2);
    d.pushFront(1);
    d.pushBack(3);

    EXPECT_EQUAL(d.size(), 3);
    EXPECT_EQUAL(d.isEmpty(), false);
    EXPECT_EQUAL(d.peekFront(), 1);
    EXPECT_EQUAL(d.peekBack(), 3);

    EXPECT_EQUAL(d.popFront(), 1);

    EXPECT_EQUAL(d.size(), 2);
    EXPECT_EQUAL(d.isEmpty(), false);
    EXPECT_EQUAL(d.peekFront(), 2);
    EXPECT_EQUAL(d.peekBack(), 3);

    EXPECT_EQUAL(d.popBack(), 3);

    EXPECT_EQUAL(d.size(), 1);
    EXPECT_EQUAL(d.isEmpty(), false);
    EXPECT_EQUAL(d.peekFront(), 2);
    EXPECT_EQUAL(d.peekBack(), 2);

    EXPECT_EQUAL(d.popBack(), 2);

    EXPECT_EQUAL(d.isEmpty(), true);
    EXPECT_EQUAL(d.size(),       0);
    EXPECT_ERROR(d.peekFront());
    EXPECT_ERROR(d.peekBack());
    EXPECT_ERROR(d.popFront());
    EXPECT_ERROR(d.popBack());
}
