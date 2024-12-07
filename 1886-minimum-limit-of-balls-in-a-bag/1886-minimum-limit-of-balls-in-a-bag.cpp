class Solution {
    private:
    bool isPossible(vector<int> nums , int maxOp , int mid){
        int total =0;
        for(auto& num:nums){
            int ops = num/mid;
            if(num % mid == 0){
                ops -= 1;
            }

            total += ops;
            if(total > maxOp){
                return false;
            }
        }

        return true;
    }
public:
    int minimumSize(vector<int>& nums, int maxOp) {

        int l = 1  , r = INT_MIN;
        for(auto& num:nums){
            r = max(r , num);
        } 

        int ans =r ,  mid =0;
        while(l<=r){
            mid = l + (r-l)/2 ;

            if(isPossible(nums , maxOp , mid)){
                ans = mid ;
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        

        return ans;
    }
};