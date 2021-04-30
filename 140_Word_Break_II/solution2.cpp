#include <map>
#include "header.h"

static bool helper(vector<string>& result, string sentence, map<pair<int, string>, bool>& history, vector<string>& wordDict, string& s, int start);

// Recursive
// Intuitive plus keeping a seach history to reduce searching numbers.
vector<string> wordBreak2(string s, vector<string>& wordDict)
{
    vector<string> result;
    map<pair<int, string>, bool> history;
    helper(result, "", history, wordDict, s, 0);
    return result;
}

bool helper(vector<string>& result, string sentence, map<pair<int, string>, bool>& history, vector<string>& wordDict, string& s, int start)
{
    bool rt = false;

    if (start >= s.length())
    {
        result.push_back(sentence);
        return true;
    }

    for (int i = 0; i < wordDict.size(); i++)
    {
        pair<int, string> p(start, wordDict[i]);
        if (history.find(p) != history.end() && history[p] == false)
        {
            continue;
        }

        if (s.find(wordDict[i], start) == start)
        {
            string phase = sentence.length() > 0 ? (" " + wordDict[i]) : wordDict[i];

            if (helper(result, sentence + phase, history, wordDict, s, start + wordDict[i].length()))
            {
                history[p] = true;
                rt = true;
            }
            else
            {
                history[p] = false;
            }
        }
        else
        {
            history[p] = false;
        }
    }

    return rt;
}