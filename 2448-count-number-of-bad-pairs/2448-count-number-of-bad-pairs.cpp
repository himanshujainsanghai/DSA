class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n = nums.size();
        vector<int> vis(nums.begin() , nums.end());
        for(int i=0 ; i<n ; i++){
            vis[i] = vis[i]-i;
        }

        unordered_map<int , int> mpp;
        mpp[vis[0]] = 1;
        long long ans = 0;
        for(int i=1 ; i<n ; i++){
            ans += i - mpp[vis[i]];
            mpp[vis[i]]++;
        }
        return ans;
        
    }
};