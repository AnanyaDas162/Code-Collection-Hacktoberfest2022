class Solution {
    public boolean isInterleave(String s1, String s2, String s3) {
        if (s1.length() + s2.length() != s3.length())
            return false;
        return dfs(s1, 0, s2, 0, s3, 0, new boolean[s1.length()][s2.length()]);
    }

    private boolean dfs(String s1, int index1, String s2, int index2, String s3, int index3, boolean[][] visited) {
        if (index3 == s3.length())
            return true;
        if (index1 == s1.length())
            return s3.substring(index3).equals(s2.substring(index2));
        if (index2 == s2.length())
            return s3.substring(index3).equals(s1.substring(index1));
        if (visited[index1][index2])
            return false;
        boolean res = false;
        if (s1.charAt(index1) == s3.charAt(index3))
            res = dfs(s1, index1 + 1, s2, index2, s3, index3 + 1, visited);
        if (s2.charAt(index2) == s3.charAt(index3))
            res = res || dfs(s1, index1, s2, index2 + 1, s3, index3 + 1, visited);
        visited[index1][index2] = true;
        return res;
    }
}