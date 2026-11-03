
#include <iostream>
using namespace std;

class Polynomial {

    struct Node {
        int coeff;
        int exp;
        Node* next;
    };

    Node* head;

public:

    Polynomial() {
        head = NULL;
    }

    void insert(int c, int e) {

        Node* newNode = new Node;

        newNode->coeff = c;
        newNode->exp = e;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
        }
        else {
            Node* temp = head;

            while (temp->next != NULL) {
                temp = temp->next;
            }

            temp->next = newNode;
        }
    }

    static Polynomial add(Polynomial& p1, Polynomial& p2) {

        Polynomial result;

        Node* a = p1.head;
        Node* b = p2.head;

        while (a != NULL && b != NULL) {

            if (a->exp == b->exp) {

                int sum = a->coeff + b->coeff;

                if (sum != 0) {
                    result.insert(sum, a->exp);
                }

                a = a->next;
                b = b->next;
            }

            else if (a->exp > b->exp) {

                result.insert(a->coeff, a->exp);
                a = a->next;
            }

            else {

                result.insert(b->coeff, b->exp);
                b = b->next;
            }
        }

        while (a != NULL) {
            result.insert(a->coeff, a->exp);
            a = a->next;
        }

        while (b != NULL) {
            result.insert(b->coeff, b->exp);
            b = b->next;
        }

        return result;
    }

    void display() {

        Node* temp = head;

        while (temp != NULL) {

            cout << temp->coeff << "x^" << temp->exp;

            if (temp->next != NULL) {
                cout << " + ";
            }

            temp = temp->next;
        }

        cout << endl;
    }
};

int main() {

    Polynomial p1, p2, result;

    p1.insert(5, 2);
    p1.insert(3, 1);
    p1.insert(2, 0);

    p2.insert(4, 2);
    p2.insert(2, 1);
    p2.insert(1, 0);

    cout << "First Polynomial: ";
    p1.display();

    cout << "Second Polynomial: ";
    p2.display();

    result = Polynomial::add(p1, p2);

    cout << "Addition Result: ";
    result.display();

    return 0;
}
