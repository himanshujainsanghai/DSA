class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        // MONOTONC DEQUE APPROACH  
        int n = nums.size();

        vector<long long> prefsum(n ,0);
        deque<int> dq;
        int j=0;
        int ans = INT_MAX;

        while(j<n){
            if(j==0){
                prefsum[j] = nums[j];
            }else{
                prefsum[j] = prefsum[j-1] + nums[j];
            }


            if(prefsum[j] >= k){
                ans = min(ans ,  j+1);
            }

            while(!dq.empty() && prefsum[j]-prefsum[dq.front()] >= k){
                ans= min(ans , j-dq.front());
                dq.pop_front();
            }

            while(!dq.empty() && prefsum[j] <= prefsum[dq.back()]){
                dq.pop_back();
            }
            

            dq.push_back(j);
            j++;
        }
        

        return (ans==INT_MAX)? -1 :ans;
        
    }
};