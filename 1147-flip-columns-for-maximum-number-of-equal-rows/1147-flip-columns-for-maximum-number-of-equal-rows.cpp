class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        // int m = matrix.size();
        int n = matrix[0].size();
        int maxrows = 0;

        // for(auto &vec:matrix){
        //     vector<int> inverted(n , 0);
        //     for(int i=0 ; i<n ; i++){
        //         if(vec[i] == 0) inverted[i] = 1;
        //     }

        //     int count =0;
        //     for(auto& row:matrix){
        //         if(row == vec || row == inverted){
        //             count++;
        //         }
        //     }

        //     maxrows = max(maxrows , count);
        // }
        // return maxrows;



        // OPITMAL APPROACH
        // tracking the nature of the rows

        unordered_map<string, int> mpp;
        for(auto& row: matrix){
            int firstchar = row[0];
            string curr = "";
            for(int j=0 ; j<n ; j++){
                curr += (row[j]==firstchar)? 's' :'c';
            }

            mpp[curr]++;

            maxrows = max(maxrows , mpp[curr]);
        }

        // traversal to check maximum count within map
        // for(auto& it:mpp){
        //     maxrows = max(maxrows , it.second);
        // }

        return maxrows;
    }
};