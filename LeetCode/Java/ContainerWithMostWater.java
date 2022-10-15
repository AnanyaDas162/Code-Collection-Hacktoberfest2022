

class ContainerWithMostWater {
	 public int maxArea(int[] height) {
	        int l=0;
	        int h=height.length-1;
	        
	        int max=0;
	        
	        while(l<h){
	            int lh=height[l];
	            int rh=height[h];
	            int min_h=Math.min(lh,rh);
	            max=Math.max(max,min_h*(h-l));
	        
	            if(min_h==lh)
	                l++;
	            else
	                h--;
	        }
	        return max;
	        
	    }
}
