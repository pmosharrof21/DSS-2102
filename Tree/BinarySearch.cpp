#include <iostream>
using namespace std;

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int data) {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

class BinarySearchTree {
public:
    TreeNode* root;

    BinarySearchTree() {
        root = nullptr;
    }

    void insert(int data) {
        root = insertRec(root, data);
    }

    void inorder() {
        inorderRec(root);
        cout << endl;
    }

    bool search(int data) {
        return searchRec(root, data);
    }

private:
    TreeNode* insertRec(TreeNode* node, int data) {
        if (node == nullptr) {
            return new TreeNode(data);
        }

        if (data < node->data) {
            node->left = insertRec(node->left, data);
        } else if (data > node->data) {
            node->right = insertRec(node->right, data);
        }

        return node;
    }

    void inorderRec(TreeNode* node) {
        if (node != nullptr) {
            inorderRec(node->left);
            cout << node->data << " ";
            inorderRec(node->right);
        }
    }

    bool searchRec(TreeNode* node, int data) {
        if (node == nullptr) {
            return false;
        }

        if (node->data == data) {
            return true;
        }

        if (data < node->data) {
            return searchRec(node->left, data);
        } else {
            return searchRec(node->right, data);
        }
    }
};

int main() {
    BinarySearchTree bst;
    bst.insert(58);
    bst.insert(35);
    bst.insert(25);
    bst.insert(42);
    bst.insert(77);
    bst.insert(63);
    bst.insert(87);
    cout << "Inorder traversal: ";
    bst.inorder();
    cout << "Search for 40: " << (bst.search(40) ? "Found" : "Not Found") << endl;
    cout << "Search for 25: " << (bst.search(25) ? "Found" : "Not Found") << endl;
    return 0;
}

