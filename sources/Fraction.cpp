#include "Fraction.hpp"

namespace ariel{


// Constructors
Fraction::Fraction() : numerator(0), denominator(1) {
        

}
Fraction::Fraction(int num, int den) {
       
}
Fraction::Fraction(float num) {}
// Getters
int Fraction::getNumerator() const {
    return 1;
}
int Fraction::getDenominator() const {
    return 1;
}
// Overloaded operators
Fraction Fraction::operator+(const Fraction& other) const {
    return Fraction(1,2);
}
Fraction Fraction::operator-(const Fraction& other) const {
        return Fraction(1,2);

}
Fraction Fraction::operator*(const Fraction& other) const {
        return Fraction(1,2);

}
Fraction Fraction::operator/(const Fraction& other) const {
        return Fraction(1,2);

}
bool Fraction::operator==(const Fraction& other) const {
        return true;

}
bool Fraction::operator!=(const Fraction& other) const {
        return true;

}
bool Fraction::operator>(const Fraction& other) const {
        return true;

}
bool Fraction::operator<(const Fraction& other) const {
        return true;

}
bool Fraction::operator>=(const Fraction& other) const {
        return true;

}
bool Fraction::operator<=(const Fraction& other) const {
    return true;
}
Fraction Fraction::operator++() {
        return Fraction(1,2);

}
Fraction Fraction::operator++(int) {
        return Fraction(1,2);

}
Fraction Fraction::operator--() {
        return Fraction(1,2);

}
Fraction Fraction::operator--(int) {
    return Fraction(1,2);
}
Fraction operator*(float a, const Fraction& other){

    return Fraction(1,2);
}


// Friend functions for input/output
    // Friend functions for input/output;
ostream& operator<<(ostream& os,const Fraction& f){
    return os;
}
std::istream& operator>>(std::istream& is, Fraction& fraction) {
    return is;
}
// Helper functions
int Fraction::gcd(int a, int b) const {
    return 1;
}
void Fraction::reduce() {}


}