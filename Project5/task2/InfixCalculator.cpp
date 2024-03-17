#include "LinkedStack.h"
#include "InfixCalculator.h"
#include <iostream>
#include <string>
#include <cctype>

InfixCalculator::InfixCalculator()
{
    infixExpression = "";
}

bool InfixCalculator::verifyInfixExpression(std::string infixExpression)
{
    // check if the infix expression only contains valid characters
    for (char c : infixExpression)
    {
        if (!isdigit(c) && c != '+' && c != '-' && c != '*' && c != '/' && c != '(' && c != ')')
        {
            return false;
        }
    }
    return true;
}

bool InfixCalculator::verifyBalancedBrackets(std::string infixExpression)
{
    int openBrackets = 0;
    for (char c : infixExpression)
    {
        if (c == '(')
        {
            openBrackets++;
        }
        else if (c == ')')
        {
            openBrackets--;
        }
    }
    return openBrackets == 0;
}

std::string InfixCalculator::infixToPostfix(std::string infixExpression)
{
    LinkedStack<char> stack;
    std::string postfixExpression = "";
    for (char c : infixExpression)
    {
        if (isdigit(c))
        {
            postfixExpression += c;
        }
        else if (c == '(')
        {
            stack.push(c);
        }
        else if (c == ')')
        {
            while (!stack.isEmpty() && stack.peek() != '(')
            {
                postfixExpression += stack.peek();
                stack.pop();
            }
            stack.pop();
        }
        else
        {
            while (!stack.isEmpty() && precendance(c) <= precendance(stack.peek()))
            {
                postfixExpression += stack.peek();
                stack.pop();
            }
            stack.push(c);
        }
    }
    while (!stack.isEmpty())
    {
        postfixExpression += stack.peek();
        stack.pop();
    }
    std::cout << "postfixExpression: " << postfixExpression << std::endl;
    return postfixExpression;
}

int InfixCalculator::precendance(char c)
{
    if (c == '+' || c == '-')
    {
        return 1;
    }
    else if (c == '*' || c == '/')
    {
        return 2;
    }
    else
    {
        return -1;
    }
}

float InfixCalculator::evaluatePostfix(std::string postfixExpression)
{
    LinkedStack<float> stack;
    for (char c : postfixExpression)
    {
        if (isdigit(c))
        {
            stack.push(c - '0');
        }
        else
        {
            float operand2 = stack.peek();
            stack.pop();
            float operand1 = stack.peek();
            stack.pop();
            switch (c)
            {
            case '+':
                stack.push(operand1 + operand2);
                break;
            case '-':
                stack.push(operand1 - operand2);
                break;
            case '*':
                stack.push(operand1 * operand2);
                break;
            case '/':
                stack.push(operand1 / operand2);
                break;
            }
        }
    }
    return stack.peek();
}

bool InfixCalculator::setInfixExpression(std::string infixExpression)
{
    if (!verifyInfixExpression(infixExpression))
        return false;
    if (!verifyBalancedBrackets(infixExpression))
        return false;
    this->infixExpression = infixExpression;
    return true;
}

float InfixCalculator::evaluate()
{
    std::string postfixExpression = infixToPostfix(infixExpression);
    return evaluatePostfix(postfixExpression);
}
