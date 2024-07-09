class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intv) {
        sort(intv.begin() , intv.end());
        vector<vector<int>> ans;
        for(int i =0 ; i<intv.size() ; i++){
            if(ans.empty() ||  ans.back()[1] < intv[i][0]){
                ans.push_back(intv[i]);
            }
            else{
                ans.back()[1] = max(ans.back()[1] , intv[i][1]);
            }
        }
        return ans;
    }
};