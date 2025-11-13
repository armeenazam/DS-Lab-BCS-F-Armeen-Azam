#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int prec(char c) {
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    return -1;
}

string infixToPrefix(string infix) {
    reverse(infix.begin(), infix.end());
    for (char &c : infix)
        if (c == '(') c = ')';
        else if (c == ')') c = '(';

    stack<char> s;
    string prefix = "";
    for (char c : infix) {
        if (isalnum(c)) prefix += c;
        else if (c == '(') s.push(c);
        else if (c == ')') {
            while (!s.empty() && s.top() != '(') {
                prefix += s.top(); s.pop();
            }
            s.pop();
        } else {
            while (!s.empty() && prec(s.top()) >= prec(c)) {
                prefix += s.top(); s.pop();
            }
            s.push(c);
        }
    }
    while (!s.empty()) { prefix += s.top(); s.pop(); }
    reverse(prefix.begin(), prefix.end());
    return prefix;
}

int evalPrefix(string exp) {
    stack<int> s;
    reverse(exp.begin(), exp.end());
    for (char c : exp) {
        if (isdigit(c)) s.push(c - '0');
        else {
            int a = s.top(); s.pop();
            int b = s.top(); s.pop();
            switch (c) {
                case '+': s.push(a + b); break;
                case '-': s.push(a - b); break;
                case '*': s.push(a * b); break;
                case '/': s.push(a / b); break;
            }
        }
    }
    return s.top();
}

int main() {
    string infix = "(3+2)*4";
    string prefix = infixToPrefix(infix);
    cout << "Prefix: " << prefix << endl;
    cout << "Result: " << evalPrefix(prefix) << endl;
}
