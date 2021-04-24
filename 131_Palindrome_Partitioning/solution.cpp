#include "header.h"

static void helper(vector<vector<string>>& result, vector<vector<int>>& history, vector<string>& one_set, string s, int start);

// Recursive
// For every start, try 1, 2, 3, ... n-start chars, if it is palindrome, then 
// recursively try next start(start + count).
// Use a 2-D array to track checking history to reduce calculation. 
// history[start][end] marks if a string from start to end is palindrome
vector<vector<string>> partition(string s)
{
    vector<vector<int>> history(s.length(), vector<int>(s.length(), 0));
    vector<vector<string>> result;
    vector<string> one_set;
    helper(result, history, one_set, s, 0);

    return result;
}

void helper(vector<vector<string>>& result, vector<vector<int>>& history, vector<string>& one_set, string s, int start)
{
    if (start >= s.length())
    {
        result.push_back(one_set);
        return;
    }

    for (int end = start; end < s.length(); end++)
    {
        if (history[start][end] == 1 ||
           (s[start] == s[end] && (end - start < 3 || history[start + 1][end - 1] == 1 )))
        {
            history[start][end] = 1;
            one_set.push_back(s.substr(start, end - start + 1));
            helper(result, history, one_set, s, end + 1);
            one_set.pop_back();
        }
        else
        {
            history[start][end] = -1;
        }
    }
}