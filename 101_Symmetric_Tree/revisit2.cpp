#include "header.h"
#include <stack>

bool isSymmetric_r2(TreeNode* root)
{
    bool result = true;
    std::stack<TreeNode*> q1, q2;

    if (!root)
    {
        result = true;
    }
    else
    {
        q1.push(root);
        q2.push(root);

        while (!q1.empty() && !q2.empty())
        {
            TreeNode* node1 = q1.top();
            TreeNode* node2 = q2.top();
            q1.pop();
            q2.pop();

            if (node1->val != node2->val)
            {
                result = false;
                break;
            }
            else if(
                (node1->left && !node2->right) ||
                (node1->right && !node2->left) ||
                (!node1->left && node2->right) ||
                (!node1->right && node2->left))
            {
                result = false;
                break;
            }
            else
            {
                if (node1->right)
                {
                    q1.push(node1->right);
                }

                if (node1->left)
                {
                    q1.push(node1->left);
                }

                if (node2->left)
                {
                    q2.push(node2->left);
                }

                if (node2->right)
                {
                    q2.push(node2->right);
                }
            }
        }

        if (!q1.empty() || !q2.empty())
        {
            result = false;
        }
    }

    return result;
}