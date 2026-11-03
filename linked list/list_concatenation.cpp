
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

    void insert(int value) {

        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            return;
        }

        Node* temp = head;

        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    void concatenate(LinkedList& second) {

        if (head == NULL) {
            head = second.head;
        }
        else {
            Node* temp = head;

            while (temp->next != NULL) {
                temp = temp->next;
            }

            temp->next = second.head;
        }

        second.head = NULL;
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

    LinkedList l1, l2;

    l1.insert(10);
    l1.insert(20);
    l1.insert(30);

    l2.insert(40);
    l2.insert(50);

    cout << "First List: ";
    l1.display();

    cout << "Second List: ";
    l2.display();

    l1.concatenate(l2);

    cout << "After Concatenation: ";
    l1.display();

    return 0;
}
