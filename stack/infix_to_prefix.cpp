
#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;

class PrefixConversion {

    int precedence(char op) {

        if (op == '^')
            return 3;

        if (op == '*' || op == '/' || op == '%')
            return 2;

        if (op == '+' || op == '-')
            return 1;

        return 0;
    }

    string toPostfix(string exp) {

        stack<char> s;
        string result = "";

        for (int i = 0; i < exp.length(); i++) {

            char ch = exp[i];

            if (isalnum(ch)) {
                result += ch;
            }

            else if (ch == '(') {
                s.push(ch);
            }

            else if (ch == ')') {

                while (!s.empty() && s.top() != '(') {
                    result += s.top();
                    s.pop();
                }

                if (!s.empty())
                    s.pop();
            }

            else {

                while (!s.empty() && s.top() != '(' &&
                       (precedence(s.top()) > precedence(ch) ||
                       (precedence(s.top()) == precedence(ch) &&
                        ch == '^'))) {

                    result += s.top();
                    s.pop();
                }

                s.push(ch);
            }
        }

        while (!s.empty()) {
            result += s.top();
            s.pop();
        }

        return result;
    }

public:

    void convert(string infix) {

        reverse(infix.begin(), infix.end());

        for (int i = 0; i < infix.length(); i++) {

            if (infix[i] == '(')
                infix[i] = ')';

            else if (infix[i] == ')')
                infix[i] = '(';
        }

        string postfix = toPostfix(infix);

        reverse(postfix.begin(), postfix.end());

        cout << "Prefix Expression: " << postfix;
    }
};

int main() {

    PrefixConversion p;
    string infix;

    cout << "Enter infix expression: ";
    cin >> infix;

    p.convert(infix);

    return 0;
}
