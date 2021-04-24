#include <set>
#include "header.h"

static bool isFree(vector<vector<char>>& board, vector<vector<int>>& records, int i, int j, set<pair<int,int>>& visited );

// Brute force, exceeds the time limit of some test case
void solve(vector<vector<char>>& board)
{
    int m = board.size();
    int n = board[0].size();
    vector<vector<int>> records(m, vector<int>(n, 0));
    

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] == 'X')
            {
                records[i][j] = -1;
            }
            else
            {
                set<pair<int, int>> visited;
                if (!isFree(board, records, i, j, visited))
                {
                    board[i][j] = 'X';
                }
            }
        }
    }
}

bool isFree(vector<vector<char>>& board, vector<vector<int>>& records, int i, int j, set<pair<int, int>>& visited)
{
    if (board[i][j] == 'X')
    {
        records[i][j] = -1;
        return false;
    }

    int m = board.size();
    int n = board[0].size();

    if (i == 0 || i == m - 1 || j == 0 || j == n - 1)
    {
        records[i][j] = 1;
        return true;
    }

    std::pair<int, int> pos(i, j);
    if (records[i][j] == 1)
    {
        return true;
    }
    else if (records[i][j] == -1)
    {
        return false;
    }
    else if(visited.find(pos) != visited.end())
    {
        return false;
    }

    visited.insert(pos);
    
    if ((isFree(board, records, i + 1, j, visited)) ||
        (isFree(board, records, i - 1, j, visited)) ||
        (isFree(board, records, i, j + 1, visited)) ||
        (isFree(board, records, i, j - 1, visited)))
    {
        records[i][j] = 1;
        return true;
    }
    else
    {
        return false;
    }
}