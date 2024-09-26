class Solution {
public:
    // int minimumMountainRemovals(vector<int>& nums) {
    // int n = nums.size();
    // if (n < 3) return 0;  // No bitonic sequence can exist if there are fewer
    // than 3 elements

    // // dp1 stores the longest increasing subsequence ending at each index
    // vector<int> dp1(n, 1);

    // // Calculate the longest increasing subsequence (LIS) for each index
    // for (int ind = 0; ind < n; ind++) {
    //     for (int prevind = 0; prevind < ind; prevind++) {
    //         if (nums[prevind] < nums[ind] && 1 + dp1[prevind] > dp1[ind]) {
    //             dp1[ind] = 1 + dp1[prevind];
    //         }
    //     }
    // }

    // // dp2 stores the longest decreasing subsequence starting at each index
    // vector<int> dp2(n, 1);

    // // Calculate the longest decreasing subsequence (LDS) for each index
    // for (int ind = n - 2; ind >= 0; ind--) {
    //     for (int nextind = n - 1; nextind > ind; nextind--) {
    //         if (nums[nextind] < nums[ind] && 1 + dp2[nextind] > dp2[ind]) {
    //             dp2[ind] = 1 + dp2[nextind];
    //         }
    //     }
    // }

    // // Combine LIS and LDS to find the longest bitonic sequence
    // int maxi = 0;
    // for (int i = 0; i < n; i++) {
    //     maxi = max(maxi, dp1[i] + dp2[i] - 1);
    // }

    // return n-maxi;

    // }
    //     int minimumMountainRemovals(vector<int>& nums) {
    //     int n = nums.size();
    //     // Step 2: Calculate LDS starting at each index
    //     vector<int> lds(n, 1);
    //     for (int i = n - 2; i >= 0; i--) {
    //         for (int j = n - 1; j > i; j--) {
    //             if (nums[i] > nums[j] && lds[i] < lds[j] + 1) {
    //                 lds[i] = lds[j] + 1;
    //             }
    //         }
    //     }

    //     // Step 1: Calculate LIS ending at each index
    //     int maxMountain = 0;
    //     vector<int> lis(n, 1);
    //     for (int i = 1; i < n; i++) {
    //         for (int j = 0; j < i; j++) {
    //             if (nums[i] > nums[j] && lis[i] < lis[j] + 1) {
    //                 lis[i] = lis[j] + 1;
    //             }
    //         }
    //         if (lis[i] > 1 && lds[i] > 1) {  // Check if it's a valid peak
    //             maxMountain = max(maxMountain, lis[i] + lds[i] - 1);
    //         }
    //     }

    //     // Step 3: Find the longest valid mountain array
    //     // for (int i = 1; i < n - 1; i++) {
    //     // }

    //     // Step 4: The minimum number of elements to remove is the total size
    //     minus the longest mountain return n - maxMountain;
    // }
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();

        // Step 2: Calculate LDS using binary search (Patience Sorting)
        vector<int> lds(n, 1);
        vector<int> decreasing;
        for (int i = n - 1; i >= 0; i--) {
            auto it =
                lower_bound(decreasing.begin(), decreasing.end(), nums[i]);
            if (it == decreasing.end()) {
                decreasing.push_back(nums[i]);
            } else {
                *it = nums[i];
            }
            lds[i] = decreasing.size();
        }
        // Step 1: Calculate LIS using binary search (Patience Sorting)
        vector<int> lis(n, 1);
        int maxMountain = 0;
        vector<int> increasing;
        for (int i = 0; i < n; i++) {
            auto it =
                lower_bound(increasing.begin(), increasing.end(), nums[i]);
            if (it == increasing.end()) {
                increasing.push_back(nums[i]);
            } else {
                *it = nums[i];
            }
            lis[i] = increasing.size();

            if (lis[i] > 1 && lds[i] > 1) {
                maxMountain = max(maxMountain, lis[i] + lds[i] - 1);
            }


        }


        // Step 3: Find the maximum valid mountain array
        // for (int i = 1; i < n - 1; i++) {
        // }

        // Step 4: The minimum number of elements to remove is the total size
        // minus the longest mountain
        return n - maxMountain;
    }
    };