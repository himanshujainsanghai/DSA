class Solution {
private:
    int solve(vector<int>& nums, int target, int index, int ans,
              vector<vector<int>>& dp, int offset) {
        if (index == nums.size()) {
            return ans == target ? 1 : 0;
        }

        if (dp[index][ans + offset] != -1) {
            return dp[index][ans + offset];
        }

        int include =
            solve(nums, target, index + 1, ans + nums[index], dp, offset);
        int exclude =
            solve(nums, target, index + 1, ans - nums[index], dp, offset);

        return dp[index][ans + offset] = include + exclude;
    }

public:
    int findTargetSumWays(vector<int>& nums, int target) {
        //     int n = nums.size();
        //     int sum = accumulate(nums.begin(), nums.end(), 0);
        //     int offset = sum; // offset to handle negative indices

        //     vector<vector<int>> dp(n, vector<int>(2 * sum + 1, -1)); // size
        //     adjusted for negative ans return solve(nums, target, 0, 0, dp,
        //     offset);
        // }

        // space optimization
        int n = nums.size();
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        if (abs(target) > totalSum || (totalSum - target) % 2 != 0)
            return 0;
        int targetSubsetSum = (totalSum - target) / 2;

        vector<int> prev(targetSubsetSum + 1, 0);
        vector<int> curr(targetSubsetSum + 1, 0);

        prev[0] = 1;
        curr[0] = 1;
        if (nums[0] <= targetSubsetSum)
            prev[nums[0]] = 1;
        if (nums[0] == 0)
            prev[0] = 2;

        for (int i = 1; i < n; i++) {
            for (int t = 0; t <= targetSubsetSum; t++) {
                int notTake = prev[t];
                int take = 0;
                if (nums[i] <= t) {
                    take = prev[t - nums[i]];
                }

                curr[t] = (notTake + take);
            }
            prev = curr;
        }

        return prev[targetSubsetSum];
    }
};