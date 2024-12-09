class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums,
                                vector<vector<int>>& queries) {
        int n = nums.size();
        // pre-processing
        vector<int> cumulativeSum(n, 0);
        for (int i = 1; i < n; i++) {
            if (nums[i] % 2 == nums[i - 1] % 2) {
                cumulativeSum[i] = cumulativeSum[i - 1] + 1;
            } else {
                cumulativeSum[i] = cumulativeSum[i - 1];
            }
        }

        int m = queries.size();
        vector<bool> ans(m , false);
        int i=0 , start =0 , end =0;

        for (auto& que : queries) {
            // ans.push_back((cumulativeSum[que[1]] - cumulativeSum[que[0]] == 0)
            //                   ? true
            //                   : false);

            start = que[0];
            end = que[1];
            if(cumulativeSum[end]-cumulativeSum[start] == 0){
                ans[i]= true;
            }
            i++;
        }
        return ans;
    }
};