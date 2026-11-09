
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
        if (node == NULL) {
            return new Node(value);
        }

        if (value < node->data) {
            node->left = insertNode(node->left, value);
        }
        else if (value > node->data) {
            node->right = insertNode(node->right, value);
        }
        else {
            cout << "Duplicate value not allowed!" << endl;
        }

        return node;
    }

    bool searchNode(Node* node, int value) {
        if (node == NULL) {
            return false;
        }

        if (node->data == value) {
            return true;
        }

        if (value < node->data) {
            return searchNode(node->left, value);
        }

        return searchNode(node->right, value);
    }

    void inorder(Node* node) {
        if (node == NULL) {
            return;
        }

        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

public:
    BST() {
        root = NULL;
    }

    void insert(int value) {
        root = insertNode(root, value);
        cout << "Insertion operation completed." << endl;
    }

    void search(int value) {
        if (searchNode(root, value)) {
            cout << value << " found in BST." << endl;
        }
        else {
            cout << value << " not found in BST." << endl;
        }
    }

    void display() {
        cout << "BST (Inorder): ";
        inorder(root);
        cout << endl;
    }
};

int main() {
    BST tree;
    int choice, value;

    do {
        cout << "\n1. Insert";
        cout << "\n2. Search";
        cout << "\n3. Display";
        cout << "\n4. Exit";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                tree.insert(value);
                break;

            case 2:
                cout << "Enter value to search: ";
                cin >> value;
                tree.search(value);
                break;

            case 3:
                tree.display();
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
