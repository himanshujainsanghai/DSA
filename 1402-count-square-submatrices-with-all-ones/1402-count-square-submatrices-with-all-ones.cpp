class Solution {
public:
int m;
int n;

int solve(int i ,int j , vector<vector<int>>& grid , vector<vector<int>>& dp){
    if(i>=m || j>=n){
        return 0;
    }
    if(grid[i][j] != 1){
        return 0;
    }
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    int hori = solve(i ,j+1 , grid , dp);
    int daig = solve(i+1 ,j+1 , grid , dp);
    int below = solve(i+1 ,j , grid ,dp);

    return dp[i][j] =  1 + min({hori , daig , below});
}
    int countSquares(vector<vector<int>>& grid) {
      m = grid.size();
      n = grid[0].size();  

      int result =0;
    vector<vector<int>> dp(m+1 , vector<int>(n+1 , 0));
    //   for(int i=0 ; i<m ; i++){
    //     for(int j=0 ; j<n ; j++){
    //         if(grid[i][j] == 1){
    //             result += solve(i ,j , grid , dp);
    //         }
    //     }
    //   }

    // TABULATION

    for(int i=0 ; i<m ; i++){
        for(int j=0 ; j<n ; j++){
            if(i==0 || j==0){
                dp[i][j] = grid[i][j];
            }
            else if(grid[i][j] == 1){
                dp[i][j] = 1 + min({dp[i-1][j-1] , dp[i-1][j] , dp[i][j-1]});
            }

            result += dp[i][j];
        }
    }

      return result;
    }
};