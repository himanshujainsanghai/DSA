class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> leftmaxi(n , 0);
        vector<int> rightmaxk(n , 0);
        for(int i=1 ; i<n ; i++){
            leftmaxi[i] = max(leftmaxi[i-1] , nums[i-1]);
        }
        for(int k=n-2 ; k>=0 ; k--){
            rightmaxk[k] = max(rightmaxk[k+1] , nums[k+1]);
        }
        long long result = 0;
        for(int j=1 ; j<n ; j++){
            result = max(result , (long long)(leftmaxi[j] - nums[j])*rightmaxk[j]);

        }
        return result;
    }
};