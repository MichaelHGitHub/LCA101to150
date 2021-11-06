#include "header.h"
#include <unordered_set>

static bool helper(vector<int>& history, unordered_set<string>& wordSet, string& s, int pos);

bool wordBreak_r(string s, vector<string>& wordDict)
{
    unordered_set<string> wordSet(wordDict.begin(), wordDict.end());

    vector<int> history(s.length() + 1, -1);
    return helper(history, wordSet, s, 0);
}

bool helper(vector<int>& history, unordered_set<string>& wordSet, string& s, int pos)
{
    if (pos == s.length())
    {
        return true;
    }

    for (int i = pos; i < s.length(); i++)
    {
        string sub = s.substr(pos, i - pos + 1);

        if (wordSet.find(sub) != wordSet.end())
        {
            if (1 == history[i + 1])
            {
                return true;
            }
            else if (-1 == history[i + 1])
            {
                if (helper(history, wordSet, s, i + 1))
                {
                    history[i + 1] = 1;
                    return true;
                }
            }
        }
    }

    history[pos] = 0;
    return false;
}