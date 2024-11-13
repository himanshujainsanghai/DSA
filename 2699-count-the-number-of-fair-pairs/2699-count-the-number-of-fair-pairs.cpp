class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        ios::sync_with_stdio(false); // Disable synchronization with C I/O
        cin.tie(NULL);               // Untie cin from cout
        cout.tie(NULL);
        int n = nums.size();
        sort(begin(nums), end(nums));

        long long res = 0;

        for (int i = 0; i < n; i++) {
            int indx =
                lower_bound(nums.begin() + i + 1, nums.end(), lower - nums[i]) -
                nums.begin(); // returns the index of element not less than
                              // (lower-nums[i]);
            // int x = indx - i - 1;
            int x = indx;

            indx =
                upper_bound(nums.begin() + i + 1, nums.end(), upper - nums[i]) -
                nums.begin(); // returns the index of element greater than
                              // (lower-nums[i]);

            // int y = indx - i - 1;

            // res += (y - x);
            res += (indx - x);
        }

        return res;
    }
};