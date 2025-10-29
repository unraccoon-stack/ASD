#pragma once
#include <iostream>
#include "checkbreckets.h"


bool check_brackets(const std::string& val) {
    int open_count = 0;
    for (char c : val) {
        if (c == '(' || c == '[' || c == '{') {
            open_count++;
        }
    }
    Stack<char> stack(open_count + 1);
    for (char c : val) {
        if (c == '(' || c == '[' || c == '{') {
            stack.push(c);
        }
        else if (c == ')' || c == ']' || c == '}') {
            if (stack.is_empty()) {
                return false;
            }
            char top = stack.top();
            if ((c == ')' && top == '(') || (c == ']' && top == '[') || (c == '}' && top == '{')) {
                stack.pop();
            }
            else {
                return false;
            }
        }
    }

    return stack.is_empty();
}