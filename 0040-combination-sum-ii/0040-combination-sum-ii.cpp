class Solution {
private:
    void func(int ind, int target, vector<vector<int>>& ans, vector<int>& ds,
              int n, vector<int>& candi) {
        if (target < 0)
            return;
        if (target == 0) {
            ans.push_back(ds);
            return;
        }
        for (int i = ind; i < n; i++) {
            if (i > ind && candi[i] == candi[i - 1])
                continue;
            if (candi[i] > target)
                break;
            ds.push_back(candi[i]);
            func(i + 1, target - candi[i], ans, ds, n, candi);
            ds.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candi, int target) {
        int n = candi.size();
        vector<vector<int>> ans;
        vector<int> ds;
        sort(candi.begin(), candi.end());
        func(0, target, ans, ds, n, candi);
        return ans;
    }
};