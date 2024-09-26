class Solution {
    void func(int col , vector<string>& board , vector<vector<string>>& ans , int n ,
       vector<int>& leftRow , vector<int>& upperDaig , vector<int>& lowerDaig){
        if(col==n){
            ans.push_back(board);
            return;
        }
        for(int row =0 ; row<n ; row++){
            if(leftRow[row] == 0 && upperDaig[row+col] == 0 && lowerDaig[n-1+col-row] == 0){

                board[row][col] = 'Q';
                leftRow[row] = 1;
                upperDaig[row+col] = 1;
                lowerDaig[n-1+col-row] = 1;
                func(col+1 , board , ans , n , leftRow , upperDaig , lowerDaig);
                board[row][col] = '.';
                leftRow[row] = 0;
                upperDaig[row+col] = 0;
                lowerDaig[n-1+col-row] = 0;
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        vector<int> leftRow(n , 0) , upperDaig(2*n-1 , 0) , lowerDaig(2*n-1 , 0);
        func(0, board, ans, n , leftRow , upperDaig , lowerDaig);
        return ans;
    }
};