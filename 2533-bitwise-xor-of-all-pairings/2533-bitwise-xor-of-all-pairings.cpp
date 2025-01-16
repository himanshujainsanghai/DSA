class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int ans = 0;
        if(m%2 != 0){ // m is odd
            for(int it: nums1){
                ans ^= it;
            }
            
        }
        if(n%2 != 0){
            for(int it: nums2){
                ans^= it;
            }
        }

        return ans;
        
    }
};