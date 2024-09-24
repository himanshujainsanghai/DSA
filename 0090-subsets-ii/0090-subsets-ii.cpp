class Solution {
private:
    void func(int ind, vector<int>& nums, vector<int>& ds,
              vector<vector<int>>& ans, int n) {
        ans.push_back(ds);
        for (int i = ind; i < n; i++) {
            if (i > ind && nums[i] == nums[i - 1])
                continue;
            ds.push_back(nums[i]);
            func(i + 1, nums, ds, ans, n);
            ds.pop_back();
            // func(i+1 , nums , ds , ans , n);
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> ds;
        sort(nums.begin() , nums.end());
        func(0, nums, ds, ans, n);
        return ans;
    }
};