class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        ios::sync_with_stdio(false); // Disable synchronization with C I/O
        cin.tie(NULL);               // Untie cin from cout
        cout.tie(NULL);              // Untie cout from any tied streams
        int sum = 0;
        int maxi =
            nums[0]; // to store the maximum value of sum in the iteration
        for (auto it : nums) {
            sum += it;
            maxi = max(sum, maxi);
            if (sum < 0)
                sum = 0;
        }
        return maxi;
    }
};