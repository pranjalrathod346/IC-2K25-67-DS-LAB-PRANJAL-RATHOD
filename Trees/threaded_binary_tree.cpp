
#include <iostream>
using namespace std;

class ThreadedBinaryTree {
    struct Node {
        int data;
        Node *left, *right;
        bool leftThread, rightThread;

        Node(int value) {
            data = value;
            left = right = nullptr;
            leftThread = rightThread = true;
        }
    };

    Node* root;

    Node* leftMost(Node* node) {
        if (node == nullptr)
            return nullptr;

        while (!node->leftThread)
            node = node->left;

        return node;
    }

    void destroy(Node* node) {
        if (node == nullptr)
            return;

        if (!node->leftThread)
            destroy(node->left);

        if (!node->rightThread)
            destroy(node->right);

        delete node;
    }

public:
    ThreadedBinaryTree() {
        root = nullptr;
    }

    ~ThreadedBinaryTree() {
        destroy(root);
    }

    void insert(int value) {
        Node* newNode = new Node(value);

        if (root == nullptr) {
            root = newNode;
            return;
        }

        Node* current = root;

        while (true) {
            if (value == current->data) {
                cout << "Duplicate value not allowed!\n";
                delete newNode;
                return;
            }

            if (value < current->data) {
                if (!current->leftThread) {
                    current = current->left;
                } else {
                    newNode->left = current->left;
                    newNode->right = current;

                    current->leftThread = false;
                    current->left = newNode;
                    return;
                }
            } else {
                if (!current->rightThread) {
                    current = current->right;
                } else {
                    newNode->right = current->right;
                    newNode->left = current;

                    current->rightThread = false;
                    current->right = newNode;
                    return;
                }
            }
        }
    }

    void inorderTraversal() {
        if (root == nullptr) {
            cout << "Tree is empty!\n";
            return;
        }

        Node* current = leftMost(root);

        cout << "Inorder Traversal: ";

        while (current != nullptr) {
            cout << current->data << " ";

            if (current->rightThread)
                current = current->right;
            else
                current = leftMost(current->right);
        }

        cout << endl;
    }
};

int main() {
    ThreadedBinaryTree tree;

    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    tree.inorderTraversal();

    return 0;
}
