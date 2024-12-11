class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int n = nums.size();
        vector<pair<int , int>> vis( n , {0,0});
       
        for(int i=0 ; i<n ; i++){
           
            vis[i] = {nums[i]-k , nums[i]+k};

        }

        sort(vis.begin() , vis.end());

        deque<int> dq;
        dq.push_back(vis[0].second);
        int ans = 1;
        for(int i=1 ; i<n ; i++){
            
            while(!dq.empty() && dq.front() < vis[i].first){
                dq.pop_front();
            }
            dq.push_back(vis[i].second);
            ans = max(ans , (int)dq.size());
        }
        

        return ans;
    }
};