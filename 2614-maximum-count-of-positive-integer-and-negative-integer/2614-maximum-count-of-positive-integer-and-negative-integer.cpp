class Solution {
public:
    int maximumCount(vector<int>& nums) {
        // int p = count_if(nums.begin() , nums.end() , [](int num){
        //     return num>0;
        // }); 

        // int n = count_if(nums.begin() , nums.end() , [](int num){
        //     return num<0;
        // });

        // return max(p , n);

        int firstP = lower_bound(nums.begin() , nums.end() , 1) - nums.begin();
        int firstN = lower_bound(nums.begin() , nums.end() , 0) - nums.begin();
        int n = nums.size();

        return max(n-firstP , firstN);
        
    }
};