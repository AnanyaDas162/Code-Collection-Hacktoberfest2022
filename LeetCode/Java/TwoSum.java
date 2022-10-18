class Solution {
    public int[] twoSum(int[] nums, int target) {
        int i,j,s[]=new int[2],t=0;
        for(i=0;i<nums.length-1;i++){
            for(j=i+1;j<nums.length;j++){
                if(nums[i]+nums[j]==target){
                    s[0]=i;
                    s[1]=j;
                    break;
                }
                }
        }
        return s;
    }
}
