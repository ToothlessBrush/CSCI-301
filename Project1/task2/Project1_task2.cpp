/*
- The purpose of task 2 is to add member and non-member functions that can be used to add, subtract, multiply, and divide fractions.
- John Klein
- xx5546ys
- 1/18/24
- Dr. Jie Hu Meichsner
*/


#include <iostream>

#include "newFraction1.h"

int main() {

    int tempNumerator, tempDenominator;

    //get first fraction
    std::cout << "enter the first fraction: numerator denominator" << std::endl;
    std::cin >> tempNumerator >> tempDenominator;

    Fraction fraction1 = Fraction(tempNumerator, tempDenominator);

    //get second fraction
    std::cout << "enter the second fraction: numerator denominator" << std::endl;
    std::cin >> tempNumerator >> tempDenominator;

    Fraction fraction2 = Fraction(tempNumerator, tempDenominator);

    //display fractions
    std::cout << "the two fractions are:" << std::endl;
    std::cout << "f1 = ";
    fraction1.showFraction();
    std::cout << "f2 = ";
    fraction2.showFraction();

    //display sum, difference, product, and quotient
    std::cout << "the arithmetic operations are:" << std::endl;
    std::cout << "f1 + f2 = ";
    add(fraction1, fraction2).showFraction();
    std::cout << "f1 - f2 = ";
    subtract(fraction1, fraction2).showFraction();
    std::cout << "f1 * f2 = ";
    multiply(fraction1, fraction2).showFraction();
    std::cout << "f1 / f2 = ";
    divide(fraction1, fraction2).showFraction();

}