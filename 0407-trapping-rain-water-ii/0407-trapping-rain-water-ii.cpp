class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        ios::sync_with_stdio(false); // Disable synchronization with C I/O
        cin.tie(NULL);               // Untie cin from cout
        cout.tie(NULL);
        // priority queue approach
        int m = heightMap.size();
        int n = heightMap[0].size();

        if(m<3 || n<3){
            return 0;

        }

        priority_queue<vector<int> , vector<vector<int>> , greater<vector<int>>> pq;
        vector<vector<int>> vis(m , vector<int>(n , 0));

        // top row and last row
        for(int j=0 ; j<n ; j++){
            vis[0][j] = 1;
            pq.push({heightMap[0][j] , 0 , j});
            vis[m-1][j] = 1;
            pq.push({heightMap[m-1][j] , m-1 , j});
        }
        
        // left col and right col
        for(int i=1 ; i<m-1 ; i++){
            vis[i][0] = 1;
            pq.push({heightMap[i][0] , i , 0});
            vis[i][n-1] = 1;
            pq.push({heightMap[i][n-1] , i , n-1});
        }
        

        int water =0 ;
        vector<vector<int>> dir = {{0,1} , {0 , -1} , {1,0} , {-1 , 0}};
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int height = it[0];
            int i = it[1];
            int j = it[2];


            for(int k =0 ; k<4 ; k++){
                int row = i+dir[k][0];
                int col = j+dir[k][1];

                if(row<m && row>=0 && col<n && col>=0 && !vis[row][col]){
                    if(height > heightMap[row][col]){
                        water += height - heightMap[row][col];
                    }
                    pq.push({max(height , heightMap[row][col]) , row , col});
                    vis[row][col] = 1;
                }
            }
        }

        return water;
    }
};