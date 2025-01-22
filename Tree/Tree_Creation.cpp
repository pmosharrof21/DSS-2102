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
class BinaryTree {
public:
    TreeNode* root;
    BinaryTree() {
        root = nullptr;
    }
    void insert(int data) {
        root = insertRec(root, data);
    }
    void inorder() {
        inorderRec(root);
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
};
int main() {
    BinaryTree tree;
    tree.insert(50);
    tree.insert(30);
    tree.insert(20);
    tree.insert(40);
    tree.insert(70);
    tree.insert(60);
    tree.insert(80);
    cout << "Inorder traversal of the tree: ";
    tree.inorder();
    cout << endl;
    return 0;
}

