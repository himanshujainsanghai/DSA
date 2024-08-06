class Solution {
private:
    bool isValid(int nrow, int ncol, int n) {
        return nrow >= 0 && nrow < n && ncol >= 0 && ncol < n;
    }
    
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> vis(n, vector<int>(n, 0));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({grid[0][0], {0, 0}});
        vis[0][0] = 1;

        int dr[] = {-1, 0, 0, 1};
        int dc[] = {0, 1, -1, 0};
        
        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int height = it.first;
            int row = it.second.first;
            int col = it.second.second;
            
            if (row == n - 1 && col == n - 1) {
                return height;
            }
            
            for (int i = 0; i < 4; i++) {
                int nrow = row + dr[i];
                int ncol = col + dc[i];
                
                if (isValid(nrow, ncol, n) && !vis[nrow][ncol]) {
                    vis[nrow][ncol] = 1;
                    pq.push({max(height, grid[nrow][ncol]), {nrow, ncol}});
                }
            }
        }
        
        return -1; // This should never be reached
    }
};
