// class Solution {
// private:
//     vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

//     int dfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& vis,
//             int cost, int n, int m) {
//         if (i == n - 1 && j == m - 1) {
//             return cost;
//         }
//         vis[i][j] = 1;
//         int minCost = INT_MAX;
//         for (int k = 0; k < 4; k++) {
//             int row = i + dir[k][0];
//             int col = j + dir[k][1];

//             if (row < n && row >= 0 && col < m && col >= 0 && !vis[row][col]) {
//                 int dirCost = cost + ((grid[i][j] - 1 == k) ? 0 : 1);
//                 minCost = min(minCost, dfs(row, col, grid, vis, dirCost, n, m));
//             }
//         }

//         vis[i][j] = 0;

//         return minCost;
//     }

// public:
//     int minCost(vector<vector<int>>& grid) {

//         int n = grid.size();
//         int m = grid[0].size();

//         // Brute Force Apporoach using DFS and Backtracking
//         // vector<vector<int>> vis(n , vector<int>(m ,0));
//         // return dfs(0 , 0 , grid , vis , 0 , n , m);

//         vector<vector<int>> ans(n, vector<int>(m, INT_MAX));
//         ans[0][0] = 0;
//         // vector<vector<int>> vis(n, vector<int>(m, 0));
//         priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>
//             pq;
//         pq.push({0, 0, 0});
//         while (!pq.empty()) {
//             auto it = pq.top();
//             pq.pop();
//             int cost = it[0];
//             int i = it[1];
//             int j = it[2];

//             if (i == n - 1 && j == m - 1) {
//                 return ans[n - 1][m - 1];
//             }

//             if(ans[i][j]<cost){
//                 continue;
//             }

//             int minCost = INT_MAX;
//             for (int k = 0; k < 4; k++) {
//                 int row = i + dir[k][0];
//                 int col = j + dir[k][1];

//                 if (row < n && row >= 0 && col < m && col >= 0) {
//                     int dirCost = cost + ((grid[i][j] - 1 == k) ? 0 : 1);
//                     if (dirCost < ans[row][col]) {
//                         ans[row][col] = dirCost;
//                         pq.push({dirCost, row, col});
//                     }
//                 }
//             }
//         }

//         return ans[n - 1][m - 1];
//     }
// };


// Deque approach
#define MAX_DIR 4
class Solution {
    // UP, RIGHT, DOWN, LEFT
    int dir[MAX_DIR+1] = {-1, 0, 1, 0, -1};
    
    int getIndex(int i){
        if(i==1) 
            return 1;//RIGHT =1
        else if(i==2) 
            return 3;//LEFT = 3
        else if(i==3) 
            return 2; // DOWN = 2
        return 0;// UP =0
    }
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        deque<pair<int, int>> d;
        d.push_back(make_pair(0, 0));
        vector<vector<int>> cost(m, vector<int>(n, INT_MAX));
        cost[0][0] = 0;
        while(!d.empty()){
            int v = d.front().first;
            int r = (d.front().second)/n;
            int c = (d.front().second)%n;
            d.pop_front();
            int move_cost[MAX_DIR] = {1, 1, 1, 1}; // Initially we mark that all 4 neighbouring direction need 1 cost to go.  
            move_cost[getIndex(grid[r][c])] = 0; // Then we check what is marking on this cell , and make that direction as 0.  
            if(r==m-1 and c==n-1)
                return cost[r][c];
            for(int i=0; i<MAX_DIR; ++i){
                int n_r = r + dir[i];
                int n_c = c + dir[i+1];
                if(n_r >=0 and n_r<m and 
                   n_c >=0 and n_c<n and
                   v + move_cost[i]  < cost[n_r][n_c]
                  )
                {
                    cost[n_r][n_c] = v; // update the cost
                     if(move_cost[i])
                     {
                         cost[n_r][n_c]++; // Since an extra step of cost 1 is required because the direction is different.
                         d.push_back(make_pair(cost[n_r][n_c], n_r*n+n_c));  // move cost is 1 so push back
                     }
                    else
                        d.push_front(make_pair(cost[n_r][n_c], n_r*n+n_c)); // move cost is 0 we push to front of queue.  
                }
            }
        }
        
        return 0;
    }
};