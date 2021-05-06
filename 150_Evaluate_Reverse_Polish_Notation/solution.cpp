#include <stack>
#include "header.h"

int evalRPN(vector<string>& tokens)
{
    stack<int> pending;

    for (int i = 0; i < tokens.size(); i++)
    {
        if (tokens[i] == "+")
        {
            int operand1 = pending.top();
            pending.pop();
            int operand2 = pending.top();
            pending.pop();

            pending.push(operand2 + operand1);

        }
        else if (tokens[i] == "-")
        {
            int operand1 = pending.top();
            pending.pop();
            int operand2 = pending.top();
            pending.pop();

            pending.push(operand2 - operand1);
        }
        else if (tokens[i] == "*")
        {
            int operand1 = pending.top();
            pending.pop();
            int operand2 = pending.top();
            pending.pop();

            pending.push(operand2 * operand1);
        }
        else if (tokens[i] == "/")
        {
            int operand1 = pending.top();
            pending.pop();
            int operand2 = pending.top();
            pending.pop();

            pending.push(operand2 / operand1);
        }
        else
        {
            pending.push(atoi(tokens[i].c_str()));
        }
    }

    return pending.top();
}