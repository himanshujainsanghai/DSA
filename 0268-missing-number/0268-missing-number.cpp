class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();

        int curr = 0;
        for(auto &it:nums){
            curr += it;
        }


        int total = n*(n+1)/2;
        return total-curr;
    }
};