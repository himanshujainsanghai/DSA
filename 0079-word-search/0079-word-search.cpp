class Solution {
    private:
    vector<vector<int>> dir = {{0,1} , {0,-1} , {1 ,0} , {-1 , 0}};
    bool dfs(int i , int j , vector<vector<char>>& board  , string word , int indx , int m  , int n){
        if(board[i][j] != word[indx]){
            return false;
        }
        if(indx == word.size()-1){
            return true;
        }
        char temp = board[i][j];
        board[i][j] = '$';
        for(int k=0 ; k<4 ; k++){
            int row = i + dir[k][0];
            int col = j + dir[k][1];

            if(row<m && row>=0 && col<n && col>=0 && board[row][col] != '$'){
                if(dfs(row , col , board , word , indx+1 , m  , n)){
                    return true;
                }
            }
        }
        board[i][j]=temp;
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        ios::sync_with_stdio(false); // Disable synchronization with C I/O
        cin.tie(NULL);               // Untie cin from cout
        cout.tie(NULL);

        int m = board.size();
        int n = board[0].size();
        for(int i=0 ; i<m ; i++){
            for(int j=0 ; j<n ; j++){
                if(board[i][j] == word[0] &&  dfs(i , j , board, word , 0 , m , n)){
                    return true;
                }
            }
        }

        return false;
        
    }
};