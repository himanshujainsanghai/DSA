class Solution {
private:
void func(int row , int col , int m , int n , vector<vector<int>>& grid){
    // upper traversal
    for(int i=row ; i>=0 ; i--){
        if((i>0) && (grid[i-1][col] != 2) && (grid[i-1][col] != 3)){
            grid[i-1][col] = 1;
        }
        else{
            break;
        }
    }

    // downward traversal
    for(int i= row ; i<m ; i++){
        if(i<m-1 && (grid[i+1][col] != 2) && (grid[i+1][col] != 3)){
            grid[i+1][col] = 1;
        }
        else{
            break;
        }
    }

    // left tarversal
    for(int j = col ; j>=0 ; j--){
        if((j>0) && (grid[row][j-1] != 2) && (grid[row][j-1] != 3)){
            grid[row][j-1] = 1;
        }
        else{
            break;
        }
    }

    // right traversal
    for(int j = col ; j<n ; j++){
        if((j<n-1) && (grid[row][j+1] != 2) && (grid[row][j+1] != 3)){
            grid[row][j+1] = 1;
        }
        else{
            break;
        }
    }
}
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m , vector<int>(n ,0));


        for(auto &vec:guards){
            int i = vec[0];
            int j = vec[1];
            grid[i][j] = 2;
        }

        for(auto &vec:walls){
            int i = vec[0];
            int j = vec[1];
            grid[i][j] = 3;
        }


        for(auto &vec:guards){
            int i = vec[0];
            int j = vec[1];

            func(i , j , m , n, grid);
        }

        int  cnt =0;
        for(int i=0 ; i<m ; i++){
            for(int j=0 ; j<n ; j++){
                if(grid[i][j] == 0){
                    cnt++;
                }

                // cout<<grid[i][j]<<" ";
            }
            // cout<<endl;
        }

        return cnt;

    }
};