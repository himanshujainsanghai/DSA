class Solution {
private:
    int func(int i, int j, string s1, string s2, vector<vector<int>>& dp) {
        if (i == 0)
            return j;
        if (j == 0)
            return i;
        if (dp[i][j] != -1)
            return dp[i][j];
        if (s1[i - 1] == s2[j - 1])
            return dp[i][j] = func(i - 1, j - 1, s1, s2, dp);
        int insert = 1 + func(i - 1, j, s1, s2, dp);
        int del = 1 + func(i, j - 1, s1, s2, dp);
        int rep = 1 + func(i - 1, j - 1, s1, s2, dp);
        return dp[i][j] = min(insert, min(del, rep));
    }

public:
    int minDistance(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        // vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        // return func(n , m , s1 , s2 , dp);
        vector<int> prev(m+1 ,0) , curr(m+1 ,0);
        for (int j = 0; j <= m; j++)
            prev[j] = j;
        // for (int i = 0; i <= n; i++)
        //     dp[i][0] = i;
        for (int i = 1; i <= n; i++) {
            curr[0] = i;
            for (int j = 1; j <= m; j++) {
                if (s1[i - 1] == s2[j - 1])
                    curr[j] = prev[j - 1];
                else {
                    int insert = 1 + prev[ j];
                    int del = 1 + curr[ j - 1];
                    int rep = 1 + prev[ j - 1];
                    curr[j] = min(insert, min(del, rep));
                }
            }
            prev = curr;
        }
        return prev[m];
    }
};