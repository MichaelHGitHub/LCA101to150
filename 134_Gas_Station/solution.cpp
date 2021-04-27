#include "header.h"

// Brute force
int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
{
    int balance = 0;

    for (int i = 0; i < gas.size(); i++)
    {
        balance = gas[i] - cost[i];
        int j = (i + 1) % gas.size();
        while (j != i && balance >= 0)
        {
            balance = balance + gas[j] - cost[j];

            j = (j + 1) % gas.size();
        }

        if (j == i && balance >= 0)
        {
            return i;
        }
    }

    return -1;
}