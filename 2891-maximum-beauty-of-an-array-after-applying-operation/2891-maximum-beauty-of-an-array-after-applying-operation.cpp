class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int n = nums.size();
        vector<pair<int , int>> vis( n , {0,0});
        int start=0 , end=0;
        for(int i=0 ; i<n ; i++){
            start = nums[i]-k;
            end = nums[i]+k;
            vis[i] = {start , end};

        }

        sort(vis.begin() , vis.end());

        deque<pair<int, int>> dq;
        dq.push_back(vis[0]);
        int ans = 1;
        for(int i=1 ; i<n ; i++){
            
            while(!dq.empty() && dq.front().second < vis[i].first){
                dq.pop_front();
            }
            dq.push_back(vis[i]);
            ans = max(ans , (int)dq.size());
        }
        

        return ans;
    }
};