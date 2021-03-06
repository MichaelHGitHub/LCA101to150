#include <unordered_set>
#include <map>
#include "header.h"

static bool helper(string& s, vector<string>& wordDict, map<pair<int, string>, bool>& history, int start);

// Recursive
// Intuitive plus keeping a seach history to reduce searching numbers.
bool wordBreak2(string s, vector<string>& wordDict) {

    map<pair<int, string>, bool> history;
    return helper(s, wordDict, history, 0);
}

bool helper(string& s, vector<string>& wordDict, map<pair<int, string>, bool>& history, int start)
{
    if (start >= s.length())
    {
        return true;
    }

    for (int i = 0; i < wordDict.size(); i++)
    {
        pair<int, string> p(start, wordDict[i]);

        // If the index(start) has a record in history, that means
        // the previous interatiob has tried all the posibility starting
        // from start, then just use the result.
        if (history.find(p) != history.end())
        {
            return history[p];
        }

        // Could be like this as well. looks safer, won't miss any posibility.
        //if (history.find(p) != history.end() && history[p] == false)
        //{
        //    continue;
        //}

        if (s.find(wordDict[i], start) == start)
        {
            if (helper(s, wordDict, history, start + wordDict[i].length()))
            {
                history[p] = true;
                return true;
            }
        }
        
        history[p] = false;

    }

    return false;
}