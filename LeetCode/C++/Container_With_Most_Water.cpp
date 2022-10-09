int maxArea(vector<int>& height) {
         int area_water = 0;   //variable to store max amount of water
         int i = 0;  // to point to first element
         int j = height.size() - 1; //to point to last element
 while (i < j) {
        
     int h = min(height[i], height[j]); // the lower height would be considered for cal area of water
        
 area_water = max(area_water, (j - i) * h); //cal current area with max area, area refers to quantity of water in rectangle  container
 while (height[i] <= h && i < j) i++; //if height of next element is less then its area would be less so no point in considering it so we move on to next element
 while (height[j] <= h && i < j) j--; // if height of prev(or next while iterating backwards) element is less then its area  would be less so no point in considering it so we move on to next previous element(iterating backwards)
        
                 }
    return area_water; //max area of water in container or max amount
    }
