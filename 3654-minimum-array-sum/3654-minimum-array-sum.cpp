// class Solution {

//     private:
//     int func(vector<int>& nums , int k , int i , int op1 , int op2 , vector<vector<vector<int>>>& dp){
//         if(i==nums.size()){
//             return 0;
//         }
//         int result = INT_MAX;

//         if(dp[i][op1][op2] != -1){
//             return dp[i][op1][op2];
//         }

//         if(op1>0){
//             int val = (nums[i]+1)/2; //ceil(nums[i]/2.0)
//             int ans = val + func(nums , k , i+1 , op1-1 , op2 , dp);
//             result = min(result , ans);
//         }

//         if(op2>0 && nums[i]>=k){
//             int val = nums[i]-k;
//             int ans = val + func(nums , k , i+1 , op1 , op2-1 ,  dp);
//             result = min(result , ans);
//         }

//         if(op1>0 && op2>0){
//             // op1->op2
//             int val = (nums[i]+1)/2;
//             if(val>=k){
//                 int val2 = val-k;
//                 int ans = val2 + func(nums , k , i+1 , op1-1 , op2-1 , dp);
//                 result = min(result , ans);
//             }


//             if(nums[i]>=k){
//                 int val = nums[i]-k;
//                 int val2 = (val+1)/2;
//                 int ans = val2 + func(nums , k , i+1 , op1-1 , op2-1 , dp);
//                 result = min(result , ans);
//             }
//         }

//         int ans = nums[i] + func(nums , k , i+1 , op1 , op2 , dp);

//         result = min(result , ans);

//         return dp[i][op1][op2] = result;

//     }
// public:
//     int minArraySum(vector<int>& nums, int k, int op1, int op2) {
//         int n = nums.size();
//     vector<vector<vector<int>>> dp(101 ,  vector<vector<int>>(101  , vector<int>(101 , -1)));


//         return func(nums , k , 0 , op1 , op2 , dp);
        
//     }
// };
class Solution {
public:
    int minArraySum(vector<int>& nums, int k, int op1, int op2) {
        int s = 0;
        for (int x : nums) {
            s += x;
        }
        vector<vector<int>> dp(op1 + 1, vector<int>(op2 + 1, s));
        for (int x : nums) {
            const int y = (x + 1) >> 1;
            for (int i = op1; i >= 0; --i) {
                for (int j = op2; j >= !i; --j) {
                    if (i) {
                        dp[i][j] = min(dp[i][j], dp[i - 1][j] - (x >> 1));
                    }
                    if (x >= k && j) {
                        dp[i][j] = min(dp[i][j], dp[i][j - 1] - k);
                    }
                    if (i && j) {
                        if (y >= k) {
                            dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] - (x >> 1) - k);
                        }
                        if (x >= k) {
                            dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] - x + ((x - k + 1) >> 1));
                        }
                    }
                }
            }
        }
        return dp[op1][op2];
    }
};