#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>
#include <cmath>
using namespace std;

namespace ariel{
class Fraction {

private:
    int numerator;
    int denominator;

public:
    // Constructors
    Fraction();
    Fraction(int num, int den);
    Fraction(float num);

    // Getters
    int getNumerator() const;
    int getDenominator() const;
    
        // Friend functions for input/output;
    friend ostream& operator<<(ostream& os , const Fraction& f);
    friend std::istream& operator>>(std::istream& is, Fraction& fraction);
    
    // Overloaded operators
    Fraction operator+(const Fraction& other) const;
    Fraction operator-(const Fraction& other) const;
    Fraction operator*(const Fraction& other) const;
    Fraction operator/(const Fraction& other) const;
    bool operator==(const Fraction& other) const;
    bool operator!=(const Fraction& other) const;
    bool operator>(const Fraction& other) const;
    bool operator<(const Fraction& other) const;
    bool operator>=(const Fraction& other) const;
    bool operator<=(const Fraction& other) const;
    Fraction operator++();
    Fraction operator++(int);
    Fraction operator--();
    Fraction operator--(int);



    friend Fraction operator*(float a, const Fraction& other);
    void reduce();

private:
    // Helper functions
    int gcd(int a, int b) const;
};
}

#endif  // FRACTION_H
