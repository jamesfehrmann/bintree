// James Fehrmann
// Simple Binary Tree Walker
// License: MIT
// Editor: Neovim
// Date: 01/16/24

#include <iostream>

struct TreeNode {
    int value;
    TreeNode *left, *right;
    TreeNode(int nodeValue, TreeNode *left, TreeNode *right) : value(nodeValue), left(left), right(right) {}
    int nodeCount() {
        int count = 1;
        if (left != nullptr)
            count += left->nodeCount();
        if (right != nullptr)
            count += right->nodeCount();
        return count;
    }
    ~TreeNode() {
        delete left;
        delete right;
    }
};

TreeNode *treeBuilder(int i) {
    if (i == 0) {
        return new TreeNode(0, nullptr, nullptr);
    }
    return new TreeNode(i, treeBuilder(i - 1), treeBuilder(i - 1));
}

enum WalkMethod { INORDER,
                  PREORDER,
                  POSTORDER };

int printNode(TreeNode *node) {
    if (node == nullptr)
        return 0;
    std::cout << node->value << " " << std::flush;
    return 1;
}

int treeWalk(TreeNode *node, WalkMethod w, int count = 0) {
    if (node == nullptr)
        return count;
    if (w == WalkMethod::PREORDER) {
        count += printNode(node);
        count = treeWalk(node->left, w, count);
        count = treeWalk(node->right, w, count);
    } else if (w == WalkMethod::INORDER) {
        count = treeWalk(node->left, w, count);
        count += printNode(node);
        count = treeWalk(node->right, w, count);
    } else if (w == WalkMethod::POSTORDER) {
        count = treeWalk(node->left, w, count);
        count = treeWalk(node->right, w, count);
        count += printNode(node);
    }
    return count;
}

int main() {
    std::cout << "---" << std::endl;

    int h = 4;
    TreeNode *tree = treeBuilder(h);

    std::cout << "Tree Node Count: " << tree->nodeCount() << std::endl;

    std::cout << "Inorder Traversal: " << std::endl;
    int c1 = treeWalk(tree, WalkMethod::INORDER);
    std::cout << "(" << c1 << ")" << std::endl;

    std::cout << "Preorder Traversal: " << std::endl;
    int c2 = treeWalk(tree, WalkMethod::PREORDER);
    std::cout << "(" << c2 << ")" << std::endl;

    std::cout << "Postorder Traversal: " << std::endl;
    int c3 = treeWalk(tree, WalkMethod::POSTORDER);
    std::cout << "(" << c3 << ")" << std::endl;

    std::cout << "---" << std::endl;

    delete tree;
    tree = nullptr;

    return 0;
}
