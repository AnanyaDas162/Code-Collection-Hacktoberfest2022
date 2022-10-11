class Solution {
    public int[] nextGreaterElement(int[] nums1, int[] nums2) {
        int b[]=new int[nums1.length];
        int i;
        
        for(i=0;i<nums1.length;i++){
            int j=nums2.length-1;
            int res=-1;
            while(j>=0 && (nums1[i]!=nums2[j]))
            {
                if(nums2[j]>nums1[i])
                {
                    res=nums2[j];
                    
                }
                j--;
            }
            b[i]=res;
        }
        return b;
    }
}
