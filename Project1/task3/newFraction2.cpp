#include "newFraction2.h"
#include <iostream>

//member functions

/**
 * @brief Construct a new Fraction object
 * 
 * @param numerator Numerator of the fraction
 * @param denominator Denominator of the fraction
*/
Fraction::Fraction(int numerator, int denominator) {
    this->numerator = numerator;
    this->denominator = denominator;
}

/**
 * @brief Construct a new Fraction object
*/
Fraction::Fraction() {
    this->numerator = 1;
    this->denominator = 1;
}

/**
 * @brief set the Numerator of the fraction
 * 
 * @param numerator Numerator of the fraction
 * @return void
*/
void Fraction::setNumerator(int numerator) {
    this->numerator = numerator;
}

/**
 * @brief set the Denominator of the fraction
 * 
 * @param denominator Denominator of the fraction
 * @return void
*/
void Fraction::setDenominator(int denominator) {
    this->denominator = denominator;
}

/**
 * @brief get the Numerator of the fraction
 * 
 * @return Numerator of the fraction
*/
int Fraction::getNumerator() {
    return numerator;
}

/**
 * @brief get the Denominator of the fraction
 * 
 * @return Denominator of the fraction
*/
int Fraction::getDenominator() {
    return denominator;
}

/**
 * @brief print the fraction in the form of "numerator/denominator"
 * 
 * @return void
*/
void Fraction::showFraction() {
    std::cout << numerator << "/" << denominator << std::endl;
}

Fraction Fraction::operator+(Fraction& fraction2) {
    //multiply fractions to get common denominator then add
    int numerator = this->numerator * fraction2.denominator + fraction2.numerator * this->denominator;
    int denominator = this->denominator * fraction2.denominator;
    return Fraction(numerator, denominator);
}

//non-member functions

Fraction operator-(Fraction& fraction1, Fraction& fraction2) {
    //multiply fractions to get common denominator then subtract
    int numerator = fraction1.getNumerator() * fraction2.getDenominator() - fraction2.getNumerator() * fraction1.getDenominator();
    int denominator = fraction1.getDenominator() * fraction2.getDenominator();
    return Fraction(numerator, denominator);
}

Fraction operator*(Fraction& fraction1, Fraction& fraction2) {
    //multiply numerators and denominator together
    int numerator = fraction1.getNumerator() * fraction2.getNumerator();
    int denominator = fraction1.getDenominator() * fraction2.getDenominator();
    return Fraction(numerator, denominator);
}

Fraction operator/(Fraction& fraction1, Fraction& fraction2) {
    //flip the second fraction to multiply
    int numerator = fraction1.getNumerator() * fraction2.getDenominator();
    int denominator = fraction1.getDenominator() * fraction2.getNumerator();
    return Fraction(numerator, denominator);
}

std::ostream& operator<<(std::ostream& out, Fraction& fraction) {
    out << fraction.getNumerator() << "/" << fraction.getDenominator();
    return out;
}

//Input: >> as a friend function of the class fraction
std::istream& operator>>(std::istream& in, Fraction& fraction) {
    int numerator, denominator;
    in >> numerator >> denominator;
    fraction.numerator = numerator;
    fraction.denominator = denominator;
    return in;
}

/**
 * @brief add two fractions
 * 
 * @param fraction1 first fraction
 * @param fraction2 second fraction
 * @return Fraction sum of the two fractions
*/
Fraction add(Fraction& fraction1, Fraction& fraction2) {
    int numerator = fraction1.getNumerator() * fraction2.getDenominator() + fraction2.getNumerator() * fraction1.getDenominator();
    int denominator = fraction1.getDenominator() * fraction2.getDenominator();
    return Fraction(numerator, denominator);
};

/**
 * @brief subtract two fractions
 * 
 * @param fraction1 first fraction
 * @param fraction2 second fraction
 * @return Fraction difference of the two fractions
*/
Fraction subtract(Fraction& fraction1, Fraction& fraction2) {
    int numerator = fraction1.getNumerator() * fraction2.getDenominator() - fraction2.getNumerator() * fraction1.getDenominator();
    int denominator = fraction1.getDenominator() * fraction2.getDenominator();
    return Fraction(numerator, denominator);
};

/**
 * @brief multiply two fractions
 * 
 * @param fraction1 first fraction
 * @param fraction2 second fraction
 * @return Fraction product of the two fractions
*/
Fraction multiply(Fraction& fraction1, Fraction& fraction2) {
    int numerator = fraction1.getNumerator() * fraction2.getNumerator();
    int denominator = fraction1.getDenominator() * fraction2.getDenominator();
    return Fraction(numerator, denominator);
};

/**
 * @brief divide two fractions
 * 
 * @param fraction1 first fraction
 * @param fraction2 second fraction
 * @return Fraction quotient of the two fractions
*/
Fraction divide(Fraction& fraction1, Fraction& fraction2) {
    //flip the second fraction to multiply
    int numerator = fraction1.getNumerator() * fraction2.getDenominator();
    int denominator = fraction1.getDenominator() * fraction2.getNumerator();
    return Fraction(numerator, denominator);
};