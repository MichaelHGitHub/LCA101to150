#include "header.h"

// Calculate the min path to each joint in a buttom up approach, 
// the value of the top is the min path. 
// Save the temp sums into the triangle array, no extra space is needed.
int minimumTotal(vector<vector<int>>& triangle)
{
    for (int i = triangle.size() - 2; i >= 0; i--)
    {
        for (int j = 0; j <= i; j++)
        {
            triangle[i][j] += min(triangle[i + 1][j], triangle[i + 1][j + 1]);
        }
    }

    return triangle[0][0];
}