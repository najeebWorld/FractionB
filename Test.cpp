#define CATCH_CONFIG_MAIN
#include "./sources/Fraction.hpp"
#include "doctest.h"
#include <iostream>
#include <stdexcept>
#include <vector>
#include <cassert>
#include <string.h>
#include <stdexcept>

using namespace std;
using namespace ariel;

TEST_CASE("Test Fraction Addition") {
    Fraction f1(1, 2);
    Fraction f2(1, 3);
    Fraction f3 = f1 + f2;

    CHECK(f3.getNumerator() == 5);
    CHECK(f3.getDenominator() == 6);
    CHECK_NOTHROW(f3.reduce());
}

TEST_CASE("Test Fraction Subtraction") {
    Fraction f1(3, 4);
    Fraction f2(1, 4);
    Fraction f3 = f1 - f2;

    CHECK(f3.getNumerator() == 1);
    CHECK(f3.getDenominator() == 2);
    CHECK_NOTHROW(f3.reduce());
}

TEST_CASE("Test Fraction Multiplication") {
    Fraction f1(2, 3);
    Fraction f2(3, 4);
    Fraction f3 = f1 * f2;

    CHECK(f3.getNumerator() == 1);
    CHECK(f3.getDenominator() == 2);
    CHECK_NOTHROW(f3.reduce());
}

TEST_CASE("Test Fraction Division") {
    Fraction f1(3, 5);
    Fraction f2(2, 3);
    Fraction f3 = f1 / f2;

    CHECK(f3.getNumerator() == 9);
    CHECK(f3.getDenominator() == 10);
    CHECK_NOTHROW(f3.reduce());
}

TEST_CASE("Test Fraction Equality") {
    Fraction f1(2, 4);
    Fraction f2(1, 2);
    Fraction f3(3, 6);

    CHECK(f1 == f2);
    CHECK(f1 == f3);
    CHECK(f2 == f3);
}

TEST_CASE("Test Fraction Inequality") {
    Fraction f1(1, 3);
    Fraction f2(2, 5);
    Fraction f3(4, 7);

    CHECK(f1 != f2);
    CHECK(f1 != f3);
    CHECK(f2 != f3);
}

TEST_CASE("Test Fraction Greater Than") {
    Fraction f1(1, 4);
    Fraction f2(1, 5);

    CHECK(f1 > f2);
    CHECK(!(f2 > f1));
}

TEST_CASE("Test Fraction Less Than") {
    Fraction f1(2, 3);
    Fraction f2(3, 4);

    CHECK(f1 < f2);
    CHECK(!(f2 < f1));
}

TEST_CASE("Test Fraction Greater Than or Equal To") {
    Fraction f1(1, 2);
    Fraction f2(1, 2);
    Fraction f3(1, 3);

    CHECK(f1 >= f2);
    CHECK(f1 >= f3);
    CHECK(!(f3 >= f1));
}

TEST_CASE("Test Fraction Less Than or Equal To") {
    Fraction f1(2, 5);
    Fraction f2(3, 5);
    Fraction f3(2, 7);

    CHECK(f1 <= f2);
    CHECK(f1 <= f3);
    CHECK(!(f3 <= f1));
}

TEST_CASE("Test Fraction Division") {
    Fraction f1(3, 5);
    Fraction f2(4, 7);
    Fraction f3 = f1 / f2;
    CHECK(f3 == Fraction(21, 20));
    CHECK_NOTHROW(f3 = f1 / f2);
}

TEST_CASE("Test Fraction Equality") {
    Fraction f1(2, 3);
    Fraction f2(4, 6);
    Fraction f3(3, 4);
    CHECK(f1 == f2);
    CHECK_FALSE(f1 == f3);
    CHECK(f1 == f2);
}

TEST_CASE("Test Fraction Comparison") {
    Fraction f1(1, 2);
    Fraction f2(2, 3);
    Fraction f3(3, 4);
    CHECK(f1 < f2);
    CHECK(f2 > f1);
    CHECK(f2 <= f3);
    CHECK(f3 >= f2);
    CHECK_FALSE(f1 > f3);
    CHECK_FALSE(f3 < f1);
    CHECK(f1 < f2);
}

TEST_CASE("Test Fraction Increment/Decrement") {
    Fraction f1(3, 4);
    Fraction f2(2, 5);
    CHECK(++f1 == Fraction(7, 4));
    CHECK(f1++ == Fraction(7, 4));
    CHECK(f1 == Fraction(11, 4));
    CHECK(--f2 == Fraction(-3, 5));
    CHECK(f2-- == Fraction(-3, 5));
    CHECK(f2 == Fraction(-8, 5));
    CHECK_NOTHROW(++f1);
    CHECK_NOTHROW(--f2);
}


