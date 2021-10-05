#include "header.h"

bool areSymmetricNodes(TreeNode* node1, TreeNode* node2);

bool isSymmetric_r(TreeNode* root)
{
    return areSymmetricNodes(root, root);
}

bool areSymmetricNodes(TreeNode* node1, TreeNode* node2)
{
    bool result = false;

    if (!node1 && !node2)
    {
        result = true;
    }
    else if ((!node1 && node2) ||
             (node1 && !node2))
    {
        result = false;
    }
    else if (node1->val != node2->val)
    {
        result = false;
    }
    else
    {
        result = areSymmetricNodes(node1->left, node2->right) &&
                 areSymmetricNodes(node1->right, node2->left);
    }

    return result;
}
