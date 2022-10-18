/* Given no. of eggs and floors, find the nearest floor from 1st floor
at which egg breaks, find the min of the worstcase time taken. */

#include<bits/stdc++.h>
using namespace std;

int t[11][51];

int mcm(int e, int f)
{
// If floor is 0 or 1 then f is the worst case
    if(f == 0 || f == 1)
        return f;
// If egg is 1, worstcase will be f, becoz we will start from 1st floor
// till f'th floor.
    if(e == 1)
        return f;

    int mn = INT_MAX;
    for(int k=1; k<=f; k++){
// Find the worstcase time
        int temp = 1 + max(mcm(e-1, k-1), mcm(e, f-k));
// Find min of the worstcase times
        mn = min(mn, temp);
    }

    return mn;
}

int mcm_m(int e, int f)
{
    if(f == 0 || f == 1)
        return f;
    if(e == 1)
        return f;

    if(t[e][f] != -1)
        return t[e][f];

    int mn = INT_MAX;
    for(int k=1; k<=f; k++){
        int temp = 1 + max(mcm_m(e-1, k-1), mcm_m(e, f-k));
        mn = min(mn, temp);
    }

    return t[e][f] = mn;
}

int mcm_dp(int e, int f)
{
    if(f == 0 || f == 1)
        return f;
    if(e == 1)
        return f;

    if(t[e][f] != -1)
        return t[e][f];

    int mn = INT_MAX;
    for(int k=1; k<=f; k++){
        int low = 0, high = 0;
        if(t[e-1][k-1] != -1)
            low = t[e-1][k-1];
        else{
            low = mcm_dp(e-1, k-1);
            t[e-1][k-1] = low;
        }
        if(t[e][f-k] != -1)
            high = t[e][f-k];
        else{
            high = mcm_dp(e, f-k);
            t[e][f-k] = high;
        }

        int temp = 1 + max(low, high);
        mn = min(mn, temp);
    }

    return t[e][f] = mn;
}

int main()
{
    int e = 3, f = 5;
    memset(t, -1, sizeof(t));

    cout << mcm(e, f) << "\n";
    cout << mcm_m(e, f) << "\n";
    cout << mcm_dp(e, f) << "\n";

    return 0;
}
