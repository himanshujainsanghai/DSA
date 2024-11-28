class Solution {

    #define P pair<int , pair<int , int>>
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        ios::sync_with_stdio(false); // Disable synchronization with C I/O
        cin.tie(NULL);               // Untie cin from cout
        cout.tie(NULL);
        int m = grid.size();
        int n = grid[0].size();



        vector<vector<int>> result(m , vector<int>(n ,INT_MAX));
        result[0][0] = 0;


        int row[] = {0 , 0 , 1 ,-1};
        int col[] = {1 , -1 , 0 , 0};

        priority_queue<P , vector<P> , greater<P>> pq;
        pq.push({0 , {0,0}});  // {wt , {x ,y}};

        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();

            int d = curr.first;
            int r = curr.second.first;
            int c = curr.second.second;

            for(int i=0 ; i<4 ; i++){
                int x = r + row[i];
                int y = c + col[i];

                if(x<0 || x>=m || y<0 || y>=n){
                    continue;
                }
                int wt = 0;
                if(grid[x][y]==1){
                    wt =1;
                } 

                if(d+wt <result[x][y]){
                    result[x][y]=d+wt;
                    pq.push({d+wt , {x , y}});
                }

            }

        }


        return result[m-1][n-1];
        
    }
};