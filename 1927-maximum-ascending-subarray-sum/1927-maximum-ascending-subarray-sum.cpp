class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> vis(nums.begin() , nums.end());
        int ans = vis[0];
        for(int i=0 ; i<n-1 ; i++){
            if(nums[i] < nums[i+1]){
                vis[i+1] += vis[i];
                ans = max(vis[i+1] , ans);

            }
            else{
                continue;
            }
        }
        return ans;

        
    }
};