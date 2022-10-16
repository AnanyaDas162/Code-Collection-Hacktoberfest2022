class Solution {
    public List<List<Integer>> subsets(int[] nums) {
       List<List<Integer>> ll=new ArrayList();
       generate(nums,0,new ArrayList(),ll);
       return ll;
   }
   public void generate(int[] nums,int i,List<Integer> ls,List<List<Integer>> ll){
       if(i==nums.length){
           ll.add(new ArrayList(ls));
           return;
       }
       generate(nums,i+1,ls,ll);
       ls.add(nums[i]);
       generate(nums,i+1,ls,ll);
       ls.remove(ls.size()-1);
    }
       
