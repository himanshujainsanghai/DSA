class Solution {
    void func(int ind , int target , vector<int>& candi , vector<vector<int>>& ans , vector<int>& ds , int n){

        if(ind == n ){
            if(target == 0) ans.push_back(ds);
            return;
        }

        if(candi[ind] <= target){
            ds.push_back(candi[ind]);
            func(ind , target-candi[ind] , candi , ans , ds , n);
            ds.pop_back();
        }
        func(ind +1 , target , candi , ans , ds , n);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candi, int target) {
        int n = candi.size();
        vector<vector<int>> ans;
        vector<int> ds;
        func(0 , target , candi , ans , ds , n);
        return ans;
        
    }
};