class Solution {
    public int maxSubArray(int[] nums) {
        int sum = 0;
        int temp = 0;
        for(int i = 0 ; i < nums.length ; i++)
        {
            temp += nums[i];
            if(temp > sum)
                sum = temp;
            if(temp < 0)
                temp = 0;
        }
        //if sum is zero that means all array elements are negative so return maximum element
        if(sum == 0)
        {
            sum = nums[0];
            for(int i = 1 ; i < nums.length ; i++)
            {
                if(sum < nums[i])
                    sum = nums[i];
            }
        }
        return sum;
    }
}
