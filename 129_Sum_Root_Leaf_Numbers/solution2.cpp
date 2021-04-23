#include <stack>
#include <unordered_set>
#include "header.h"

// Iterative
// post-order traversal plus build the number in pre-order oder.
// Need post-order traversal because we need to back track the number in post-order
// traversal order.
int sumNumbers2(TreeNode* root)
{
    int sum = 0;

    if (!root)
    {
        return sum;
    }

    // Need a stack and a set to do post-order traversal.
    stack<TreeNode*> pending_nodes;
    unordered_set<TreeNode*> visited;

    int num = 0;
    pending_nodes.push(root);
    while (!pending_nodes.empty())
    {
        TreeNode* node = pending_nodes.top();

        bool left_visited = (visited.find(node->left) != visited.end());
        bool right_visited = (visited.find(node->right) != visited.end());

        // First time meet the node, add its value to number(pre-order build number).
        if (!left_visited && !right_visited)
        {
            num = num * 10 + node->val;
        }

        // If this is a leaf node, a number is complete, add to sum.
        if (!node->left && !node->right)
        {
            sum += num;
        }

        // Check if a node needs to be popped, normal post-order operation:
        // If no child needs to be handled, pop the node out. 
        if ((!node->left || left_visited) && (!node->right || right_visited))
        {
            // Remove the current node value from the number because it is used
            // and need to remove it so that we can build next number.
            num /= 10;
            pending_nodes.pop();
            visited.insert(node);
            continue;
        }

        // If there are unhandled child, add them to the stack.

        if (node->right && !right_visited)
        {
            pending_nodes.push(node->right);
        }
        
        if (node->left && !left_visited)
        {
            pending_nodes.push(node->left);
        }
    }
    return sum;
}

