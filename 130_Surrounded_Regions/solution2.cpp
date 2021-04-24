#include <queue>
#include <set>
#include "header.h"

// Use an array same size as board to mark the captured "O".
// Captured "O" in three steps:
// 1. Scan the board and find the all "O" that are free. 
//    put all the free "O"s into a queue.
// 2. Let each of the free "O" try to rescure its neighbour. 
// 3. Replace the captured "O".

void solve2(vector<vector<char>>& board)
{
    // A queue to hold free O
    queue<pair<int, int>> free_O;
    set< pair<int, int>> visited;

    int m = board.size();
    int n = board[0].size();
    vector<vector<bool>> capture_mark(m, vector<bool>(n, true));


    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] == 'X' || i == 0 || i == m - 1 || j == 0 || j == n - 1)
            {
                capture_mark[i][j] = false;

                if (board[i][j] == 'O')
                {
                    free_O.push(pair<int, int>(i, j));
                }
            }
        }
    }

    while (!free_O.empty())
    {
        pair<int, int> pos = free_O.front();
        free_O.pop();
        visited.insert(pos);

        if (pos.first > 0 && board[pos.first - 1][pos.second] == 'O' && visited.find(pair<int, int>(pos.first - 1, pos.second)) == visited.end())
        {
            capture_mark[pos.first - 1][pos.second] = false;
            free_O.push(pair<int,int>(pos.first - 1, pos.second));
        }

        if (pos.first < m-1 && board[pos.first + 1][pos.second] == 'O' && visited.find(pair<int, int>(pos.first + 1, pos.second)) == visited.end())
        {
            capture_mark[pos.first + 1][pos.second] = false;
            free_O.push(pair<int, int>(pos.first + 1, pos.second));
        }

        if (pos.second > 0 && board[pos.first][pos.second - 1] == 'O' && visited.find(pair<int, int>(pos.first, pos.second - 1)) == visited.end())
        {
            capture_mark[pos.first][pos.second - 1] = false;
            free_O.push(pair<int, int>(pos.first, pos.second - 1));
        }

        if (pos.second < n-1 > 0 && board[pos.first][pos.second + 1] == 'O' && visited.find(pair<int, int>(pos.first, pos.second + 1)) == visited.end())
        {
            capture_mark[pos.first][pos.second + 1] = false;
            free_O.push(pair<int, int>(pos.first, pos.second + 1));
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (capture_mark[i][j])
            {
                board[i][j] = 'X';
            }
        }
    }
}

