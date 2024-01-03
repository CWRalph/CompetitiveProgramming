#include <iostream>

struct Node {
    int value;
    Node* left;
    Node* right;

    Node(int val) : value(val), left(nullptr), right(nullptr) {}
};

// Function to insert a new node into the BST
Node* insertNode(Node* root, int value) {
    if (root == nullptr) {
        return new Node(value);
    }

    if (value < root->value) {
        root->left = insertNode(root->left, value);
    } else {
        root->right = insertNode(root->right, value);
    }

    return root;
}

// Function for in-order traversal
void inOrderTraversal(Node* node) {
    if (node) {
        inOrderTraversal(node->left);
        std::cout << node->value << " ";
        inOrderTraversal(node->right);
    }
}

// Function to find a node in the BST
bool findNode(Node* root, int value) {
    if (root == nullptr) {
        return false;
    }

    if (value == root->value) {
        return true;
    } else if (value < root->value) {
        return findNode(root->left, value);
    } else {
        return findNode(root->right, value);
    }
}

int main() {
    Node* root = nullptr;

    // Insert nodes into the BST
    root = insertNode(root, 50);
    root = insertNode(root, 30);
    root = insertNode(root, 70);
    root = insertNode(root, 20);
    root = insertNode(root, 40);
    root = insertNode(root, 60);
    root = insertNode(root, 80);

    // In-order traversal of the BST
    std::cout << "In-Order Traversal: ";
    inOrderTraversal(root);
    std::cout << std::endl;

    // Find a node (e.g., 30)
    int value_to_find = 30;
    if (findNode(root, value_to_find)) {
        std::cout << "Node with value " << value_to_find << " found in the BST." << std::endl;
    } else {
        std::cout << "Node with value " << value_to_find << " not found in the BST." << std::endl;
    }

    return 0;
}


