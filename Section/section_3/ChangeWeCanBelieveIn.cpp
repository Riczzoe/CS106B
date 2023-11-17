#include "ChangeWeCanBelieveIn.h"
#include "error.h"
using namespace std;

int fewestCoinsFor(int cents, const Set<int>& coins) {
    (void) cents;
    (void) coins;
    return -1;
}

/* * * * * Test Cases Below This Point * * * * */
#include "GUI/SimpleTest.h"

PROVIDED_TEST("Works for US currency.") {
    Set<int> usCoins = { 1, 5, 10, 25, 50, 100 };

    EXPECT_EQUAL(fewestCoinsFor(13,  usCoins), 4);
    EXPECT_EQUAL(fewestCoinsFor(26,  usCoins), 2);
    EXPECT_EQUAL(fewestCoinsFor(54,  usCoins), 5);
    EXPECT_EQUAL(fewestCoinsFor(88,  usCoins), 6);
    EXPECT_EQUAL(fewestCoinsFor(189, usCoins), 8);
}

PROVIDED_TEST("Works for Recursian currency.") {
    Set<int> rCoins = { 1, 12, 14, 63 };

    EXPECT_EQUAL(fewestCoinsFor(12,  rCoins), 1);
    EXPECT_EQUAL(fewestCoinsFor(11,  rCoins), 11);
    EXPECT_EQUAL(fewestCoinsFor(24,  rCoins), 2);
}

/* All denominations of coinage that have ever been issued in the United States,
 * ranging from 1 cent to $100.
 */
const Set<int> kAllUSDenominations = {
           // Half-cent coins used to exist, but are too small for an int. :-(
    1,
    2,     // Two-cent coins were minted from 1864 - 1873
    3,     // Three-cent nickels were minted from 1865 - 1889
    5,
    10,
    20,    // Twenty-cent coins were minted from 1875 - 1878
    25,
    50,
    100,
    250,   // "Quarter eagle" coins were minted from 1796-1929
    300,   // Three-dollar gold coins were minted from 1854 - 1889
    400,   // Four-dollar gold coins were minted from 1879 - 1880
    500,   // "Half eagle" coins were minted from  1795 - 1929
    1000,  // "Eagle" coins were minted from 1792 - 1933
    2000,  // "Double eagle" coins were minted from 1792 - 1933
    2500,  // "Quarter Platinum Eagle" coins have been minted since 1995
    5000,  // "American Gold Eagle" and "American Buffalo" coins have been minted since 1985
    10000  // "American Platinum Eagle" coins have been minted since 1995
};

PROVIDED_TEST("Works for historical US currency.") {
    EXPECT_EQUAL(fewestCoinsFor(4,  kAllUSDenominations), 2);
    EXPECT_EQUAL(fewestCoinsFor(24, kAllUSDenominations), 3);
    EXPECT_EQUAL(fewestCoinsFor(37, kAllUSDenominations), 3);
}

PROVIDED_TEST("Stress test: Handles historical US currency and memoization.") {
    EXPECT_EQUAL(fewestCoinsFor(1234, kAllUSDenominations), 7);
    EXPECT_EQUAL(fewestCoinsFor(2345, kAllUSDenominations), 4);
    EXPECT_EQUAL(fewestCoinsFor(3456, kAllUSDenominations), 6);
}
