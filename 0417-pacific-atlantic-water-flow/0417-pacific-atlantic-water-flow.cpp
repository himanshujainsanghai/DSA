class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        if(m==1 && n==1) return {{0, 0}};

        vector<vector<int>> pacificVisited(m , vector<int>(n , 0));
        vector<vector<int>> atlanticVisited(m , vector<int>(n , 0));


        // mark the visited for the onew who could reach pacific and atlantic

        for(int i=0 ; i<m ; i++){
            dfs(i , 0 , heights , pacificVisited , m ,n);
            dfs(i , n-1 , heights , atlanticVisited , m , n);
        }

        for(int j=0 ; j<n ; j++){
            dfs(0 , j , heights , pacificVisited , m , n);
            dfs(m-1 , j , heights , atlanticVisited , m , n);
        }

        // mark the results now

        vector<vector<int>> ans;

        for(int i=0 ; i<m ; i++){
            for(int j=0 ; j<n ; j++){
                if(pacificVisited[i][j]==1 && atlanticVisited[i][j]==1){
                    ans.push_back({i, j});
                }
            }
        }
        return ans;

    }

    void dfs(int i , int j , vector<vector<int>>& heights ,vector<vector<int>>& vis, 
    int m , int n){
        vis[i][j] = 1;

        int rowi[] = {-1 , 0 , 1 , 0};
        int coli[] = {0, +1 , 0 , -1};

        for(int k=0 ; k<4 ; k++){
            int nrow = i+rowi[k];
            int ncol = j+coli[k];

            if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && !vis[nrow][ncol] && 
            (heights[nrow][ncol] >= heights[i][j])){
                dfs(nrow , ncol , heights , vis , m , n);
            }
        }

        return;
    }
};