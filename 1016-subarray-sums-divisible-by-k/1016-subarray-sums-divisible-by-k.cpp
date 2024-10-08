class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        int prefsum = 0 , ans =0;
        // unordered_map<int, int> mpp;
        // we can use vector also to optimize SC
        vector<int> mpp(k , 0);
        mpp[0]=1;
        for(int i =0 ; i<n ; i++){
            prefsum = (prefsum + nums[i]%k +k)%k;
            ans += mpp[prefsum];
            mpp[prefsum]++;
        }
        return ans;
        
    }
};