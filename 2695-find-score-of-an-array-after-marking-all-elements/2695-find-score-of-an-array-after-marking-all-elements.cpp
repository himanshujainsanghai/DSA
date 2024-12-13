class Solution {
public:
    long long findScore(vector<int>& nums) {
        ios::sync_with_stdio(false); // Disable synchronization with C I/O
        cin.tie(NULL);               // Untie cin from cout
        cout.tie(NULL);
        int n = nums.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>,
            greater<pair<int, int>>> pq;
        for (int i = 0; i < n; i++) {
            pq.push({nums[i] , i});
        }

        vector<int> vis(n, 0);

        long long score = 0;

        int num =0 , index =0;
        while (!pq.empty()) {
            num = pq.top().first;
            index = pq.top().second;
            pq.pop();

            if(vis[index] == 0){
                score += num;
                vis[index]=1;
                if(index-1 >=0 && vis[index-1] == 0) vis[index-1]=1;
                if(index+1 <n && vis[index+1] == 0) vis[index+1]=1;
            }
        }



        return score;
    }
};