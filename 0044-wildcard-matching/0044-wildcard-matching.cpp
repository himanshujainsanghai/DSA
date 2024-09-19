class Solution {
private:
    bool func(int i, int j, string s, string p, vector<vector<int>>& dp) {
        if (i == 0 && j == 0)
            return true;
        if (i == 0 && j > 0)
            return false;
        if (j == 0 && i > 0) {
            for (int c = 1; c <= i; c++) {
                if (p[c - 1] != '*')
                    return false;
            }
            return true;
        }
        if (dp[i][j] != -1)
            return dp[i][j];
        if (p[i - 1] == s[j - 1] || p[i - 1] == '?')
            return dp[i][j] = func(i - 1, j - 1, s, p, dp);
        if (p[i - 1] == '*')
            return dp[i][j] =
                       func(i - 1, j, s, p, dp) || func(i, j - 1, s, p, dp);
        return dp[i][j] = false;
    }

public:
    bool isMatch(string s, string p) {
        int n = p.size();
        int m = s.size();
        // vector<vector<int>> dp(n+1 , vector<int>(m+1 , -1));
        // return func(n ,m , s,p , dp);
        // vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
        vector<bool> prev(m + 1, false), curr(m + 1, false);
        prev[0] = true;
        // for(int j =1 ; j<=m ; j++) dp[0][j] = false;
        // for (int i = 1; i <= n; i++) {
        //     bool flag = true;
        //     for (int c = 1; c <= i; c++) {
        //         if (p[c - 1] != '*') {
        //             flag = false;
        //             break;
        //         }
        //     }
        //     dp[i][0] = flag;
        // }
        for (int i = 1; i <= n; i++) {
            bool flag = true;
            for (int c = 1; c <= i; c++) {
                if (p[c - 1] != '*') {
                    flag = false;
                    break;
                }
            }
            curr[0] = flag;
            for (int j = 1; j <= m; j++) {
                if (p[i - 1] == s[j - 1] || p[i - 1] == '?')
                    curr[j] = prev[j - 1];
                else if (p[i - 1] == '*')
                    curr[j] = prev[j] || curr[j - 1];
                else
                    curr[j] = false;
            }
            prev = curr;
        }
        return prev[m];
    }
};