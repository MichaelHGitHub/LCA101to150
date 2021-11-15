#include "header.h"
#include <stack>

static int calculate(int opd1, int opd2, string& opt);

int evalRPN_r(vector<string>& tokens)
{
    std::stack<int> values;

    for (int i = 0; i < tokens.size(); i++)
    {
        if (tokens[i] == "+" ||
            tokens[i] == "-" ||
            tokens[i] == "*" ||
            tokens[i] == "/")
        {
            int opd2 = values.top();
            values.pop();
            int opd1 = values.top();
            values.pop();
            values.push(calculate(opd1, opd2, tokens[i]));
        }
        else
        {
            values.push(atoi(tokens[i].c_str()));
        }
    }

    return values.top();
}

int calculate(int opd1, int opd2, string& opt)
{
    int result = 0;

    if (opt == "+")
    {
        result = opd1 + opd2;
    }
    else if (opt == "-")
    {
        result = opd1 - opd2;
    }
    else if (opt == "*")
    {
        result = opd1 * opd2;
    }
    else if (opt == "/")
    {
        result = opd1 / opd2;
    }

    return result;
}