class Solution {
    public String longestPalindrome(String s) {
        if (s.length() == 0) {
            return s;
        }
        int n = s.length();
        boolean table[][] = new boolean[n][n];
        int maxLength = 1;
        for (int i = 0; i < n; ++i) {
            table[i][i] = true;
        }
        int start = 0;
        for (int i = 0; i < n - 1; i++) {
            if (s.charAt(i) == s.charAt(i + 1)) {
                table[i][i + 1] = true;
                start = i;
                maxLength = 2;
            }
        }
        for (int length = 3; length <= n; length++) {
            for (int i = 0; i < n - length + 1; i++) {
                int j = i + length - 1;
                if (table[i + 1][j - 1] == true && s.charAt(i) == s.charAt(j)) {
                    table[i][j] = true;
                    if (length > maxLength) {
                        maxLength = length;
                        start = i;
                    }
                }
            }
        }
        return s.substring(start, start + maxLength);
    }
}