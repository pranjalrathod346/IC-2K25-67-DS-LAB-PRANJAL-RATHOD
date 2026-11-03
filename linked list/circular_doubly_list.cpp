
#include <iostream>
using namespace std;

class CircularDoublyList {

    struct Node {
        int data;
        Node* prev;
        Node* next;
    };

    Node* head;

public:

    CircularDoublyList() {
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
            newNode->prev = head;
            return;
        }

        if (pos == 1) {

            Node* last = head->prev;

            newNode->next = head;
            newNode->prev = last;

            last->next = newNode;
            head->prev = newNode;

            head = newNode;
            return;
        }

        Node* temp = head;

        for (int i = 1; i < pos - 1 && temp->next != head; i++) {
            temp = temp->next;
        }

        if (temp->next == head && pos != 2) {
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
        newNode->prev = temp;

        temp->next->prev = newNode;
        temp->next = newNode;
    }

    void deletion(int pos) {

        if (head == NULL || pos < 1) {
            cout << "List empty or invalid position\n";
            return;
        }

        Node* temp = head;

        for (int i = 1; i < pos && temp->next != head; i++) {
            temp = temp->next;
        }

        if (temp->next == head && pos > 1) {
            int count = 1;
            Node* p = head;

            while (p->next != head) {
                count++;
                p = p->next;
            }

            if (pos > count) {
                cout << "Invalid position\n";
                return;
            }
        }

        if (temp->next == temp) {
            head = NULL;
        }
        else {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;

            if (temp == head) {
                head = temp->next;
            }
        }

        delete temp;
    }

    void display() {

        if (head == NULL) {
            cout << "List is empty\n";
            return;
        }

        Node* temp = head;

        cout << "Circular Doubly List: ";

        do {
            cout << temp->data << " <-> ";
            temp = temp->next;
        } while (temp != head);

        cout << "(Back to Head)\n";
    }
};

int main() {

    CircularDoublyList c;

    c.insert(10, 1);
    c.insert(20, 2);
    c.insert(30, 3);

    c.display();

    c.insert(15, 2);
    cout << "After insertion:\n";
    c.display();

    c.deletion(3);
    cout << "After deletion:\n";
    c.display();

    return 0;
}
