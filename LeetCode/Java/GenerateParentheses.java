
 class GenerateParentheses {
	 class Solution {
		    public List<String> generateParenthesis(int n) {
		        List<String> combs = new ArrayList<>();
		        generate(n, n, new StringBuilder(), combs);
		        return combs;
		    }
		    
		    public void generate(int open, int close, StringBuilder sb, List<String> combs){
		        if(open == 0 && close == 0){
		            combs.add(sb.toString());
		            return;
		        }
		        if(open > 0){
		            sb.append("(");
		            generate(open - 1, close, sb, combs);
		            sb.delete(sb.length() - 1, sb.length());
		        }
		        
		        if(close > 0 && open < close){
		            sb.append(")");
		            generate(open, close - 1, sb, combs);
		            sb.delete(sb.length() - 1, sb.length());
		        }
		    }
}
