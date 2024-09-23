class Solution {
private:
    int func(int ind, int prevind, vector<int>& nums, int n,
             vector<vector<int>>& dp) {
        if (ind == n)
            return 0;
        if (dp[ind][prevind + 1] != -1)
            return dp[ind][prevind + 1];
        int len = func(ind + 1, prevind, nums, n, dp);
        if (prevind == -1 || nums[ind] > nums[prevind]) {
            len = max(len, 1 + func(ind + 1, ind, nums, n, dp));
        }
        return dp[ind][prevind + 1] = len;
    }

public:
    int lengthOfLIS(vector<int>& nums) {

        int n = nums.size();
        // vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        // return func(0 , -1 , nums , n , dp);
        // vector<int> next(n+1 ,0) , curr(n+1 ,0);
        // for (int ind = n - 1; ind >= 0; ind--) {
        //     for (int prevind = ind - 1; prevind >= -1; prevind--) {
        //         int len = next[ prevind+1];
        //         if (prevind == -1 || nums[ind] > nums[prevind]) {
        //             len = max(len, 1 + next[ind+1]);
        //         }
        //         curr[prevind + 1] = len;
        //     }
        //     next = curr;
        // }
        // return next[-1+1];

        // MORE OPTIMISED SOLUTION-->
        // vector<int> dp(n + 1, 1);
        // int maxi = 0;
        // for (int ind = 0; ind < n; ind++) {
        //     for (int prevind = 0; prevind < ind; prevind++) {
        //         if (nums[prevind] < nums[ind]) {
        //             dp[ind] = max(dp[ind], 1 + dp[prevind]);
        //         }
        //     }
        //     maxi = max(maxi, dp[ind]);
        // }
        // return maxi;

        // GREEDY APPROACH-->
        vector<int> ans;
        ans.push_back(nums[0]);

        for(int i=0;i<n;i++) {
            if (ans.back() < nums[i]) {
                ans.push_back(nums[i]);
            } else {
                int index = lower_bound(ans.begin(), ans.end(), nums[i]) - ans.begin();
                ans[index] = nums[i];
            }
        }

        return ans.size();
    }
};