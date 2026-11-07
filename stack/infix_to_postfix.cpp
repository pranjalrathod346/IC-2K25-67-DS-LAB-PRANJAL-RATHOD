
#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

class Conversion {

    int precedence(char op) {

        if (op == '^')
            return 3;

        if (op == '*' || op == '/' || op == '%')
            return 2;

        if (op == '+' || op == '-')
            return 1;

        return 0;
    }

public:

    void convert(string infix) {

        stack<char> s;
        string postfix = "";

        for (int i = 0; i < infix.length(); i++) {

            char ch = infix[i];

            if (isalnum(ch)) {
                postfix += ch;
            }

            else if (ch == '(') {
                s.push(ch);
            }

            else if (ch == ')') {

                while (!s.empty() && s.top() != '(') {
                    postfix += s.top();
                    s.pop();
                }

                if (!s.empty())
                    s.pop();
            }

            else {

                while (!s.empty() && s.top() != '(' &&
                       (precedence(s.top()) > precedence(ch) ||
                       (precedence(s.top()) == precedence(ch) &&
                        ch != '^'))) {

                    postfix += s.top();
                    s.pop();
                }

                s.push(ch);
            }
        }

        while (!s.empty()) {
            postfix += s.top();
            s.pop();
        }

        cout << "Postfix Expression: " << postfix;
    }
};

int main() {

    Conversion c;
    string infix;

    cout << "Enter infix expression: ";
    cin >> infix;

    c.convert(infix);

    return 0;
}
