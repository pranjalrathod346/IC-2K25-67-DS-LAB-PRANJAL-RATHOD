
#include <iostream>
#include <stack>
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

class BinaryTree {
    Node* root;

public:
    BinaryTree() {
        root = NULL;
    }

    void createTree() {
        // Creating the binary tree
        root = new Node(1);

        root->left = new Node(2);
        root->right = new Node(3);

        root->left->left = new Node(4);
        root->left->right = new Node(5);

        root->right->left = new Node(6);
        root->right->right = new Node(7);
    }

    // Recursive Preorder
    void preorder(Node* node) {
        if (node == NULL)
            return;

        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }

    // Recursive Inorder
    void inorder(Node* node) {
        if (node == NULL)
            return;

        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    // Recursive Postorder
    void postorder(Node* node) {
        if (node == NULL)
            return;

        postorder(node->left);
        postorder(node->right);
        cout << node->data << " ";
    }

    // Iterative Preorder
    void iterativePreorder() {
        if (root == NULL)
            return;

        stack<Node*> s;
        s.push(root);

        while (!s.empty()) {
            Node* current = s.top();
            s.pop();

            cout << current->data << " ";

            if (current->right != NULL)
                s.push(current->right);

            if (current->left != NULL)
                s.push(current->left);
        }
    }

    // Iterative Inorder
    void iterativeInorder() {
        stack<Node*> s;
        Node* current = root;

        while (current != NULL || !s.empty()) {
            while (current != NULL) {
                s.push(current);
                current = current->left;
            }

            current = s.top();
            s.pop();

            cout << current->data << " ";

            current = current->right;
        }
    }

    // Iterative Postorder using two stacks
    void iterativePostorder() {
        if (root == NULL)
            return;

        stack<Node*> s1, s2;
        s1.push(root);

        while (!s1.empty()) {
            Node* current = s1.top();
            s1.pop();

            s2.push(current);

            if (current->left != NULL)
                s1.push(current->left);

            if (current->right != NULL)
                s1.push(current->right);
        }

        while (!s2.empty()) {
            cout << s2.top()->data << " ";
            s2.pop();
        }
    }

    void display() {
        cout << "\nRecursive Preorder: ";
        preorder(root);

        cout << "\nRecursive Inorder: ";
        inorder(root);

        cout << "\nRecursive Postorder: ";
        postorder(root);

        cout << "\n\nIterative Preorder: ";
        iterativePreorder();

        cout << "\nIterative Inorder: ";
        iterativeInorder();

        cout << "\nIterative Postorder: ";
        iterativePostorder();

        cout << endl;
    }
};

int main() {
    BinaryTree tree;

    tree.createTree();
    tree.display();

    return 0;
}
