class Solution {
    public String[] sortPeople(String[] names, int[] heights) {
        int i = 0 , j = 0 , k = 0 , l = 0 , m = 0 ;
    for(i = 0 ; i < heights.length - 1; i++)
    {
        for(j = i + 1 ; j < heights.length ; j++)
        {
            if(heights[i] < heights[j])
            {
                String t = names[i];
                names[i] = names[j];
                names[j] = t;
                k = heights[i];
                heights[i] = heights[j];
                heights[j] = k;
            }
        }
    }
return names;
    }
}
