/* 
problem statement:

There is an integer array nums sorted in ascending order (with distinct values).

Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

You must write an algorithm with O(log n) runtime complexity.

*/





/* This is always possible when we are at mid either left half is sorted or right haldf is sorted */
class Solution {
public:
    int search(vector<int>& arr, int target) {
        int n = arr.size();
        int low = 0, high = n-1;
        long int mid = -1;
        while(low <= high){
            mid = low + (high-low)/2;
            if(arr[mid] == target) return  mid;
            if(arr[mid] >= arr[low]){
                /* left half sorted */
                if(target >= arr[low] && target < arr[mid]) high = mid-1;
                else low = mid+1;
            }
            else{
                /* right half is sorted */
                if( target > arr[mid] && target <= arr[high]) low = mid+1;
                else high = mid-1;
            }
        }
        return -1;
    }
};

time complexity : O(logn)
space complexity : O(1)
