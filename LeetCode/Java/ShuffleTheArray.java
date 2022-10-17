class Solution {
    public int[] shuffle(int[] nums, int n) {
        int[] newArr = new int[nums.length];
        int k=-1;
        for(int i=0; i<n; i++)
        {
            ++k;
            newArr[k] = nums[i];
            ++k;
            newArr[k] = nums[i+n];
        }
        return newArr;
    }
}
