class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.size() <= 1) return true;

        // int jumpsNeeded = 1; 

        // for (int i = nums.size() - 2; i >= 0; --i) {
        //     if (nums[i] >= jumpsNeeded)  jumpsNeeded = 1; 
        //     else  jumpsNeeded++; 
        // }
        // return nums[0] >= jumpsNeeded; 
        int maxIndex =0  ;

        for(int i =0 ; i<nums.size() ; i++){
            if(i > maxIndex) return false;
            maxIndex = max(maxIndex , i+nums[i]);
            if(maxIndex > nums.size()) return true;
        }
        return true;
    }
};