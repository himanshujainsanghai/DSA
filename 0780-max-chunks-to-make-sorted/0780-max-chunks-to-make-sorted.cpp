class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        // int n = arr.size();

        // vector<int> prefixmax(arr.begin() , arr.end());
        // vector<int> suffixmin(arr.begin() , arr.end());

        // for(int i=1 ; i<n ; i++){
        //     prefixmax[i] = max( prefixmax[i] ,  prefixmax[i-1]);
        // }

        // for(int i= n-2 ; i>=0 ; i--){
        //     suffixmin[i] = min(suffixmin[i] , suffixmin[i+1]);
        // }

        // int count =0;

        // for(int i=0 ; i<n ; i++){
        //     int phlekamax = (i>0)? prefixmax[i-1] : -1;
        //     int baddkamin = suffixmin[i];
        //     if( phlekamax  < baddkamin ){
        //         count++;
        //     }
        // }
        // return count;     



        // Approach 2
        int n = arr.size();
        int count = 0;
        int cummsum =0 , indsum =0;
        for(int i=0 ; i<n ; i++){
            cummsum += arr[i];
            indsum += i;
            if(cummsum == indsum){
                count++;
            }

        }  
        return count;
    }
};