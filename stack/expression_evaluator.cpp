
#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

class ExpressionEvaluator {

    int precedence(char op) {

        if (op == '*' || op == '/')
            return 2;

        if (op == '+' || op == '-')
            return 1;

        return 0;
    }

    void calculate(stack<int>& values,
                    stack<char>& operators) {

        int b = values.top();
        values.pop();

        int a = values.top();
        values.pop();

        char op = operators.top();
        operators.pop();

        switch (op) {

            case '+':
                values.push(a + b);
                break;

            case '-':
                values.push(a - b);
                break;

            case '*':
                values.push(a * b);
                break;

            case '/':
                if (b == 0) {
                    throw string("Division by zero");
                }
                values.push(a / b);
                break;
        }
    }

public:

    void evaluate(string exp) {

        stack<int> values;
        stack<char> operators;

        try {

            for (int i = 0; i < exp.length(); i++) {

                char ch = exp[i];

                if (isspace(ch)) {
                    continue;
                }

                // Read number
                if (isdigit(ch)) {

                    int num = 0;

                    while (i < exp.length() &&
                           isdigit(exp[i])) {

                        num = num * 10 + (exp[i] - '0');
                        i++;
                    }

                    values.push(num);
                    i--;
                }

                // Opening bracket
                else if (ch == '(') {
                    operators.push(ch);
                }

                // Closing bracket
                else if (ch == ')') {

                    while (!operators.empty() &&
                           operators.top() != '(') {

                        if (values.size() < 2)
                            throw string("Invalid expression");

                        calculate(values, operators);
                    }

                    if (operators.empty())
                        throw string("Invalid parentheses");

                    operators.pop();
                }

                // Operators
                else if (ch == '+' || ch == '-' ||
                         ch == '*' || ch == '/') {

                    while (!operators.empty() &&
                           operators.top() != '(' &&
                           precedence(operators.top()) >= precedence(ch)) {

                        if (values.size() < 2)
                            throw string("Invalid expression");

                        calculate(values, operators);
                    }

                    operators.push(ch);
                }

                else {
                    throw string("Invalid character");
                }
            }

            while (!operators.empty()) {

                if (operators.top() == '(')
                    throw string("Invalid parentheses");

                if (values.size() < 2)
                    throw string("Invalid expression");

                calculate(values, operators);
            }

            if (values.size() != 1)
                throw string("Invalid expression");

            cout << "Result: " << values.top();
        }

        catch (string error) {
            cout << "Error: " << error;
        }
    }
};

int main() {

    ExpressionEvaluator e;
    string exp;

    cout << "Enter expression: ";
    getline(cin, exp);

    e.evaluate(exp);

    return 0;
}
