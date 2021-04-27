#include "header.h"

// 
// There are only 2 posibilities: one way or no way. 
// If the sum of the gas collected at each station along the way can't cover the total
// cost, then it is no way. 
// To find the one and only way, let's consider this route: Gj--->Gk--->Gi,G(i+1)--->Gl--->Gn.
// If starting from Gj and the current gas balance at Gi turns to negative, that means 
// the car can reach Gi starting from Gj, but can't reach G(i+1).
// As the balance at any station between Gj to Gi, say Gk, must be positive(that's how the car can reach Gk),
// then the balance at Gi would be even more negative if started from Gk, which means no station 
// between Gj and Gi, as starting point, can reach Gi. Therefore, our next starting point should be
// G(i+1).
// Then let's take look at the second half: assuming G(i+1) can reach Gn and the balance
// at Gn is m. In the same idea stated above, any station between G(i+1) and Gn, as a starting point, 
// will leave a balance at Gn that is less than m. Since we only have 1 solution, then the one
// that leaves highest balance should be the one as start point, which is G(i+1) in this
// illustration.
// 
int canCompleteCircuit2(vector<int>& gas, vector<int>& cost)
{
    int total_balance = 0;
    int cur_balance = 0;
    int start_point = 0;

    for (int i = 0; i < gas.size(); i++)
    {
        int cur_diff = gas[i] - cost[i];
        cur_balance += cur_diff;
        total_balance += cur_diff;

        if (cur_balance < 0)
        {
            cur_balance = 0;
            start_point = i + 1;
        }
    }

    return total_balance >=0? start_point: -1;
}