
#include <iostream>
#include <stack>
#include <string>
#include <cctype>
#include <cmath>
using namespace std;

class Postfix {

public:

    void evaluate(string exp) {

        stack<int> s;

        for (int i = 0; i < exp.length(); i++) {

            char ch = exp[i];

            if (isdigit(ch)) {

                s.push(ch - '0');
            }

            else {

                if (s.size() < 2) {
                    cout << "Invalid expression";
                    return;
                }

                int b = s.top();
                s.pop();

                int a = s.top();
                s.pop();

                switch (ch) {

                    case '+':
                        s.push(a + b);
                        break;

                    case '-':
                        s.push(a - b);
                        break;

                    case '*':
                        s.push(a * b);
                        break;

                    case '/':
                        if (b == 0) {
                            cout << "Division by zero";
                            return;
                        }
                        s.push(a / b);
                        break;

                    case '^':
                        s.push(pow(a, b));
                        break;

                    default:
                        cout << "Invalid operator";
                        return;
                }
            }
        }

        if (s.size() == 1)
            cout << "Result: " << s.top();
        else
            cout << "Invalid expression";
    }
};

int main() {

    Postfix p;
    string exp;

    cout << "Enter postfix expression: ";
    cin >> exp;

    p.evaluate(exp);

    return 0;
}
