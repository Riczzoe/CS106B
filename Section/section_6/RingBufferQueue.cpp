#include "RingBufferQueue.h"
#include "error.h"
using namespace std;

/* Capacity of a RingBufferQueue. */
const int kNumSlots = 5; // Matches diagram above

RingBufferQueue::RingBufferQueue() {
    /* Create our array. */
    elems = new int[kNumSlots];
    allocatedSize = kNumSlots;

    /* We're logically empty at this point; no items have been added. */
    logicalSize = 0;

    /* Head begins at the beginning - though it in principle could go
     * anywhere within the array.
     */
    head = 0;
}

RingBufferQueue::~RingBufferQueue() {
    delete[] elems;
}

/* Adds a value right after the last position. */
void RingBufferQueue::enqueue(int value) {
    /* If we're at full capacity, there's no room left. */
    if (size() == allocatedSize) {
        error("Already packed like sardines in here!");
    }

    /* Determine where this element goes. If we didn't have any wraparound,
     * we would go at position head + size(). However, we have to account
     * for the fact that this might walk off the end of the array, in which
     * case we need to wrap around to the beginning. The modulus operator
     * is our friend here. By computing (head + size()) % allocatedSize,
     * one of the two things happen:
     *
     *   1. If head + size() < allocatedSize, then the remainder when we
     *      do the division is head + size().
     *   2. If head + size() >= allocatedSize, then the remainder of the
     *      division will be what we get when we subtract out as many
     *      copies of allocatedSize as we can.
     *
     * More generally, modding by an array size essentially says "wrap me
     * around to the right position."
     */
    elems[(head + size()) % allocatedSize] = value;
    logicalSize++;
}

int RingBufferQueue::peek() const {
    /* Make sure there's something here to return. */
    if (isEmpty()) {
        error("Nothing to see here folks, move along.");
    }

    /* Look at the position given by the head. */
    return elems[head];
}

int RingBufferQueue::dequeue() {
    /* This also does error-checking for us. Nifty! */
    int result = peek();

    /* The head needs to move forward a step, possibly wrapping around. Above,
     * we did this using the mod operator. Just to show another strategy, we'll
     * use if statements here.
     */
    head++;
    if (head == allocatedSize) head = 0;

    /* As usual, we don't actually get rid of the integer we're removing. We
     * just pretend it doesn't exist.
     */
    logicalSize--;

    return result;
}

int RingBufferQueue::size() const {
    return logicalSize; // Number of slots used
}

bool RingBufferQueue::isEmpty() const {
    return size() == 0;
}


/* * * * * * Test Cases Below This Point * * * * */
#include "GUI/SimpleTest.h"

PROVIDED_TEST("Handles large numbers of enqueues followed by dequeues.") {
    RingBufferQueue q;

    for (int i = 0; i < 10000; i++) {
        q.enqueue(i);
    }

    for (int i = 0; i < 10000; i++) {
        EXPECT_EQUAL(q.dequeue(), i);
    }
}

PROVIDED_TEST("Handles interleaved enqueues and dequeues.") {
    RingBufferQueue q;

    int nextIn = 0, nextOut = 0;

    for (int i = 0; i < 10000; i++) {
        q.enqueue(nextIn); nextIn++;
        q.enqueue(nextIn); nextIn++;

        EXPECT_EQUAL(q.dequeue(), nextOut);
        nextOut++;
    }
}
