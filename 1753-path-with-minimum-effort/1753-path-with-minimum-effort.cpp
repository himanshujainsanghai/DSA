class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        priority_queue<pair<int , pair<int ,int>> , vector<pair<int , pair<int , int>>> ,
        greater<pair<int , pair<int , int>>>> pq;
        pq.push({0, {0,0}});


        vector<vector<int>> dist(n , vector<int>(m ,INT_MAX));
        dist[0][0] = 0;

        vector<int> drow = {-1,0,1,0};
        vector<int> dcol = {0,1,0,-1};

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int diff = it.first;
            int u = it.second.first;
            int v = it.second.second;
            if(u == n-1 && v == m-1) return diff;
            for(int i =0 ; i<4 ; i++){
                int nrow = u + drow[i];
                int ncol = v + dcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m){
                    int maxeffort = max(abs(heights[nrow][ncol] - heights[u][v]) , diff);
                    if(maxeffort < dist[nrow][ncol]){
                        dist[nrow][ncol] = maxeffort;
                        pq.push({maxeffort , {nrow, ncol}});
                    }
                }
            }
        }
        return 0;
    }
};