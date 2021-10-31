#include "header.h"

static void helper(vector<vector<char>>& board, int r, int c);

// 1. Mark the edge 'O' as 'T'
// 2. Spread 'T' to every 'O' it can reach in 4 directions
// 3. Change remaining 'O' to 'X'
// 4. Change 'T' to 'O'
void solve_r(vector<vector<char>>& board)
{
    for (int i = 0; i < board.size(); i++)
    {
        if (board[i][0] == 'O')
        {
            board[i][0] = 'T';
        }

        if (board[i][board[i].size() - 1] == 'O')
        {
            board[i][board[i].size() - 1] = 'T';
        }
    }

    for (int j = 0; j < board[0].size(); j++)
    {
        if (board[0][j] == 'O')
        {
            board[0][j] = 'T';
        }

        if (board[board.size() - 1][j] == 'O')
        {
            board[board.size() - 1][j] = 'T';
        }
    }

    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            if (board[i][j] == 'T')
            {
                helper(board, i, j - 1);
                helper(board, i, j + 1);
                helper(board, i - 1, j);
                helper(board, i + 1, j);
            }
        }
    }

    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            if (board[i][j] == 'O')
            {
                board[i][j] = 'X';
            }

            if (board[i][j] == 'T')
            {
                board[i][j] = 'O';
            }
        }
    }
}

void helper(vector<vector<char>>& board, int r, int c)
{
    if (r < 0 || r == board.size() || c < 0 || c == board[r].size())
    {
        return;
    }

    if (board[r][c] == 'O')
    {
        board[r][c] = 'T';

        helper(board, r, c - 1);
        helper(board, r, c + 1);
        helper(board, r - 1, c);
        helper(board, r + 1, c);
    }
}