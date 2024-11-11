
#include "RPN.hpp"
#include <sstream>

RPN::RPN() {}

RPN::RPN(const std::string &expression) : _expression(expression) {
    if (!isValidExpression(_expression))
        throw std::invalid_argument("Invalid expression");
}

RPN::RPN(const RPN &other) {
    *this = other;
}

RPN &RPN::operator=(const RPN &other) {
    if (this != &other) {
        _stack = other._stack;
        _expression = other._expression;
    }
    return *this;
}

RPN::~RPN() {}

bool RPN::isValidExpression(const std::string &expression) {
    if (expression.empty())
        return false;
    for (size_t i = 0; i < expression.length(); ++i) {
        if (expression[i] == ' ')
            continue;
        if (expression[i] == '+' || expression[i] == '-' || \
            expression[i] == '*' || expression[i] == '/')
            continue;
        if (isdigit(expression[i]))
            continue;
        return false;
    }
    return true;
}

int RPN::calculate(int a, int b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': 
            if (b == 0)
                throw std::invalid_argument("Division by zero");
            return a / b;
    }
    return 0;
}

int RPN::operate() {
    std::istringstream iss(_expression);
    std::string token;
    while (iss >> token) {
        if (isdigit(token[0])) {
            _stack.push_back(std::stoi(token));
        }
        else {
            if (_stack.size() < 2)
                throw std::invalid_argument("Invalid expression");
            int b = _stack.back();
            _stack.pop_back();
            int a = _stack.back();
            _stack.pop_back();
            _stack.push_back(calculate(a, b, token[0]));
        }
    }
    if (_stack.size() != 1)
        throw std::invalid_argument("Invalid expression");
    return _stack.front();
}