
#include <iostream>
using namespace std;

class Stack {

    struct Node {
        int data;
        Node* next;
    };

    Node* top;

public:

    Stack() {
        top = NULL;
    }

    void push(int value) {

        Node* newNode = new Node;

        newNode->data = value;
        newNode->next = top;

        top = newNode;

        cout << value << " inserted\n";
    }

    void pop() {

        if (top == NULL) {
            cout << "Stack Underflow\n";
            return;
        }

        Node* temp = top;

        cout << "Deleted element: " << temp->data << endl;

        top = top->next;

        delete temp;
    }

    void peek() {

        if (top == NULL) {
            cout << "Stack is empty\n";
        }
        else {
            cout << "Top element: " << top->data << endl;
        }
    }

    void display() {

        if (top == NULL) {
            cout << "Stack is empty\n";
            return;
        }

        Node* temp = top;

        cout << "Stack elements: ";

        while (temp != NULL) {

            cout << temp->data << " ";

            temp = temp->next;
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
