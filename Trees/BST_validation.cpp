
#include <iostream>
#include <climits>
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

    bool validate(Node* node, long long minValue,
                  long long maxValue) {

        if (node == NULL)
            return true;

        if (node->data <= minValue ||
            node->data >= maxValue) {
            return false;
        }

        return validate(node->left, minValue, node->data) &&
               validate(node->right, node->data, maxValue);
    }

public:
    BST() {
        root = NULL;
    }

    void createValidTree() {
        root = new Node(50);
        root->left = new Node(30);
        root->right = new Node(70);
        root->left->left = new Node(20);
        root->left->right = new Node(40);
    }

    void createInvalidTree() {
        root = new Node(50);
        root->left = new Node(30);
        root->right = new Node(70);
        root->left->left = new Node(20);
        root->left->right = new Node(60);
    }

    void checkBST() {
        if (validate(root, LLONG_MIN, LLONG_MAX)) {
            cout << "The tree is a Valid BST." << endl;
        }
        else {
            cout << "The tree is NOT a Valid BST." << endl;
        }
    }
};

int main() {
    BST tree;
    int choice;

    cout << "1. Create Valid BST";
    cout << "\n2. Create Invalid BST";
    cout << "\nEnter your choice: ";
    cin >> choice;

    if (choice == 1) {
        tree.createValidTree();
    }
    else if (choice == 2) {
        tree.createInvalidTree();
    }
    else {
        cout << "Invalid choice!";
        return 0;
    }

    tree.checkBST();

    return 0;
}
