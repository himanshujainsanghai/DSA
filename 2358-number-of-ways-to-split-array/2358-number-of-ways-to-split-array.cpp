class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        long lsum =0;
        long rsum = accumulate(nums.begin() , nums.end() , 0L);
        
        int i=0 , count =0;
        while(i<n-1){
            lsum += nums[i];
            rsum -= nums[i];
            if(lsum >= rsum){
                count++;
            }

            i++;

        }

        return count;
        
    }
};