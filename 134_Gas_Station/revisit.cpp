#include "header.h"

int canCompleteCircuit_r(vector<int>& gas, vector<int>& cost)
{
    int start_station = -1;

    for (int i = 0; i < gas.size(); i++)
    {
        int pos = i;
        int tank_gas = 0;

        do
        {
            tank_gas += gas[pos];
            tank_gas -= cost[pos];

            if (tank_gas >= 0)
            {
                pos = ++pos % gas.size();
            }
        } while (tank_gas >= 0 && pos != i);

        if (tank_gas >= 0 && pos == i)
        {
            start_station = i;
            break;
        }

    }

    return start_station;
}