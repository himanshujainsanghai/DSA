class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        // ios::sync_with_stdio(false); // Disable synchronization with C I/O
        // cin.tie(NULL);               // Untie cin from cout
        // cout.tie(NULL);
        // int n = nums.size();

        // priority_queue<pair<int , int> , vector<pair<int , int>> , greater<pair<int , int>>> pq;
        // for(int i=0 ; i<n ; i++){
        //     pq.push({nums[i] , i});
        // }

        // while(k--){
        //     auto it = pq.top();
        //     pq.pop();
        //     int ind = it.second;
        //     nums[ind] = nums[ind]*multiplier;
        //     pq.push({nums[ind] , ind});
        // }

        // return nums;




        // make heap methood
        int n = nums.size();

        vector<pair<int, int>> vec(n);
        for(int i = 0; i < n; i++) {
            vec[i] = {nums[i], i};
        }

        make_heap(begin(vec), end(vec), greater<>());

        while(k--) {
            pop_heap(begin(vec), end(vec), greater<>());
            pair<int, int> temp = vec.back();
            vec.pop_back();

            int idx = temp.second;
            int number = temp.first;

            nums[idx] = number*multiplier;

            vec.push_back({nums[idx], idx});
            push_heap(begin(vec), end(vec), greater<>());
        }

        return nums;
        
    }
};