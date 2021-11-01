#include "header.h"
#include <unordered_map>

static vector<vector<string>> helper(unordered_map<int, vector<vector<string>>>& history, string& s, int pos);
static bool isParlindrome(string& s);

vector<vector<string>> partition_r(string s)
{
    unordered_map<int, vector<vector<string>>> history;
    return helper(history, s, 0);
}

vector<vector<string>> helper(unordered_map<int, vector<vector<string>>>& history, string& s, int pos)
{
    vector<vector<string>> result;
    if (pos == s.length())
    {
        return result;
    }

    if (history.find(pos) != history.end())
    {
        return history[pos];
    }

    for (int i = pos; i < s.length(); i++)
    {
        string sub = s.substr(pos, i - pos + 1);
        if (isParlindrome(sub))
        {
            vector<vector<string>> subSet = helper(history, s, i + 1);
            if (subSet.size() > 0)
            {
                for (int j = 0; j < subSet.size(); j++)
                {
                    vector<string> one_set;
                    one_set.push_back(sub);
                    one_set.insert(one_set.begin() + 1, subSet[j].begin(), subSet[j].end());
                    result.push_back(one_set);
                }
            }
            else
            {
                result.push_back(vector<string>(1, sub));
            }
        }
    }

    history[pos] = result;
    return result;
}

bool isParlindrome(string& s)
{
    if (s == string(s.rbegin(), s.rend()))
    {
        return true;
    }
    else
    {
        return false;
    }
}