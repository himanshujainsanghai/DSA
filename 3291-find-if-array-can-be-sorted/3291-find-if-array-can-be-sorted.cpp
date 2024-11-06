class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int n = nums.size();


        // for(int i=0 ; i<n ; i++){
        //     bool flag = false;

        //     for(int j=0 ; j<n-i-1 ; j++){

        //         if(nums[j] <= nums[j+1]){
        //             // no swap needed
        //             continue;
        //         }
        //         else{
        //             // nums[j]>nums[j+1]
        //             if(__builtin_popcount(nums[j]) == __builtin_popcount(nums[j+1])){
        //                 swap(nums[j] , nums[j+1]);
        //                 flag = true;
        //             }
        //             else{
        //                 // they cannot be swapped -->cant be sorted
        //                 return false;

        //             }
        //         }


        //         if(flag == false){
        //             break;
        //         }
        //     }
        // }


        // APPROACH-2i
        int mini=nums[0];
        int maxi=nums[0];
        int maxprev = 0;

        for(int i=1 ; i<n ; i++){
            if(__builtin_popcount(nums[i]) == __builtin_popcount(nums[i-1])){
                mini = min(nums[i] , mini);
                maxi = max(nums[i] , maxi);
            }
            else{
                if(mini < maxprev){
                    return false;
                }

                maxprev = maxi;
                maxi = nums[i];
                mini = nums[i];

            }

        }
        if (mini < maxprev) {
            return false;
        }

        return true;
        
    }
};