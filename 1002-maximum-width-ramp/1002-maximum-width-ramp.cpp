class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        ios::sync_with_stdio(false); // Disable synchronization with C I/O
        cin.tie(NULL);               // Untie cin from cout
        cout.tie(NULL); 
        int n = nums.size();
        vector<int> right(n , 0);
        right[n-1] = nums[n-1];
        for(int i =n-2 ; i>=0 ; i--){
            if(nums[i] <=right[i+1] ){
                right[i] = right[i+1];
            }else{
                right[i] = nums[i];
            }
        }
        int l = 0 ; 
        int r = 1;
        int maxi =0;
        while(r<n){
            if(nums[l] <= nums[r] || nums[l]<=right[r]){
                maxi = max(maxi ,r-l);
                r++;

            }
            else{
                l++;
            }

        }
        return maxi;
        
    }
};