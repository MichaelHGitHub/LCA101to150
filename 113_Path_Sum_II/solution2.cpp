#include <stack>
#include <map>
#include "header.h"

// Iterative
// Typical pre-order traversal plus tracking the path of each node(from root to the node), 
// and the sum of the path. Save them in two maps.
vector<vector<int>> pathSum2(TreeNode* root, int targetSum)
{
    vector<vector<int>> result;

    if (root == nullptr)
    {
        return result;
    }

    stack<TreeNode*> pending_nodes;

    // Track path to node and sum of the path
    map<TreeNode*, vector<int>> paths;
    map<TreeNode*, int> sums;

    pending_nodes.push(root);
    sums[root] = root->val;
    paths[root] = vector<int>(1, root->val);

    while (!pending_nodes.empty())
    {
        TreeNode* node = pending_nodes.top();
        pending_nodes.pop();

        // Retrive the path of the node and sum of the path
        vector<int> path = paths[node];
        int sum = sums[node];

        if (node->left == nullptr && node->right == nullptr && sum == targetSum)
        {
            result.push_back(path);
        }

        if (node->left != nullptr)
        {
            pending_nodes.push(node->left);
            sums[node->left] = (sum + node->left->val);
            paths[node->left] = path;
            paths[node->left].push_back(node->left->val);
        }

        if (node->right != nullptr)
        {
            pending_nodes.push(node->right);
            sums[node->right] = (sum + node->right->val);
            paths[node->right] = path;
            paths[node->right].push_back(node->right->val);
        }

    }

    return result;
}

