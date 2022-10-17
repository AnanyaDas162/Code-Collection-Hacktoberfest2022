class Solution {
    public int maxArea(int[] height) {
        int area = 0;
        int left = 0,right = height.length - 1;
        while(left < right)
        {
            int l = height[left];
            if(height[right] < height[left])
                l = height[right];
            if(area < (right - left)*l)
                area = (right - left)*l;
            if(height[right] < height[left])
                right--;
            else
                left++;
        }
        return area;
    }
}
