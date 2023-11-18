#pragma once
#include <iostream>

class Fraction {
public:
    Fraction();              // default constructor
    Fraction(int n, int d);  // constructor

    void add(Fraction &f);
    void multiply(Fraction &f);

    double decimal();
    int getNum();
    int getDenom();

    friend std::ostream& operator<<(std::ostream &out, Fraction &frac);
    friend Fraction operator*(Fraction &first, Fraction &second);
    friend void operator*=(Fraction &first, Fraction &second);
    friend bool operator<(Fraction &first, Fraction &second);

private:
    int num;    // the numerator
    int denom;  // the denominator

    void reduce();
    int gcd(int u, int v);
};
