class LongestPalindromicSubsequenceTopDownDPSolution {
    public int longestPalindromeSubseq(String s) {

        //Length of string
        int n = s.length();

        //Map to store results
        Map<String, Integer> map = new HashMap<String, Integer>();

        return lpsUtil(s, 0, n-1, map);
    }

    private static int lpsUtil(String s, int i, int j, Map<String, Integer> map) {

        //If length of relevant string is 1 => return 1 since that is already
        // a palindrome
        if(i==j) return 1;

        //If length is 2 => if both characters are same, then answer will be 2 but
        //if they are different => answer will be 1
        if(j-i == 1) {
            if(s.charAt(i) == s.charAt(j)) {
                return 2;
            } else {
                return 1;
            }
        }

        int answer, candidateAnswer1, candidateAnswer2;

        String key = buildKey(i, j);

        //If we have encountered this input before => we must have stored its result
        //in map => return directly from map.
        if(map.containsKey(key)) {
            return map.get(key);
        }

        //Character at i
        char ch1 = s.charAt(i);

        //Character at j
        char ch2 = s.charAt(j);

        //If the two are equal => length of LPS will be length of LPS for middle
        //portion + 2
        if(ch1 == ch2) {
            answer = lpsUtil(s, i+1, j-1, map) + 2;
            //Put the answer in map.
            map.put(key, answer);
            return answer;
        }
        else {
            //LPS of string except last character
            candidateAnswer1 = lpsUtil(s, i, j-1, map);
            //LPS of string except first character
            candidateAnswer2 = lpsUtil(s, i+1, j, map);
            answer = Math.max(candidateAnswer1, candidateAnswer2);
            //Put answer in map
            map.put(key, answer);
            return answer;
        }
    }

    private static String buildKey(int i, int j) {
        return (String.valueOf(i) + "_" + String.valueOf(j));
    }
}
