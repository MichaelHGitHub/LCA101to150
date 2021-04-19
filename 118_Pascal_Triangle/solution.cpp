#include "header.h"

// In each row of a Pacal's triangle, the first and the last elements are always
// 1 because they are lack of one element in the previous row to add on. 
// the rest of the triangles are the sum of two triangles in the previous row.
// 
vector<vector<int>> generate(int numRows)
{
    vector<vector<int>> result;

    for (int i = 0; i < numRows; i++)
    {
        vector<int> row(i+1);
        result.push_back(row);

        for (int j = 0; j < i + 1; j++)
        {
            // First and last elements in a row is always a fixed value, in this
            // case 1. 
            if (j == 0 || j == i)
            {
                result[i][j] = 1;
            }
            else
            {
                result[i][j] = result[i - 1][j - 1] + result[i - 1][j];
            }
        }
    }

    return result;
}