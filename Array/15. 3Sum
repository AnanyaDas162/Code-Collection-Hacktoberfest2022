class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
     //first if we sort thae array nlogn
        //-4,-1,-1,0,1,2
        //for k=-4 
        //for(k==-1)
        //since only unnique pairs are allowed we first take a number then find all possbile numbser that satify condition and simulteneously skipping the duplicates i and j and since we have found all possible distainct tuples next time this number is observed again we tatally skip it 
        //whose paits have been found.
        int n= nums.length;
    
        List<List<Integer>> list= new ArrayList<List<Integer>>();
       HashSet<Integer> set= new HashSet<Integer>();
        Arrays.sort(nums);
        for(int i=0;i<n-2;i++){
           
            if(i>0 && (nums[i]==nums[i-1] ) ){
                continue;
            }
            pair(i,nums, list);
        }
        
        
        
        return list;
    }
    
    public  void pair(int k, int[] nums, List<List<Integer>> list){
        //a is index
        int i=k+1;
        int j=nums.length-1;
        int a=nums[k];
        while(i<j){
            int b= nums[i]+nums[j];
            //0 is target
            if(a+b>0 ){//means a ia bigger
                j--;
            }
           else if(a+b<0){
                i++;
            }
           else if(a+b==0){
                ArrayList<Integer> al= new ArrayList<Integer>();
                al.add(nums[k]);
                al.add(nums[i]);
                al.add(nums[j]);
                list.add(al);
                i++;         
                j--;
               while(i<j && nums[i]==nums[i-1]){i++;}
               while(i<j && nums[j]==nums[j+1]){j--;}
            }
        }
        
    }
    
    
    
}
