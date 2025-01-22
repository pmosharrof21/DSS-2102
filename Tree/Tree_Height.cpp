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

    int getHeight() {
        return getHeightRec(root);
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

    int getHeightRec(TreeNode* node) {
        if (node == nullptr) {
            return 0;
        }

        int leftHeight = getHeightRec(node->left);
        int rightHeight = getHeightRec(node->right);

        return max(leftHeight, rightHeight) + 1;
    }
};

int main() {
    BinaryTree tree;
    tree.insert(60);
    tree.insert(30);
    tree.insert(20);
    tree.insert(80);
    tree.insert(50);
    tree.insert(70);
    tree.insert(40);

    cout << "Height of the tree: " << tree.getHeight() << endl;

    return 0;
}

