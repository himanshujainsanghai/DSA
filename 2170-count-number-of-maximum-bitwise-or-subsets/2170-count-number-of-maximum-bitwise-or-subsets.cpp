class Solution {
private:
    int func(int ind, int currOr, int maxOr, vector<int>& nums,
             vector<vector<int>>& dp) {
        if (ind < 0) {
            if (currOr == maxOr)
                return 1;
            return 0;
        }
        if (dp[ind][currOr] != -1) {
            return dp[ind][currOr];
        }

        int take = func(ind - 1, currOr | nums[ind], maxOr, nums, dp);
        int nottake = func(ind - 1, currOr, maxOr, nums, dp);
        return dp[ind][currOr] = take + nottake;
    }

public:
    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size();
        int maxOr = nums[0];
        for (int i = 1; i < n; i++) {
            maxOr = maxOr | nums[i];
        }
        // int maxOr = accumulate(nums.begin(), nums.end(), 0, bit_or<>());
        vector<vector<int>> dp(n + 1, vector<int>(maxOr + 1, -1));
        return func(n - 1, 0, maxOr, nums, dp);
    }
       
};