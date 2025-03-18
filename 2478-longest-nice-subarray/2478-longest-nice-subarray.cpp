class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();

        // TC = O(n*n);
        // int ans = 1;
        // for(int i=0 ; i<n ; i++){
        //    int mask = 0;
        //    for(int j=i ; j<n ; j++){
        //         if((nums[j] & mask) != 0){
        //             break;
        //         }
        //         ans = max(ans , j-i+1);
        //         mask = (mask | nums[j]);

        //    }
        // }

        // return ans;


        // TC = O(n) using sliding window Approach
        int i=0, j=0 , ans =1;
        int mask = 0;
        while(j<n){
            while((nums[j] & mask) != 0){
                mask = (mask ^ nums[i]);
                i++;
            }
            ans = max(ans , j-i+1);
            mask = (mask | nums[j]);
            j++;
        }
        return ans;

    }
};