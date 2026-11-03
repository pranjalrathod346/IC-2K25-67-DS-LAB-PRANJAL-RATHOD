
#include <iostream>
using namespace std;

class LinkedList {

    struct Node {
        int data;
        Node* next;
    };

    Node* head;

public:

    LinkedList() {
        head = NULL;
    }

    void insert(int value, int pos) {

        Node* newNode = new Node;
        newNode->data = value;

        if (pos == 1) {
            newNode->next = head;
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
        temp->next = newNode;
    }

    void deletion(int pos) {

        if (head == NULL || pos < 1) {
            cout << "List is empty or invalid position\n";
            return;
        }

        Node* temp = head;

        if (pos == 1) {
            head = head->next;
            delete temp;
            return;
        }

        for (int i = 1; i < pos - 1 && temp != NULL; i++) {
            temp = temp->next;
        }

        if (temp == NULL || temp->next == NULL) {
            cout << "Invalid position\n";
            return;
        }

        Node* del = temp->next;
        temp->next = del->next;

        delete del;
    }

    void search(int key) {

        Node* temp = head;
        int pos = 1;

        while (temp != NULL) {

            if (temp->data == key) {
                cout << "Element found at position " << pos;
                return;
            }

            temp = temp->next;
            pos++;
        }

        cout << "Element not found";
    }

    void reverse() {

        Node* prev = NULL;
        Node* current = head;
        Node* nextNode;

        while (current != NULL) {

            nextNode = current->next;
            current->next = prev;

            prev = current;
            current = nextNode;
        }

        head = prev;
    }

    void display() {

        Node* temp = head;

        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }

        cout << "NULL\n";
    }

};

int main() {

    LinkedList l;

    l.insert(10, 1);
    l.insert(20, 2);
    l.insert(30, 3);
    l.insert(40, 4);

    cout << "Original List: ";
    l.display();

    l.insert(25, 3);

    cout << "After Insertion: ";
    l.display();

    l.deletion(2);

    cout << "After Deletion: ";
    l.display();

    cout << "Searching 30: ";
    l.search(30);

    l.reverse();

    cout << "\nReversed List: ";
    l.display();

    return 0;
}
