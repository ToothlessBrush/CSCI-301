#include "InfixCalculator.h"
#include <iostream>
#include <string>

/**
 * @brief use the calculator to evaluate an infix expression
 *
 * @param infixExpression the infix expression to evaluate
 * @param calculator the calculator to use

*/
void useCalculator(std::string infixExpression, InfixCalculator &calculator)
{
    if (!calculator.setInfixExpression(infixExpression))
    {
        std::cout << "Invalid infix expression" << std::endl;
        return;
    }

    std::cout << "the result is: " << calculator.evaluate() << std::endl;
    return;
}

int main()
{
    bool shouldContinue = true;

    std::string infixExpression;
    std::cout << "welcome to the Infix Calculator!" << std::endl;

    do
    {
        // get inputs
        std::string infixExpression;
        std::cout << "Enter an infix expression: ";
        std::cin >> infixExpression;
        InfixCalculator calculator;

        // use the calculator to evaluate the infix expression
        useCalculator(infixExpression, calculator);

        // ask for another expression
        std::cout << "Do you want to enter another expression? (y/n): ";
        char response;
        std::cin >> response;
        shouldContinue = response == 'y';
    } while (shouldContinue);

    return 0;
}