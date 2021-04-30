#include <map>
#include "header.h"

static void helper(vector<string>& result, string sentence, vector<string>& wordDict, string& s, int start);

// Recursive
// In the recursive call, in stead of interating the given string, we can interate the wordDict,
// which will greately speed up the searching.
vector<string> wordBreak(string s, vector<string>& wordDict)
{
    vector<string> result;
    helper(result, "", wordDict, s, 0);
    return result;
}

void helper(vector<string>& result, string sentence, vector<string>& wordDict, string& s, int start)
{
    if (start >= s.length())
    {
        result.push_back(sentence);
        return;
    }

    for (int i = 0; i < wordDict.size(); i++)
    {
        if (s.find(wordDict[i], start) == start)
        {
            string phase = sentence.length() > 0 ? (" " + wordDict[i]) : wordDict[i];
            helper(result, sentence + phase, wordDict, s, start + wordDict[i].length());
        }
    }
}