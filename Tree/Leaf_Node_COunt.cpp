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

    int countLeafNodes() {
        return countLeafNodesRec(root);
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

    int countLeafNodesRec(TreeNode* node) {
        if (node == nullptr) {
            return 0;
        }
        if (node->left == nullptr && node->right == nullptr) {
            return 1;
        }
        return countLeafNodesRec(node->left) + countLeafNodesRec(node->right);
    }
};

int main() {
    BinaryTree tree;
    tree.insert(37);
    tree.insert(52);
    tree.insert(67);
    tree.insert(40);
    tree.insert(70);
    tree.insert(28);
    tree.insert(86);
    cout << "Number of leaf nodes: " << tree.countLeafNodes() << endl;
    return 0;
}

