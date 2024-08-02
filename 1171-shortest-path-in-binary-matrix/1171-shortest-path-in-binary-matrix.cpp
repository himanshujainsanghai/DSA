class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n-1][n-1] == 1) {
            return -1;
        }

        vector<vector<int>> dist(n , vector<int>(n , INT_MAX));
        dist[0][0] = 1;
        queue<pair<int , pair<int , int>>> q;
        q.push({1 , {0 , 0}});
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int dis = it.first;
            int u = it.second.first;
            int v = it.second.second;

            for(int drow = -1 ; drow<=1 ; drow++){
                for(int dcol = -1 ; dcol <=1 ; dcol++){
                    int nrow = u + drow;
                    int ncol = v + dcol;
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<n
                    && grid[nrow][ncol] ==0 && dis+1<dist[nrow][ncol] ){
                        dist[nrow][ncol] = dis+1;
                        if(nrow == n-1 && ncol == n-1){
                            return dis+1;
                        }
                        q.push({dis+1 , {nrow, ncol}});
                    }
                }
            }
        }
        return dist[n-1][n-1] == INT_MAX ? -1 : dist[n-1][n-1];
        
    }
};