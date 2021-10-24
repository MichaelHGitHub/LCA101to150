#include "header.h"

void helper(vector<vector<int>>& triangle, int& minSum, int sum, int row, int col);

int minimumTotal_r(vector<vector<int>>& triangle)
{
    int minSum = INT32_MAX;
    helper(triangle, minSum, 0, 0, 0);
    return minSum;
}


void helper(vector<vector<int>>& triangle, int& minSum, int sum, int row, int col)
{
    if (row >= triangle.size())
    {
        minSum = min(minSum, sum);
        return;
    }

    helper(triangle, minSum, sum + triangle[row][col], row + 1, col);
    helper(triangle, minSum, sum + triangle[row][col], row + 1, col + 1);
}