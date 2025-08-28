#include <iostream>
#include <stack>
#include <cstring>
#include <cctype>
using namespace std;

int evaluatePostfix(const char* expr) {
    stack<int> s;
    for (int i = 0; expr[i] != '\0'; i++) {
        char c = expr[i];
        if (c == ' ') continue;
        if (isdigit(c)) {
            s.push(c - '0');
        } else if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^') {
            if (s.size() < 2) {
                cout << "Invalid expression." << endl;
                return 0;
            }
            int b = s.top(); s.pop();
            int a = s.top(); s.pop();
            int res;
            switch (c) {
                case '+': res = a + b; break;
                case '-': res = a - b; break;
                case '*': res = a * b; break;
                case '/': res = a / b; break;
                case '^': res = 1;
                    for (int j = 0; j < b; j++) res *= a;
                    break;
            }
            s.push(res);
        }
    }
    if (s.size() == 1)
        return s.top();
    cout << "Invalid expression." << endl;
    return 0;
}

int main() {
    char expr[100];
    cout << "Enter postfix expression (single-digit operands, space separated): ";
    cin.getline(expr, 100);
    int result = evaluatePostfix(expr);
    cout << "Result: " << result << endl;
    return 0;
}
