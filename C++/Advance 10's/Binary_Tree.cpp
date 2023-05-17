#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
};

class BinaryTree {
private:
    Node* root;

    Node* createNode(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->left = nullptr;
        newNode->right = nullptr;
        return newNode;
    }

    Node* insertNode(Node* currentNode, int value) {
        if (currentNode == nullptr) {
            return createNode(value);
        }
        if (value < currentNode->data) {
            currentNode->left = insertNode(currentNode->left, value);
        } else if (value > currentNode->data) {
            currentNode->right = insertNode(currentNode->right, value);
        }
        return currentNode;
    }

    Node* searchNode(Node* currentNode, int value) {
        if (currentNode == nullptr || currentNode->data == value) {
            return currentNode;
        }
        if (value < currentNode->data) {
            return searchNode(currentNode->left, value);
        }
        return searchNode(currentNode->right, value);
    }

public:
    BinaryTree() {
        root = nullptr;
    }

    void insert(int value) {
        root = insertNode(root, value);
    }

    bool search(int value) {
        Node* node = searchNode(root, value);
        return node != nullptr;
    }
};

int main() {
    BinaryTree tree;

    int numElements;
    cout << "Enter the number of elements to insert: ";
    cin >> numElements;

    int value;
    for (int i = 0; i < numElements; i++) {
        cout << "Enter element " << (i + 1) << ": ";
        cin >> value;
        tree.insert(value);
    }

    int searchValue;
    cout << "Enter an element to search for: ";
    cin >> searchValue;

    if (tree.search(searchValue)) {
        cout << "Element found in the tree." << endl;
    } else {
        cout << "Element not found in the tree." << endl;
    }

    return 0;
}
