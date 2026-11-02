
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

    void create(int value) {

        Node* newNode = new Node;

        newNode->data = value;
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

    void display() {

        Node* temp = head;

        cout << "Linked List: ";

        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }

        cout << "NULL";
    }
};

int main() {

    LinkedList l;
    int n, value;

    cout << "Enter number of nodes: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter value: ";
        cin >> value;

        l.create(value);
    }

    l.display();

    return 0;
}
