class Solution {
    #define P pair<int , pair<int , int>>
public:
    int minimumTime(vector<vector<int>>& grid) {
        if(grid[1][0]>1 && grid[0][1]>1){
            return -1;
        }


        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> result(m , vector<int>(n , INT_MAX));
        result[0][0] = 0;

        vector<vector<int>> vis(m , vector<int>(n ,0));
        vis[0][0] = 1;

        // {time , {i,j}};
        priority_queue<P , vector<P> , greater<P>> pq;
        pq.push({0 , {0,0}});

        int dir[] = {1 , -1 , 0 , 0};
        int dic[] = {0 , 0 , 1 , -1};

        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();

            int time = curr.first;
            int r = curr.second.first;
            int c = curr.second.second;

            if(r==m-1 && c==n-1){
                return result[m-1][n-1];
            }


            for(int i=0 ; i<4 ; i++){
                int row = r+dir[i];
                int col = c+dic[i];
                if(row<0 || row>=m || col<0 || col>=n || vis[row][col]==1){
                    continue;
                }
                
                if(grid[row][col] <= time){
                    pq.push({time+1 , {row , col}});
                    result[row][col] = time+1;
                    vis[row][col] = 1;
                }
                else if((grid[row][col] - time)%2 == 0){
                    pq.push({grid[row][col]+1 , {row , col}});
                    result[row][col] = grid[row][col]+1;
                    vis[row][col] = 1;
                }
                else{
                    pq.push({grid[row][col] , {row , col}});
                    result[row][col] = grid[row][col];
                    vis[row][col] =1 ;
                }


            }

        }


        return result[m-1][n-1];
        
    }
};