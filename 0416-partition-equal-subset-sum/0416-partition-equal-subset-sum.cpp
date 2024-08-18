// class Solution {
// private:
// bool isSubsetSum(vector<int>& arr, int sum , int n){
//         vector<bool> prev(sum+1 , 0) , curr(sum+1 , 0);
//         prev[0] = curr[0] = true;
//         // prev[arr[0]] = true;
//         if (arr[0] <= sum) {
//             prev[arr[0]] = true;
//         }
//         for(int ind = 1 ; ind<n ; ind++){
//             for(int target = 1; target<=sum ; target++){
//             bool nottake = prev[ target ];
//             bool take = false;
//             if(target >= arr[ind]) take = prev[target-arr[ind]];
//             curr[target] = nottake || take;
//             }
//             prev = curr;
//         }
        
        
//         return prev[sum];
    
//     }
// public:
//     bool canPartition(vector<int>& arr) {
//         int n = arr.size();
//         int totalsum = 0;
//         for(int i = 0 ; i<n ; i++) totalsum += arr[i];
//         if(totalsum % 2) return false;
//         int target = totalsum /2;
//         return isSubsetSum(arr , target , n);
        
//     }
// };
#include <unordered_set>
#include <numeric>

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        /*
        - can we partition the array into two subsets that have equal sums
        - sum(arr1) = sum(arr2)
        - sum(arr1) + sum(arr2) = total
        - sum(arr1) = sum(arr2) = total / 2
        - if we can find a subset that sums to half, then we know another subset sums to half
        */
        int totalSum = accumulate(begin(nums), end(nums), 0), halfSum = totalSum / 2;
        if(totalSum & 1) return false;
        bitset<10001> dp(1);       // 0 is always achievable => dp[0] = 1
        for(int num : nums) 
            dp = dp | dp << num;
        return dp[halfSum];
    }
};