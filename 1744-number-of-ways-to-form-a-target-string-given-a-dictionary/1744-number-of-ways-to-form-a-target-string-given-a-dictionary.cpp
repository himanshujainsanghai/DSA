class Solution {
private:
    long func(int wordInd, int targetInd, int wordLen, string target,
              vector<vector<int>> colFreq, vector<vector<int>>& dp) {
        // base cases
        if (targetInd == target.size()) {
            dp[wordInd][targetInd] = 1;
            return 1;
        }
        if (wordInd == wordLen) {
            dp[wordInd][targetInd] = 0;
            return 0;
        }
        // pruning
        if ((target.size() - targetInd) > (wordLen - wordInd)) {
            dp[wordInd][targetInd] = 0;
            return 0;
        }

        if (dp[wordInd][targetInd] != -1) {
            return dp[wordInd][targetInd];
        }

        int charInd = target[targetInd] - 'a';
        int freq = colFreq[wordInd][charInd];

        // pick
        long pick = freq * func(wordInd + 1, targetInd + 1, wordLen, target,
                                colFreq, dp);
        long notpick =
            func(wordInd + 1, targetInd, wordLen, target, colFreq, dp);
        long ans = (pick + notpick) % 1000000007;
        return dp[wordInd][targetInd] = ans;
    }

public:
    int numWays(vector<string>& words, string target) {
        int wordLen = words[0].size();
        int targetLen = target.size();

        // populate frequency for each word per column
        vector<vector<int>> colFreq(wordLen, vector<int>(26, 0));
        for (int i = 0; i < wordLen; i++) {
            for (int j = 0; j < words.size(); j++) {
                int charIndx = words[j][i] - 'a';
                colFreq[i][charIndx]++;
            }
        }

        // for memoization
        // vector<vector<int>> dp(wordLen+1  , vector<int>(targetLen +1 , -1));
        // return (int)func(0 , 0 , wordLen , target , colFreq , dp);

        // TLE even on memoization
        // vector<vector<int>> dp(wordLen + 1, vector<int>(targetLen + 1, 0));
        // for (int i = 0; i <= wordLen; i++) {
        //     dp[i][targetLen] = 1;
        // }

        // for (int wordInd = wordLen - 1; wordInd >= 0; wordInd--) {

        //     for (int targetInd = targetLen - 1; targetInd >= 0; targetInd--)
        //     {
        //         // pruning
        //         if ((target.size() - targetInd) > (wordLen - wordInd)) {
        //             dp[wordInd][targetInd] = 0;
        //             continue;
        //         }
        //         int charInd = target[targetInd] - 'a';
        //         int freq = colFreq[wordInd][charInd];

        //         // pick
        //         long pick =
        //             (long(freq) * dp[wordInd + 1][targetInd + 1]) %
        //             1000000007;
        //         long notpick = dp[wordInd + 1][targetInd];
        //         long ans = (pick + notpick) % 1000000007;
        //         dp[wordInd][targetInd] = (int)ans;
        //     }
        // }

        // space optimization
        vector<int> prev(targetLen +1 , 0);
        prev[targetLen] =1;
        for (int wordInd = wordLen - 1; wordInd >= 0; wordInd--) {

            vector<int> curr(targetLen+1 , 0);
            curr[targetLen] = 1;

            for (int targetInd = targetLen - 1; targetInd >= 0; targetInd--)
            {
                // pruning
                if ((target.size() - targetInd) > (wordLen - wordInd)) {
                    curr[targetInd] = 0;
                    continue;
                }
                int charInd = target[targetInd] - 'a';
                int freq = colFreq[wordInd][charInd];

                // pick
                long pick =
                    (long(freq) * prev[targetInd + 1]) % 1000000007;
                long notpick = prev[targetInd];
                long ans = (pick + notpick) % 1000000007;
                curr[targetInd] = (int)ans;
            }

            prev = curr;
        }

        return prev[0];
    }
};