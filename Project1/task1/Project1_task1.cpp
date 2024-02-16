/*
- The purpose of task 1 is to make a fraction class that you can modify and display.
- John Klein
- xx5546ys
- 1/18/24
- Dr. Jie Hu Meichsner
*/

#include <iostream>

#include "Fraction.h"

int main() {
    
    Fraction fraction = Fraction(1, 2);
    fraction.showFraction();
    std::cout << "changing fraction" << std::endl;
    fraction.setNumerator(3);
    fraction.setDenominator(4);
    fraction.showFraction();
    std::cout << fraction.getNumerator() << std::endl;
    std::cout << fraction.getDenominator() << std::endl;
    
    return 0;
}