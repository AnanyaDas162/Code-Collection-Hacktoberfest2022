class Solution {
    public boolean isValid(String s) {
       
        Stack<Character> stack = new Stack();
        
        for(char c : s.toCharArray()){
            if(c=='(' || c=='{' || c=='[')  stack.add(c);
            else{
                if(stack.isEmpty())  return false;
                if(c==']' && stack.peek() != '[') return false;
                if(c==')' && stack.peek() != '(') return false;
                if(c=='}' && stack.peek() != '{') return false;
                
                stack.pop();
            }
            
        }
        
       return stack .isEmpty();
        
        
    }
}
