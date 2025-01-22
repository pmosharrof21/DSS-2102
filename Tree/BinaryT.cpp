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
        cout << endl;
    }

    void preorder() {
        preorderRec(root);
        cout << endl;
    }

    void postorder() {
        postorderRec(root);
        cout << endl;
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

    void preorderRec(TreeNode* node) {
        if (node != nullptr) {
            cout << node->data << " ";
            preorderRec(node->left);
            preorderRec(node->right);
        }
    }

    void postorderRec(TreeNode* node) {
        if (node != nullptr) {
            postorderRec(node->left);
            postorderRec(node->right);
            cout << node->data << " ";
        }
    }
};

int main() {
    BinaryTree tree;
    tree.insert(58);
    tree.insert(35);
    tree.insert(27);
    tree.insert(42);
    tree.insert(78);
    tree.insert(66);
    tree.insert(81);

    cout << "Inorder traversal: ";
    tree.inorder();

    cout << "Preorder traversal: ";
    tree.preorder();

    cout << "Postorder traversal: ";
    tree.postorder();

    return 0;
}
