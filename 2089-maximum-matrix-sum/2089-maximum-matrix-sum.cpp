class Solution {
public:

    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        long long  sum = 0;
        int minielement =1000000;
        int countnegatives = 0;
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<n ; j++){
                sum += abs(matrix[i][j]);
                if(matrix[i][j] <0){
                    countnegatives++;
                }

                if(minielement > abs(matrix[i][j])){
                    minielement = abs(matrix[i][j]);
                }
            }
        }


        // cout<<sum<<" "<<minielement<<" "<<countnegatives<<endl;
        

        if(countnegatives%2 == 0){
            return sum;
        }
        

        return (sum - 2*minielement);
    }
};