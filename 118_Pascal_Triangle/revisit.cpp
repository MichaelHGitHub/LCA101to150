#include "header.h"

vector<vector<int>> generate_r(int numRows)
{
    vector<vector<int>> result;
    // First row
    result.push_back(vector<int>(1,1));
    // Other rows
    for (int i = 1; i < numRows; i++)
    {
        result.push_back(vector<int>(i + 1, 1));

        // Colums between the first and the last
        for (int j = 1; j < i; j++)
        {
            result[i][j] = result[i - 1][j - 1] + result[i - 1][j];
        }
    }
    return result;
}