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

void printNode(TreeNode *node) {
    std::cout << node->value << " " << std::flush;
}

void treeWalk(TreeNode *node, WalkMethod w) {
    if (w == WalkMethod::PREORDER)
        printNode(node);
    if (node->value > 0)
        treeWalk(node->left, w);
    if (w == WalkMethod::INORDER)
        printNode(node);
    if (node->value > 0)
        treeWalk(node->right, w);
    if (w == WalkMethod::POSTORDER)
        printNode(node);
}

int main() {
    std::cout << "---" << std::endl;

    int h = 4;
    TreeNode *tree = treeBuilder(h);

    std::cout << "Inorder   Traversal: ";
    treeWalk(tree, WalkMethod::INORDER);
    std::cout << std::endl;

    std::cout << "Preorder  Traversal: ";
    treeWalk(tree, WalkMethod::PREORDER);
    std::cout << std::endl;

    std::cout << "Postorder Traversal: ";
    treeWalk(tree, WalkMethod::POSTORDER);
    std::cout << std::endl;

    std::cout << "---" << std::endl;
    return 0;
}
