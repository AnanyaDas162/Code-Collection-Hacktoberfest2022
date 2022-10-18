class Solution {
    public int searchInsert(int[] nums, int target) {
        int i=0, j=nums.length-1, mid=0, ans=0;
        if(target<nums[i])
            return i;
        if(target>nums[j])
            return j+1;
        while(i<=j)
        {
            mid = (i+j)/2;
            if(target==nums[mid])
                return mid;
            else if(target>nums[mid])
            {
                i=mid+1;
                ans=mid+1;
            }
            else if(target<nums[mid])
            {
                j=mid-1;
                ans=mid;
            }
        }
        return ans;
    }
}
