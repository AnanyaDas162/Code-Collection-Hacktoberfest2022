class Solution {
public:
    bool isMatch(string s, string p) {
        int N = s.length();
        int M = p.length();
        bool dp[N + 1][M + 1];
        for(int n = 0; n <= N; n++) {
            for(int m = 0; m <= M; m++) {
                if (m == 0 && n == 0)
                    dp[n][m] = true;
                else if (m == 0)
                    dp[n][m] = false;
                else if (n == 0){
                    if (p[m - 1] == '*')
                        dp[n][m] = dp[n][m - 1];
                    else
                        dp[n][m] = false;
                }
                else if (p[m - 1] == '*')
                    dp[n][m] = dp[n - 1][m - 1] | dp[n][m - 1] | dp[n - 1][m];
                else if (p[m - 1] == '?')
                    dp[n][m] = dp[n - 1][m - 1];
                else if (s[n - 1] != p[m - 1])
                    dp[n][m] = false;
                else
                    dp[n][m] = dp[n - 1][m - 1];
            }
        }
        return dp[N][M];
    }
};
