class Solution
{
    public int[] maxSlidingWindow(int[] nums, int k)
    {
        int i,l,r;
        int[] res=new int[nums.length-k+1];
        PriorityQueue<Pair<Integer, Integer>> maxHeap=new PriorityQueue<>((a,b) -> b.getValue()-a.getValue());
        for(i=0;i<k-1;i++)
            maxHeap.add(new Pair<>(i,nums[i]));
        for(l=0,r=k-1;r<=nums.length-1;l++,r++)
        {
            maxHeap.add(new Pair<>(r,nums[r]));
            while(maxHeap.peek().getKey()<l || maxHeap.peek().getKey()>r)
                maxHeap.poll();
            res[l]=maxHeap.peek().getValue();
        }
        
        return res;
    }
}