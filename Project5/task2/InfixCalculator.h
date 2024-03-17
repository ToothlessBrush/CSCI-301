/*
-Implement a stack based infix calculator that can handle the following operators: +, -, *, and /.
-xx5546ys, John Klein
-3/16/2024
-Dr. Jie Hu Meichsner
*/

#ifndef INFIXCALCULATOR_H
#define INFIXCALCULATOR_H

#include "LinkedStack.h"
#include <iostream>
#include <string>
#include <cctype>

class InfixCalculator
{
private:
    /**
     * @brief the infixExpression to evaluate
     */
    std::string infixExpression;

    /**
     * @brief verify that the infix expression is valid
     *
     * @param infixExpression the infix expression to verify
     * @return true if the infix expression is valid
     */
    bool verifyInfixExpression(std::string infixExpression);

    /**
     * @brief verify that the infix expression has balanced brackets
     *
     * @param infixExpression the infix expression to verify
     * @return true if the infix expression has balanced brackets
     */
    bool verifyBalancedBrackets(std::string infixExpression);

    /**
     * @brief convert the infix expression to postfix
     *
     * @param infixExpression the infix expression to convert
     * @return the postfix expression
     */
    std::string infixToPostfix(std::string infixExpression);

    /**
     * @brief get the precendance of an operator
     *
     * @param c the operator to get the precendance of
     * @return the precendance of the operator
     */
    int precendance(char c);

    /**
     * @brief evaluate the postfix expression
     *
     * @param postfixExpression the postfix expression to evaluate
     * @return the result of the postfix expression
     */
    float evaluatePostfix(std::string postfixExpression);

public:
    /**
     * @brief defualt Constructer for InfixCalculator
     */
    InfixCalculator();

    /**
     * @brief Construct a new Infix Calculator object
     *
     * @param infixExpression the infix expression to evaluate
     * @return true if the infix expression was set
     */
    bool setInfixExpression(std::string infixExpression);

    /**
     * @brief evaluate the postfix expression
     *
     * @return the result of the postfix expression
     */
    float evaluate();
};

#include "InfixCalculator.cpp"

#endif