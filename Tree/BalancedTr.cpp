#include <iostream>
using namespace std;
class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;
    int height;
    TreeNode(int data) {
        this->data = data;
        this->left = this->right = nullptr;
        this->height = 1;
    }
};
class AVLTree {
public:
    TreeNode* root;

    AVLTree() {
        root = nullptr;
    }
    int height(TreeNode* node) {
        if (node == nullptr)
            return 0;
        return node->height;
    }
    int max(int a, int b) {
        return (a > b) ? a : b;
    }
    TreeNode* rightRotate(TreeNode* y) {
        TreeNode* x = y->left;
        TreeNode* T2 = x->right;
        x->right = y;
        y->left = T2;
        y->height = max(height(y->left), height(y->right)) + 1;
        x->height = max(height(x->left), height(x->right)) + 1;
        return x;
    }
    TreeNode* leftRotate(TreeNode* x) {
        TreeNode* y = x->right;
        TreeNode* T2 = y->left;
        y->left = x;
        x->right = T2;
        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;
        return y;
    }
    int getBalance(TreeNode* node) {
        if (node == nullptr)
            return 0;
        return height(node->left) - height(node->right);
    }
    TreeNode* insert(TreeNode* node, int data) {
        if (node == nullptr)
            return new TreeNode(data);
        if (data < node->data)
            node->left = insert(node->left, data);
        else if (data > node->data)
            node->right = insert(node->right, data);
        else
            return node;
        node->height = 1 + max(height(node->left), height(node->right));
        int balance = getBalance(node);
        if (balance > 1 && data < node->left->data)
            return rightRotate(node);
        if (balance < -1 && data > node->right->data)
            return leftRotate(node);
        if (balance > 1 && data > node->left->data) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
        if (balance < -1 && data < node->right->data) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }
        return node;
    }
    void inorder(TreeNode* root) {
        if (root != nullptr) {
            inorder(root->left);
            cout << root->data << " ";
            inorder(root->right);
        }
    }
    void insert(int data) {
        root = insert(root, data);
    }
    void inorder() {
        inorder(root);
    }
};
int main() {
    AVLTree tree;
    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(40);
    tree.insert(50);
    tree.insert(25);
    cout << "Inorder traversal of the balanced tree: ";
    tree.inorder();
    cout << endl;
    return 0;
}

