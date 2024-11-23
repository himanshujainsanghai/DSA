class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {


        int m = box.size();
        int n = box[0].size();

        vector<vector<char>> ans(n , vector<char>(m , '.'));


        // transpose 
        // for(int i=0 ; i<n ; i++){
        //     for(int j=0 ; j<m ; j++){
        //         ans[i][j] = box[j][i];
        //     }
        // }

        // // reverse each row in order to rotate
        // for(vector<char>& vec:ans){
        //     reverse(vec.begin() ,vec.end());
        // } 


        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                ans[j][m - i - 1] = box[i][j];  // This handles both transpose and reverse
            }
        }



        for(int j=0 ; j<m  ; j++){

            int lastspacefound = n-1;
            for(int i =n-1 ; i>=0 ; i--){

                if(ans[i][j] == '*'){
                    lastspacefound = i-1;
                    continue;
                }

                if(ans[i][j] == '#'){
                    ans[i][j] = '.';
                    ans[lastspacefound][j] = '#';
                    lastspacefound--;
                }

            }
        }


        return ans;


        
    }
};