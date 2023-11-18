#include "fraction.h"

using namespace std;

Fraction::Fraction() {
    num = 1;
    denom = 1;
}

Fraction::Fraction(int num, int denom) {
    this->num = num;
    this->denom = denom;

    reduce();
}

int Fraction::getNum() {
    return num;
}

int Fraction::getDenom() {
    return denom;
}

void Fraction::add(Fraction &other) {
    num = num * other.denom + other.num * denom;
    denom *= other.denom;

    reduce();
}

void Fraction::multiply(Fraction &f) {
    num *= f.num;
    denom *= f.denom;

    reduce();
}

double Fraction::decimal() {
    return (double) num / denom;
}

void Fraction::reduce() {
    int divisor = gcd(num, denom);

    num /= divisor;
    denom /= divisor;
}

int Fraction::gcd(int u, int v) {
    if (v != 0) {
        return gcd(v, u % v);
    } else {
        return u;
    }
}

ostream &operator<<(ostream &out, Fraction &frac) {
    out << frac.num << "/" << frac.denom;
    return out;
}

Fraction operator*(Fraction &first, Fraction &second) {
    int newNum = first.num * second.denom + 
                 second.num * first.denom;
    int newDenom = first.denom * second.denom;
    return Fraction(newNum, newDenom);
}

void operator*= (Fraction &first, Fraction &second) {
    first.num *= second.num;
    first.denom *= second.denom;
    first.reduce();
}

bool operator< (Fraction &first, Fraction &second) {
    return first.decimal() < second.decimal();
}

