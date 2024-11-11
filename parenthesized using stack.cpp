//In any language program mostly syntax error occurs due to unbalancing delimiter such as 

//(),{},[]. Write C++ program using stack to check whether given expression is well 

//parenthesized or not

#include <iostream>
#include <stack>
using namespace std;

bool isValidParenthesis(string expression) {
    stack<char> s;
    
    // Loop through each character in the expression
    for (char c : expression) {
        // If it's an opening bracket, push it onto the stack
        if (c == '(' || c == '{' || c == '[') {
            s.push(c);
        }
        // If it's a closing bracket, check if it matches the top of the stack
        else if (c == ')' || c == '}' || c == ']') {
            // If stack is empty or brackets don't match, return false
            if (s.empty()) return false;
            
            char top = s.top();
            s.pop();
            
            // Check if the top of the stack matches the closing bracket
            if ((c == ')' && top != '(') || (c == '}' && top != '{') || (c == ']' && top != '[')) {
                return false;
            }
        }
    }
    
    // If the stack is empty at the end, it means all brackets are matched
    return s.empty();
}

int main() {
    string expression;
    cout << "Enter an expression: ";
    cin >> expression;
    
    if (isValidParenthesis(expression)) {
        cout << "The expression is well-parenthesized." << endl;
    } else {
        cout << "The expression is not well-parenthesized." << endl;
    }

    return 0;
}
