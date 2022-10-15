#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double findMedianSortedArraysNaive(vector<int> &nums1, vector<int> &nums2)
    {
        // vector for storing merged array
        vector<int> merged(nums1.size() + nums2.size());

        // using inbuilt merge function
        merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), merged.begin());

        // conditional for median based on parity of the size of merged array
        if (merged.size() % 2)
        {
            return (merged[merged.size() / 2] + 0.00);
        }
        else
        {
            return (merged[merged.size() / 2] + merged[(merged.size() / 2) - 1]) / 2.0;
        }
    }

    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        // below approach uses concept of binary search

        int n = nums1.size();
        int m = nums2.size();

        if (n > m)
            return findMedianSortedArrays(nums2, nums1); // Swapping to make A smaller

        int start = 0;
        int end = n;

        int realmidinmergedarray = (n + m + 1) / 2;

        while (start <= end)
        {
            int mid = (start + end) / 2;

            // size of two partition
            int leftAsize = mid;
            int leftBsize = realmidinmergedarray - mid;

            // checking overflow at edges
            int leftA = (leftAsize > 0) ? nums1[leftAsize - 1] : INT_MIN;
            int leftB = (leftBsize > 0) ? nums2[leftBsize - 1] : INT_MIN;
            int rightA = (leftAsize < n) ? nums1[leftAsize] : INT_MAX;
            int rightB = (leftBsize < m) ? nums2[leftBsize] : INT_MAX;

            // if correct partition is done
            if (leftA <= rightB and leftB <= rightA)
            {
                if ((m + n) % 2 == 0)
                    return (max(leftA, leftB) + min(rightA, rightB)) / 2.0;

                return max(leftA, leftB);
            }
            else if (leftA > rightB)
            {
                end = mid - 1;
                // changing the partition to left
            }
            else
            {
                start = mid + 1;
                // changing the partition to right
            }
        }
        return 0.0;
    }
};
