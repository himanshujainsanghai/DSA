// class Solution {
//     private:
//     vector<vector<int>> dir = {{0,1} , {0,-1} , {1,0} , {-1 , 0}};
//     int m , n;
//     int dfs(int i , int j , vector<vector<int>>& grid , vector<vector<int>>& vis){
//         vis[i][j] = 1;
//         int perimeter = 0;
//         for(auto it:dir){
//             int row = i+it[0];
//             int col = j+it[1];

//             if (row >= 0 && row < m && col >= 0 && col < n) {
//                 if (grid[row][col] == 1 && !vis[row][col]) {
//                     perimeter += dfs(row, col, grid , vis); // Recurse for land cell
//                 } else if (grid[row][col] == 0 && !vis[row][col]) {
//                     perimeter++; // Water cell contributes to the perimeter
//                 }
//             } else {
//                 // Out of bounds contributes to the perimeter
//                 perimeter++;
//             }


//         }

//         // cout<<perimeter<<endl;

//         return perimeter;

//     }
// public:
//     int islandPerimeter(vector<vector<int>>& grid) {
//         m = grid.size();
//         n = grid[0].size();

//         vector<vector<int>> vis(m ,  vector<int>(n , 0));
//         for(int i=0 ; i<m ; i++){
//             for(int j=0 ; j<n ; j++){
//                 if(grid[i][j] == 1){
//                     return  dfs(i , j , grid , vis);;
//                 }
//             }
//         }
//         return 0;
//     }
// };

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int p =0;
        int m = grid.size();
        int n = grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                     p+=4;
                 if(i>0&&grid[i-1][j]==1) p-=2;
                 if(j>0&&grid[i][j-1]==1) p-=2;
                }
            }
        }
      return p;
    }
};