
 class LongestStringChain {

	 public int longestStrChain(String[] words) {
	        if(words == null || words.length == 0) {
	            return 0;
	        }
	        Arrays.sort(words, (a,b) -> a.length() - b.length());
	        Map<String, Integer> map = new HashMap();
	        int max = 0;
	        for(String word: words) {
	            int longestSubstring = 0;
	            for(int i = 0; i < word.length(); i++) {
	                String subWord = word.substring(0, i) + word.substring(i+1);
	                longestSubstring = Math.max(longestSubstring, map.getOrDefault(subWord, 0) + 1);
	            }
	            map.put(word, longestSubstring);
	            max = Math.max(max, longestSubstring);
	        }
	        return max;
	    }

}
