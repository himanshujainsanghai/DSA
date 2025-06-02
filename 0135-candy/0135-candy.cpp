class Solution {
public:
    int candy(vector<int>& arr) {
        int n = arr.size();
        int peak = 1;
        vector<int> left(n , 0);
        left[0]=1;
        for(int i=1 ; i<n ; i++){
            if(arr[i]>arr[i-1]){
                peak++;

            }
            else{
                peak = 1;
            }

            left[i] = peak;
            
        }
        peak=1;
        vector<int> right(n ,0);
        right[n-1]=1;
        for(int i=n-2 ; i>=0 ; i--){
            if(arr[i]>arr[i+1]){
                peak++;
            }
            else{
                peak =1;
            }
            right[i]=peak;
        }
        int ans = 0;
        for(int i=0 ; i<n ; i++){
            ans += max(right[i] , left[i]);
        }
        return ans;
    }
};