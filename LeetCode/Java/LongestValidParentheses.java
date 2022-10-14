

 class LongestValidParentheses {
	 class Solution {
		    public int longestValidParentheses(String s) {
		        Stack<Integer> stack = new Stack();
		        stack.push(-1);
		        
		        int maxLen = 0;
		        
		        for(int i = 0; i < s.length(); i++){
		            if(s.charAt(i) == '('){ //opening bracket
		                
		                stack.push(i);
		            }else if(s.charAt(i) == ')'){ //closing bracket
		                
		                stack.pop();
		                if(stack.empty()){
		                    //reset
		                    stack.push(i);
		                }else{
		                    //update maxLen
		                    maxLen = Math.max(maxLen, i - stack.peek());
		                }
		                    
		            }
		        }
		        
		        return maxLen;
		    }


}
