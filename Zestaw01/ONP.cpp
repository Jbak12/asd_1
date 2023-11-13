#include <string> 
#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include "ArrayStack.hpp"

bool is_number(const std::string &s) {
  return !s.empty() && std::all_of(s.begin(), s.end(), ::isdigit);
}
int main() {
    std::map <char, int> priority = {
        {'(', 1},
        {'+', 2},
        {'-', 2},
        {'*', 3},
        {'/', 3},
    };

    ArrayStack<std::string,10000> stack;
    std::vector<std::string> output;
    std::vector<std::string> infix_expression;
    std::string exp;

    while (std::cin >> exp) {
        infix_expression.push_back(exp);
        char nextChar = std::cin.get();
        if (nextChar == '\n') {
            break;
        }
    }

    for(std::string literal : infix_expression) {
        if(is_number(literal)) {
            output.push_back(literal);
        } else if(stack.empty() || priority[char(literal[0])] >= priority[stack.top()[0]] || literal == "(") {
            // std::cout<<stack.top()<<std::endl;
            stack.push(literal);
        } else if(literal == ")") {
            std::string to_pop;
            while((to_pop = stack.pop()) != "(" ) {
                output.push_back(to_pop);
            }
        }        
    }

    while(!stack.empty()) {
        output.push_back(stack.pop());
    }

    std::string result;
    for (std::string ch : output) {
        result += ch + " ";
    }

    if (!result.empty()) {
        result.pop_back();
    }
    std::cout<<result<<std::endl;
    return 0; 
}