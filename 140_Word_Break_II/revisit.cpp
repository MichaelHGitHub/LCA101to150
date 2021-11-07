#include "header.h"
#include <unordered_map>
#include <unordered_set>

static vector<string> helper(std::unordered_map<int, vector<string>>& history, unordered_set<string>& wordDict, string& s, int pos);

vector<string> wordBreak_r(string s, vector<string>& wordDict)
{
    unordered_map<int, vector<string>> history;
    unordered_set<string> wordSet(wordDict.begin(), wordDict.end());

    return helper(history, wordSet, s, 0);
}

vector<string> helper(std::unordered_map<int, vector<string>>& history, unordered_set<string>& wordDict, string& s, int pos)
{
    vector<string> sentences;
    if (pos >= s.length())
    {
        return sentences;
    }

    if (history.find(pos) != history.end())
    {
        return history[pos];
    }

    for (int i = pos; i < s.length(); i++)
    {
        string sub = s.substr(pos, i - pos + 1);

        if (wordDict.find(sub) != wordDict.end())
        {
            vector<string> children = helper(history, wordDict, s, i + 1);
            if (children.size() > 0)
            {
                for (int j = 0; j < children.size(); j++)
                {
                    sentences.push_back(sub + " " + children[j]);
                }
            }
            else if (i == s.length() - 1)
            {
                sentences.push_back(sub);
            }
        }
    }

    if (sentences.size() > 0)
    {
        history[pos] = sentences;
    }
    return sentences;
}