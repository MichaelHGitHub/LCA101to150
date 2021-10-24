#include "header.h"

int minimumTotal_r2(vector<vector<int>>& triangle)
{
    int minSum = INT32_MAX;
    vector<int> pathSums(triangle.size(), 0);
    for (int i = 0; i < triangle.size(); i++)
    {
        int min_in_row = INT32_MAX;
        for (int j = triangle[i].size() - 1; j >= 0; j--)
        {
            if (j == 0)
            {
                pathSums[j] = pathSums[j] + triangle[i][j];
            }
            else if(j == triangle[i].size() - 1)
            {
                pathSums[j] = pathSums[j - 1] + triangle[i][j];
            }
            else
            {
                pathSums[j] = min(pathSums[j], pathSums[j-1]) + triangle[i][j];
            }
            min_in_row = min(min_in_row, pathSums[j]);
        }
        minSum = min_in_row;
    }
    return minSum;
}