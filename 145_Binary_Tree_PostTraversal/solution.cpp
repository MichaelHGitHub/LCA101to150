#include <stack>
#include <unordered_set>
#include "header.h"

vector<int> postorderTraversal(TreeNode* root) {

    vector<int> result;

    if (!root)
    {
        return result;
    }

    stack<TreeNode*> pending;
    unordered_set<TreeNode*> visited;
    pending.push(root);

    while (!pending.empty())
    {
        TreeNode* node = pending.top();
        bool left_visited = node->left ? (visited.find(node->left) != visited.end()) : true;
        bool right_visited = node->right ? (visited.find(node->right) != visited.end()) : true;


        if (right_visited && left_visited)
        {
            result.push_back(node->val);
            visited.insert(node);
            pending.pop();
        }
        else
        {
            if (node->right && !right_visited)
            {
                pending.push(node->right);
            }

            if (node->left && !left_visited)
            {
                pending.push(node->left);
            }
        }
    }
    return result;
}