
#include <iostream>
using namespace std;

class CircularList {

    struct Node {
        int data;
        Node* next;
    };

    Node* head;

public:

    CircularList() {
        head = NULL;
    }

    void insert(int value, int pos) {

        if (pos < 1) {
            cout << "Invalid position\n";
            return;
        }

        Node* newNode = new Node;
        newNode->data = value;

        if (head == NULL) {

            if (pos != 1) {
                cout << "Invalid position\n";
                delete newNode;
                return;
            }

            head = newNode;
            newNode->next = head;
            return;
        }

        if (pos == 1) {

            Node* last = head;

            while (last->next != head) {
                last = last->next;
            }

            newNode->next = head;
            head = newNode;
            last->next = head;

            return;
        }

        Node* temp = head;

        for (int i = 1; i < pos - 1 && temp->next != head; i++) {
            temp = temp->next;
        }

        if (pos > 1 && temp->next == head && pos != 2) {
            // Check position below using node count
            int count = 1;
            Node* p = head;

            while (p->next != head) {
                count++;
                p = p->next;
            }

            if (pos > count + 1) {
                cout << "Invalid position\n";
                delete newNode;
                return;
            }
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

    void deletion(int pos) {

        if (head == NULL || pos < 1) {
            cout << "List empty or invalid position\n";
            return;
        }

        if (pos == 1) {

            Node* temp = head;

            if (head->next == head) {
                head = NULL;
            }
            else {
                Node* last = head;

                while (last->next != head) {
                    last = last->next;
                }

                head = head->next;
                last->next = head;
            }

            delete temp;
            return;
        }

        Node* temp = head;

        for (int i = 1; i < pos - 1 && temp->next != head; i++) {
            temp = temp->next;
        }

        if (temp->next == head) {
            cout << "Invalid position\n";
            return;
        }

        Node* del = temp->next;
        temp->next = del->next;

        delete del;
    }

    void display() {

        if (head == NULL) {
            cout << "List is empty\n";
            return;
        }

        Node* temp = head;

        cout << "Circular List: ";

        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);

        cout << "(Back to Head)\n";
    }
};

int main() {

    CircularList c;

    c.insert(10, 1);
    c.insert(20, 2);
    c.insert(30, 3);
    c.insert(40, 4);

    c.display();

    c.insert(15, 2);
    cout << "After insertion:\n";
    c.display();

    c.deletion(3);
    cout << "After deletion:\n";
    c.display();

    return 0;
}
