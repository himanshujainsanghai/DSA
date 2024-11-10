class Solution {

    void bits_update(vector<int>& bits , int n , int diff){
        for(int i=0 ; i<32 ; i++){
            if(n & (1<<i)){
                bits[i] += diff;
            }
        }
    }
    int bits_to_int(vector<int>& bits){
        int res=0;
        for(int i=0 ; i<32 ; i++){
            if(bits[i]){
                res += (1<<i);
            }
        }
        return res;
    }
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int ans = INT_MAX;
        vector<int> bits(32 , 0);

        int left =0 ;

        for(int right =0 ; right<nums.size() ; right++){
            bits_update(bits , nums[right] , 1);
            int curr = bits_to_int(bits);

            while(left <= right && curr >=k){
                ans = min(ans , right-left +1);
                bits_update(bits, nums[left] , -1);
                curr = bits_to_int(bits);
                left++;
            }
        }

        return (ans == INT_MAX)? -1 : ans;


    }
};