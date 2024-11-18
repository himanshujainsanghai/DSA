class Solution {
private:
    void pos(vector<int>& code , vector<int>& ans ,int n , int k , int prefsum){
        for(int i=0 ; i<n ; i++){
            int sum =0;
            for(int j=1 ; j<k+1 ; j++){
                sum += code[(i+j)%n];
            }
            ans[i] = sum;
        }
    }
    void neg(vector<int>& code , vector<int>& ans , int n  , int k, int prefsum){
        for(int i=0 ; i<n ; i++){
            int sum = 0;
            for(int j=1 ; j<k+1 ; j++){
                if((i-j)>=0){
                    sum += code[i-j];
                }else{
                    sum += code[n+(i-j)];
                }
            }

            ans[i] = sum;
        }
    }
public:
    vector<int> decrypt(vector<int>& code, int k) {
        // int n = code.size();
        // vector<int> ans(n ,0);
        // if(k==0){
        //     return ans;
        // }
        // int prefsum =0;
        // for(int i=0 ; i<n  ; i++) prefsum += code[i];

        // if(k>0) pos(code , ans , n ,k ,  prefsum);
        // else{
        //     neg(code , ans , n , abs(k) , prefsum);
        // } 

        // return ans;   // BRUTE FORCE : TC=O(N*K);
        


        int n = code.size();
        vector<int> ans(n , 0);
        if(k==0) return ans;

        int i=-1 , j=-1;
        if(k>0){
            i=1;
            j=k;
        }
        else{
            i=n-abs(k);
            j=n-1;
        }

        int windowsum = 0;
        for(int ind = i ; ind<=j ; ind++){
            windowsum += code[ind];
        }

        for(int ind =0 ; ind<n ; ind++){
            ans[ind] = windowsum;

            windowsum -= code[i%n];
            i++;


            windowsum += code[(j+1)%n];
            j++;
        }

        return ans;

    }
};