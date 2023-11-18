#include <iostream>
#include "console.h"
#include "fraction.h"

using namespace std;

int main() {
    // create three fractions

    // a default fraction
    Fraction fracA; // should be 1/1
    cout << "fracA: " << fracA << " (should be 1/1)" << endl;

    Fraction fracB(1, 2); // 1/2
    cout << "fracB: " << fracB << " (should be 1/2)" << endl;

    Fraction fracC(2, 3); // 2/3
    cout << "fracC: " << fracC << " (should be 2/3)" << endl;

    float f = fracC.decimal();
    cout << fracC << " in decimal form: "
         << f << " (should be 0.666667)" << endl;

    cout << fracB << " * " << fracC << ": ";
    fracB.mult(fracC);
    cout << fracB << " (should be 1/3)" << endl;

    cout << fracB << " + " << fracA << ": ";
    fracB.add(fracA);
    cout << fracB << " (should be 4/3)" << endl;

    cout << fracB << " + " << fracC << ": ";
    fracB.add(fracC);
    cout << fracB << " (should be 2/1)" << endl;

    Fraction fracD(20, 20);
    cout << fracD << " (should be 1/1)" << endl;

    Fraction fracZero(0, 10); // really, 0
    cout << fracZero << " (should be 0/1)" << endl;

    Fraction fracE(1, 3);
    Fraction fracF(1, 4);
    cout << fracE
         << (fracE < fracF ? " is less than " : " is not less than ")
         << fracF << endl;
    return 0;
}
