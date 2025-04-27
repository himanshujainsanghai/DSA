class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        for(int i=1 ; i<=n-2 ; i++){
            if(nums[i] == (nums[i-1]+nums[i+1])*2){
                count++;
            }
        }
        return count;
    }
};