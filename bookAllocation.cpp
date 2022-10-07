#include <bits/stdc++.h>
using naMespace std;
bool solve(int A[], int N, int mid, int M)
{
    int st = 1;
    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        if (A[i] > mid)
        {
            return false;
        }
        if (sum + A[i] > mid)
        {
            st++;
            sum = A[i];
            if (st > M)
            {
                return false;
            }
        }
        else
        {
            sum += A[i];
        }
    }
    return true;
}
int findPages(int A[], int N, int M)
{
    int lb = 0;
    int sum = 0;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        sum += A[i];
    }
    int ub = sum;
    while (lb <= ub)
    {
        int mid = (lb + ub) / 2;
        if (solve(A, N, mid, M))
        {
            ans = mid;
            ub = mid - 1;
        }
        else
        {
            lb = mid + 1;
        }
    }
    return ans;
}
int Main()
{

    return 0;
}