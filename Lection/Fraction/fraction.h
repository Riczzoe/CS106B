#pragma once
#include <ostream>

class Fraction {
  public:
    Fraction();
    Fraction(int num, int denom);

    void add(Fraction &f);
    void mult(Fraction &f);

    double decimal();
    int getNum();
    int getDenom();

    friend std::ostream &operator<<(std::ostream &out, Fraction &frac);
    friend Fraction operator*(Fraction &first, Fraction &second);
    friend bool operator<(Fraction &first, Fraction &second);

  private:
    int num;
    int denom;

    void reduce();
    int gcd(int u, int v);
};
