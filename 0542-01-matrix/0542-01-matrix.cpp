

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        queue<pair<int, int>> q;

        // Initialize the queue with all zero cells and set their distance to 0
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0) {
                    dist[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        // Direction vectors for moving up, down, left, and right
        int drow[] = {-1, 0, +1, 0};
        int dcol[] = {0, +1, 0, -1};

        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            // Traverse in the 4 possible directions
            for (int i = 0; i < 4; i++) {
                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                // Check if the adjacent cell is within bounds and not visited
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m) {
                    if (dist[nrow][ncol] > dist[row][col] + 1) {
                        dist[nrow][ncol] = dist[row][col] + 1;
                        q.push({nrow, ncol});
                    }
                }
            }
        }

        return dist;
    }
};
