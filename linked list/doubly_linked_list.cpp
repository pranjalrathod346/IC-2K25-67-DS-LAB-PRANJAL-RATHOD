
#include <iostream>
using namespace std;

class DoublyList {

    struct Node {
        int data;
        Node* prev;
        Node* next;
    };

    Node* head;

public:

    DoublyList() {
        head = NULL;
    }

    void insert(int value, int pos) {

        Node* newNode = new Node;
        newNode->data = value;
        newNode->prev = NULL;
        newNode->next = NULL;

        if (pos < 1) {
            cout << "Invalid position\n";
            delete newNode;
            return;
        }

        if (pos == 1) {
            newNode->next = head;

            if (head != NULL) {
                head->prev = newNode;
            }

            head = newNode;
            return;
        }

        Node* temp = head;

        for (int i = 1; i < pos - 1 && temp != NULL; i++) {
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "Invalid position\n";
            delete newNode;
            return;
        }

        newNode->next = temp->next;
        newNode->prev = temp;

        if (temp->next != NULL) {
            temp->next->prev = newNode;
        }

        temp->next = newNode;
    }

    void deletion(int pos) {

        if (head == NULL || pos < 1) {
            cout << "List empty or invalid position\n";
            return;
        }

        Node* temp = head;

        for (int i = 1; i < pos && temp != NULL; i++) {
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "Invalid position\n";
            return;
        }

        if (temp->prev != NULL) {
            temp->prev->next = temp->next;
        }
        else {
            head = temp->next;
        }

        if (temp->next != NULL) {
            temp->next->prev = temp->prev;
        }

        delete temp;
    }

    void reverse() {

        Node* current = head;
        Node* temp = NULL;

        while (current != NULL) {

            temp = current->prev;
            current->prev = current->next;
            current->next = temp;

            current = current->prev;
        }

        if (temp != NULL) {
            head = temp->prev;
        }
    }

    void display() {

        Node* temp = head;

        cout << "Doubly Linked List: ";

        while (temp != NULL) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }

        cout << "NULL\n";
    }
};

int main() {

    DoublyList d;

    d.insert(10, 1);
    d.insert(20, 2);
    d.insert(30, 3);
    d.insert(40, 4);

    d.display();

    d.insert(25, 3);
    cout << "After insertion:\n";
    d.display();

    d.deletion(2);
    cout << "After deletion:\n";
    d.display();

    d.reverse();
    cout << "After reverse:\n";
    d.display();

    return 0;
}
