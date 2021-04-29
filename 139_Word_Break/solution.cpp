#include <unordered_set>
#include <map>
#include "header.h"

static bool helper(string& s, unordered_set<string>& words, map<int, bool> history, int start);

bool wordBreak(string s, vector<string>& wordDict) {

    unordered_set<string> words(wordDict.begin(), wordDict.end());
    map<int, bool> history;

    return helper(s, words, history, 0);
}

bool helper(string& s, unordered_set<string>& words, map<int, bool> history, int start)
{
    if (start >= s.length())
    {
        return true;
    }

    for (int i = start; i < s.length(); i++)
    {
        string phase = s.substr(start, i - start + 1);

        if (history.find(i) != history.end() && history[i] == false)
        {
            return false;
        }

        if (history.find(i) != history.end() && history[i] == true)
        {
            return true;
        }

        if (words.find(phase) != words.end())
        {
            if (helper(s, words, history, i + 1))
            {
                history[i] = true;
                return true;
            }
            else
            {
                history[i] = false;
                //return false;
            }
        }
    }

    return false;
}