// class Solution {
// public:
//     typedef pair<int, int> P;
//     vector<vector<int>> directions{{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

//     vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
//         int m = isWater.size();
//         int n = isWater[0].size();


//         vector<vector<int>> height(m, vector<int>(n, -1));

//         queue<P> que;
//         //Height of water cells must be 0 only
//         //T.C : O(m*n)
//         for(int i = 0; i < m; i++) {
//             for(int j = 0; j < n; j++) {
//                 if(isWater[i][j] == 1) { //this cell is water
//                     height[i][j] = 0; //This is a source for hitting BFS
//                     que.push({i, j});
//                 }
//             }
//         }

//         //Apply khandani template - Multi source BFS ka
//         //T.C : O(m*n)
//         //S.C : O(m*n)
//         while(!que.empty()) {
//             int N = que.size();

//             while(N--) {
//                 P curr = que.front();
//                 que.pop();

//                 int i = curr.first;
//                 int j = curr.second;

//                 for(auto &dir : directions) {
//                     int i_ = i + dir[0];
//                     int j_ = j + dir[1];

//                     if(i_ >= 0 && i_ < m && j_ >= 0 && j_ < n && height[i_][j_] == -1) {
//                         height[i_][j_] = height[i][j] + 1;
//                         que.push({i_, j_});
//                     }
//                 }
//             }
//         }

//         return height;


//     }
// };

// optimal approach

class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& g) {
        int rows = g.size();
        int cols = g[0].size();
        int inf = rows+cols;

        for(int r=0;r<rows;r++) {
            for(int c=0;c<cols;c++) {
                if(g[r][c] == 1) g[r][c] = 0;
                else g[r][c] = 1;
            }
        }

        for(int r=0;r<rows;r++) {
            for(int c=0;c<cols;c++) {
                if(g[r][c] == 0)continue;
                int left = inf, top = inf;
                if(c-1 >=0) left = g[r][c-1];
                if(r-1 >=0) top = g[r-1][c];
                g[r][c] = min(left,top)+1;
            }
        }
        for(int r = rows-1; r>=0; r--) {
            for(int c= cols-1; c>=0; c--) {
                if(g[r][c] == 0)continue;
                int right = inf, bottom = inf;
                if(r+1 < rows) bottom = g[r+1][c];
                if(c+1 < cols) right = g[r][c+1];
                g[r][c] = min(g[r][c], min(right,bottom)+1);
            }
        }
        return g;
    }
};