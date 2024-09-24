class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        int n = nums.size();
        vector<int> dp(n + 1, 1), hash(n);
        int maxi = 0;
        int lastIndex = 0;
        for (int ind = 1; ind < n; ind++) {
            hash[ind] = ind;
            for (int prevind = 0; prevind < ind; prevind++) {
                if (nums[ind] % nums[prevind] == 0 && 1+dp[prevind] > dp[ind]) {
                    dp[ind] = 1 + dp[prevind];
                    hash[ind] = prevind;
                }
            }
            if (dp[ind] > maxi) {
                maxi = dp[ind];
                lastIndex = ind;
            }
        }
        vector<int> temp;
        temp.push_back(nums[lastIndex]);
        while (hash[lastIndex] != lastIndex) {
            lastIndex = hash[lastIndex];
            temp.push_back(nums[lastIndex]);
        }
        // reverse(temp.begin(), temp.end());
        return temp;

    }
};