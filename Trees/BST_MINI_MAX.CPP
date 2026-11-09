
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

class BST {
    Node* root;

    Node* insertNode(Node* node, int value) {
        if (node == NULL)
            return new Node(value);

        if (value < node->data)
            node->left = insertNode(node->left, value);
        else if (value > node->data)
            node->right = insertNode(node->right, value);

        return node;
    }

public:
    BST() {
        root = NULL;
    }

    void insert(int value) {
        root = insertNode(root, value);
    }

    void findMinimum() {
        if (root == NULL) {
            cout << "Tree is empty!" << endl;
            return;
        }

        Node* temp = root;

        while (temp->left != NULL) {
            temp = temp->left;
        }

        cout << "Minimum element: " << temp->data << endl;
    }

    void findMaximum() {
        if (root == NULL) {
            cout << "Tree is empty!" << endl;
            return;
        }

        Node* temp = root;

        while (temp->right != NULL) {
            temp = temp->right;
        }

        cout << "Maximum element: " << temp->data << endl;
    }
};

int main() {
    BST tree;
    int choice, value;

    do {
        cout << "\n1. Insert";
        cout << "\n2. Find Minimum";
        cout << "\n3. Find Maximum";
        cout << "\n4. Exit";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                tree.insert(value);
                cout << "Value inserted successfully." << endl;
                break;

            case 2:
                tree.findMinimum();
                break;

            case 3:
                tree.findMaximum();
                break;

            case 4:
                cout << "Exiting...";
                break;

            default:
                cout << "Invalid choice!";
        }

    } while (choice != 4);

    return 0;
}
