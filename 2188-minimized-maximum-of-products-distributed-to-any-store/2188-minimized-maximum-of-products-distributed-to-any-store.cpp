class Solution {
public:

    bool func(int x, int n ,  vector<int>& quantities){
        for(auto &products:quantities){
            n -= (products + x -1)/x;
            // n -= ciel(products/x); 

            if( n<0){
                return false;
            }
        }

        return true;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        int l =1 ;
        int r = *max_element(quantities.begin() , quantities.end());

        int res =0;

        while( l<=r){
            int mid = l+(r-l)/2;

            if(func(mid , n , quantities)){
                res = mid;
                r = mid-1;
            }
            else{
                l = mid +1;
            }
        }

        return res;
        
    }
};