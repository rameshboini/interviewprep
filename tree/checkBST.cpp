#include "tree.h"

bool isBSTUtil(Node *root, int min, int max)
{
    if (!root)
        return true;

    if (root->data < min || root->data > max)
        return false;

    return isBSTUtil(root->left, min, root->data - 1) &&
           isBSTUtil(root->right, root->data + 1, max);
}

bool isBST(Node *root)
{
    return isBSTUtil(root, INT16_MIN, INT16_MAX);
}

int main()
{
    Node *root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(1);
    root->left->right = new Node(6);

    if (isBST(root))
        cout << "Is BST";
    else
        cout << "Not a BST";

    return 0;
}