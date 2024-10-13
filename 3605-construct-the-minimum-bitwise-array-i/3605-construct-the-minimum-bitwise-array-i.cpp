class Solution {
    private:
    int func(int num){
        int x =0;
        for(int i=1 ; i<num ; i++){
            if((i | i+1 )== num){
                return i;
            }
        }
        return -1;
    }
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n , -1);
        for(int i =0 ; i<n ; i++){
            ans[i] = func(nums[i]);
        }


        return ans;
    }
};