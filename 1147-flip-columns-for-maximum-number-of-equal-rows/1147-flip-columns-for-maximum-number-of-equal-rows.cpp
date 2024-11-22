class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int maxrows = 0;

        for(auto &vec:matrix){
            vector<int> inverted(n , 0);
            for(int i=0 ; i<n ; i++){
                if(vec[i] == 0) inverted[i] = 1;
            }

            int count =0;
            for(auto& row:matrix){
                if(row == vec || row == inverted){
                    count++;
                }
            }

            maxrows = max(maxrows , count);
        }
        return maxrows;
    }
};