#include "header.h"

void sumOfPath(int& totalSum, TreeNode* node, int sum);

int sumNumbers_r(TreeNode* root)
{
    int total_sum = 0;
    sumOfPath(total_sum, root, 0);

    return total_sum;
}

void sumOfPath(int& totalSum, TreeNode* node, int sum)
{
    if (nullptr == node)
    {
        return;
    }

    sum = sum * 10 + node->val;
    if (nullptr == node->left && nullptr == node->right)
    {
        totalSum += sum;
        return;
    }

    sumOfPath(totalSum, node->left, sum);
    sumOfPath(totalSum, node->right, sum);
}