class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.size() <= 1) return true;

        int jumpsNeeded = 1; 

        for (int i = nums.size() - 2; i >= 0; --i) {
            if (nums[i] >= jumpsNeeded)  jumpsNeeded = 1; 
            else  jumpsNeeded++; 
        }
        return nums[0] >= jumpsNeeded; 
    }
};