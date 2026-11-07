
#include <iostream>
using namespace std;

class Stack {

    int arr[100];
    int top;

public:

    Stack() {
        top = -1;
    }

    void push(int value) {

        if (top == 99) {
            cout << "Stack Overflow\n";
            return;
        }

        top++;
        arr[top] = value;

        cout << value << " inserted\n";
    }

    void pop() {

        if (top == -1) {
            cout << "Stack Underflow\n";
            return;
        }

        cout << "Deleted element: " << arr[top] << endl;
        top--;
    }

    void peek() {

        if (top == -1) {
            cout << "Stack is empty\n";
            return;
        }

        cout << "Top element: " << arr[top] << endl;
    }

    void display() {

        if (top == -1) {
            cout << "Stack is empty\n";
            return;
        }

        cout << "Stack elements: ";

        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }

        cout << endl;
    }
};

int main() {

    Stack s;
    int choice, value;

    do {

        cout << "\n1. Push";
        cout << "\n2. Pop";
        cout << "\n3. Peek";
        cout << "\n4. Display";
        cout << "\n5. Exit";

        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {

            case 1:
                cout << "Enter value: ";
                cin >> value;
                s.push(value);
                break;

            case 2:
                s.pop();
                break;

            case 3:
                s.peek();
                break;

            case 4:
                s.display();
                break;

            case 5:
                cout << "Exiting...";
                break;

            default:
                cout << "Invalid choice";
        }

    } while (choice != 5);

    return 0;
}
