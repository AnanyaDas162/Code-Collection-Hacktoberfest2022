/*
Suppose an array of length n sorted in ascending order is rotated between 1 and n times. For example, the array nums = [0,1,2,4,5,6,7] might become:

[4,5,6,7,0,1,2] if it was rotated 4 times.
[0,1,2,4,5,6,7] if it was rotated 7 times.
Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].

Given the sorted rotated array nums of unique elements, return the minimum element of this array.

You must write an algorithm that runs in O(log n) time.
*/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        
        if(n == 1) return nums[0];
        
        /*
        choose nums[0] as pivot, 
        so we don't need to put nums[0] in the search range
        */
        int l = 0, r = n-1;
        
        //array is sorted, not rotated
        if(nums[l] < nums[r]) return nums[l];
        
        int mid;
        
        while(l <= r){
            mid = (l+r) >> 1;
            // cout << mid << endl;
            
            /*
            found the inflection point: 
            the position where right element < left element
            */
            if(nums[mid+1] < nums[mid]) return nums[mid+1];
            if(nums[mid] < nums[mid-1]) return nums[mid];
            
            if(nums[mid] < nums[0]){
                r = mid-1;
            }else{
                //nums[mid] > nums[0]
                l = mid+1;
            }
        }
        
        return -1;
    }
};

int main(){
  vector<int> nums = {3,4,5,1,2};
  cout<<findMin(nums);
  return 0;
}

//time: O(logN)
//space: O(1)
