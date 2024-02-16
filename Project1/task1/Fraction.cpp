#include "Fraction.h"
#include <iostream>

Fraction::Fraction(int numerator, int denominator) {
    this->numerator = numerator;
    this->denominator = denominator;
}

void Fraction::setNumerator(int numerator) {
    this->numerator = numerator;
}

void Fraction::setDenominator(int denominator) {
    this->denominator = denominator;
}

int Fraction::getNumerator() {
    return numerator;
}

int Fraction::getDenominator() {
    return denominator;
}

void Fraction::showFraction() {
    std::cout << numerator << "/" << denominator << std::endl;
}