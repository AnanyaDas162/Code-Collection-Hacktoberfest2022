
class KClosestElements {

	 public List<Integer> findClosestElements(int[] arr, int k, int x) {
	        int xIndex = findElement(arr, x);

	        int lowerBound = xIndex - k < 0 ? 0 : xIndex - k;
	        int upperBound = xIndex + k > arr.length - 1 ? arr.length - 1 : xIndex + k;
	    
	        while(lowerBound + k <= upperBound) {
	            if(Math.abs(arr[lowerBound] - x) <= Math.abs(arr[upperBound] - x)) {
	                upperBound--;
	            } else {
	                lowerBound++;
	            }
	        }
	        
	        List<Integer> result = new LinkedList<Integer>();
	        for (int i = lowerBound; i <= upperBound; i++) {
	            result.add(arr[i]);
	        }
	        
	        return result;
	    }
	    
	    public int findElement(int[] arr, int target) {
	        int left = 0;
	        int right = arr.length - 1;
	        
	        while(left + 1 < right) {
	            int mid = left + (right - left) /2;
	            
	            if(arr[mid] == target) {
	                return mid;
	            } else if(arr[mid] > target) {
	                right = mid;
	            } else {
	                left = mid;
	            }
	        }
	        
	        if (Math.abs(arr[left] - target) > Math.abs(arr[right] - target)){
	            return right;
	        } else {
	            return left;
	        }
	    }
	}


