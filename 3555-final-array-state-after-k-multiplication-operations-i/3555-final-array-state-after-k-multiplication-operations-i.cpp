class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        ios::sync_with_stdio(false); // Disable synchronization with C I/O
        cin.tie(NULL);               // Untie cin from cout
        cout.tie(NULL);
        int n = nums.size();

        priority_queue<pair<int , int> , vector<pair<int , int>> , greater<pair<int , int>>> pq;
        for(int i=0 ; i<n ; i++){
            pq.push({nums[i] , i});
        }

        while(k--){
            auto it = pq.top();
            pq.pop();
            int ind = it.second;
            nums[ind] = nums[ind]*multiplier;
            pq.push({nums[ind] , ind});
        }

        return nums;

        
    }
};