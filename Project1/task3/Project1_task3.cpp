/*
- The purpose of task 3 is to add member and non-member overload functions to input, output, add, subtract, multiply, and divide fractions.
- John Klein
- xx5546ys
- 1/18/24
- Dr. Jie Hu Meichsner
*/

#include <iostream>

#include "newFraction2.h"

int main() {

    //get first fraction
    Fraction fraction1 = Fraction();
    std::cout << "enter the first fraction: numerator denominator" << std::endl;
    std::cin >> fraction1;

    //get second fraction
    Fraction fraction2 = Fraction();
    std::cout << "enter the second fraction: numerator denominator" << std::endl;
    std::cin >> fraction2;

    //display fractions
    std::cout << "the two fractions are:" << std::endl;
    std::cout << "f1 = " << fraction1 << std::endl;
    std::cout << "f2 = " << fraction2 << std::endl;

    //display sum, difference, product, and quotient
    std::cout << "the arithmetic operations are:" << std::endl;
    Fraction sum = fraction1 + fraction2;
    std::cout << "f1 + f2 = " << sum << std::endl;
    Fraction difference = fraction1 - fraction2;
    std::cout << "f1 - f2 = " << difference << std::endl;
    Fraction product = fraction1 * fraction2;
    std::cout << "f1 * f2 = " << product << std::endl;
    Fraction quotient = fraction1 / fraction2;
    std::cout << "f1 / f2 = " << quotient << std::endl;

}