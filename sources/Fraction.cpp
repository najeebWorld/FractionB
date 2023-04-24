#include "Fraction.hpp"
#include <iostream>
#include <cmath>

using namespace std;
using namespace ariel;

// Constructors
Fraction::Fraction() : numerator(0), denominator(1) {}

Fraction::Fraction(int num, int den) : numerator(num), denominator(den) {
    reduce();
}

Fraction::Fraction(float num) {
    // Convert float to fraction
    int den = 1;
    while (floor(num) != num) {
        num *= 10;
        den *= 10;
    }
    numerator = static_cast<int>(num);
    denominator = den;
    reduce();
}

// Getters
int Fraction::getNumerator() const {
    return numerator;
}

int Fraction::getDenominator() const {
    return denominator;
}

// Overloaded operators
Fraction Fraction::operator+(const Fraction& other) const {
    int num = numerator * other.denominator + other.numerator * denominator;
    int den = denominator * other.denominator;
    return Fraction(num, den);
}

Fraction Fraction::operator-(const Fraction& other) const {
    int num = numerator * other.denominator - other.numerator * denominator;
    int den = denominator * other.denominator;
    return Fraction(num, den);
}

Fraction Fraction::operator*(const Fraction& other) const {
    int num = numerator * other.numerator;
    int den = denominator * other.denominator;
    return Fraction(num, den);
}

Fraction Fraction::operator/(const Fraction& other) const {
    int num = numerator * other.denominator;
    int den = denominator * other.numerator;
    return Fraction(num, den);
}

bool Fraction::operator==(const Fraction& other) const {
    return (numerator == other.numerator) && (denominator == other.denominator);
}

bool Fraction::operator!=(const Fraction& other) const {
    return !(*this == other);
}

bool Fraction::operator>(const Fraction& other) const {
    return (numerator * other.denominator) > (other.numerator * denominator);
}

bool Fraction::operator<(const Fraction& other) const {
    return (numerator * other.denominator) < (other.numerator * denominator);
}

bool Fraction::operator>=(const Fraction& other) const {
    return !(*this < other);
}

bool Fraction::operator<=(const Fraction& other) const {
    return !(*this > other);
}

Fraction Fraction::operator++() {
    // Pre-increment
    numerator += denominator;
    reduce();
    return *this;
}

Fraction Fraction::operator++(int) {
    // Post-increment
    Fraction temp = *this;
    numerator += denominator;
    reduce();
    return temp;
}

Fraction Fraction::operator--() {
    // Pre-decrement
    numerator -= denominator;
    reduce();
    return *this;
}

Fraction Fraction::operator--(int) {
    // Post-decrement
    Fraction temp = *this;
    numerator -= denominator;
    reduce();
    return temp;
}

// Friend functions for input/output
ostream& ariel::operator<<(ostream& os, const Fraction& f) {
    os << f.numerator << '/' << f.denominator;
    return os;
}

istream& ariel::operator>>(istream& is, Fraction& fraction) {
    char slash;
    is >> fraction.numerator >> slash >> fraction.denominator;
    fraction.reduce();
    return is;
}

// Helper functions
int Fraction::gcd(int a, int b) const {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// Friend function for scalar multiplication
Fraction ariel::operator*(float a, const Fraction& other) {
    int num = static_cast<int>(a * other.numerator);
    int den = other.denominator;
    return Fraction(num, den);
}

// Reduce the fraction to its simplest form
void Fraction::reduce() {
    int divisor = gcd(numerator, denominator);
    numerator /= divisor;
    denominator /= divisor;

    // Make sure the denominator is always positive
    if (denominator < 0) {
        numerator *= -1;
        denominator *= -1;
    }
}

