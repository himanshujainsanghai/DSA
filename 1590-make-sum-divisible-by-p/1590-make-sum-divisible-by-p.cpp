class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        
        int n = nums.size();
        // int sum = accumulate(nums.begin() , nums.end() , 0);
        int sum = 0;
        for(int i=0 ; i<n ; i++){
            sum = (sum + nums[i]) %p;
        }
        int target = sum%p;
        if(target == 0) return 0;

        unordered_map<int , int> mpp;
        // cumulative sum , index
        // (prev)%p = (curr - target + p)%p
        // mpp.push({0, -1});
        mpp[0] = -1;
        int curr = 0;
        int dist = INT_MAX;
        for(int i=0 ; i<n ; i++){
            curr = (curr + nums[i]) % p;

            int prev = (curr - target + p) %p;

            if(mpp.find(prev) != mpp.end()){
                int start = mpp[prev];

                dist = min(dist , i-start);
            }
            


            mpp[curr] = i;
        }

        if(dist >= n) return -1;
        return dist;
    }
};