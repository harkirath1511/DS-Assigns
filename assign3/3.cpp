#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

bool isBalanced(const char* expr) {
    stack<char> s;
    for (int i = 0; expr[i] != '\0'; i++) {
        char c = expr[i];
        if (c == '(' || c == '[' || c == '{') {
            s.push(c);
        } else if (c == ')' || c == ']' || c == '}') {
            if (s.empty()) return false;
            char top = s.top();
            s.pop();
            if ((c == ')' && top != '(') ||
                (c == ']' && top != '[') ||
                (c == '}' && top != '{')) {
                return false;
            }
        }
    }
    return s.empty();
}

int main() {
    char expr[100];
    cout << "Enter expression: ";
    cin.getline(expr, 100);
    if (isBalanced(expr))
        cout << "Balanced parentheses." << endl;
    else
        cout << "Unbalanced parentheses." << endl;
    return 0;
}
