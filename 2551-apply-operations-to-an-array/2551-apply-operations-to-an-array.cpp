class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n , 0);
        int j=0;
        for(int i=0 ; i<n ; i++){
            if(nums[i]== 0) continue;
            else if(i<n-1 && nums[i] == nums[i+1]){
                nums[i+1] = 0;
                ans[j] = 2*nums[i];

            }else{
                ans[j] = nums[i];
            }
            j++;
        }
        
        return ans;
    }
};