#include "WeightsAndBalances.h"
using namespace std;

bool isMeasurable(int amount, const Vector<int>& weights) {
    (void) amount;
    (void) weights;
    return false;
}

/* * * * * Test Cases Below This Point * * * * */
#include "GUI/SimpleTest.h"

PROVIDED_TEST("Works for the examples from the problem statement.") {
    EXPECT( isMeasurable(2, {1, 3}));
    EXPECT(!isMeasurable(5, {1, 3}));
    EXPECT( isMeasurable(6, {1, 3, 7}));
}

PROVIDED_TEST("Can measure everything from -13 to +13 with well-chosen weights.") {
    for (int i = -13; i <= +13; i++) {
        EXPECT(isMeasurable(i, { 1, 3, 9 }));
    }
    EXPECT(!isMeasurable(-14, { 1, 3, 9 }));
    EXPECT(!isMeasurable(+14, { 1, 3, 9 }));
}
