class Solution {
public:
    void solve(int ind, int temp, int& result, vector<int>& str) {
        result = max(result, __builtin_popcount(temp));

        for (int i = ind; i < str.size(); i++) {
            if ((temp & str[i]) == 0) {
                solve(i, temp | str[i], result, str);
            }
        }
        return;
    }
    int maxLength(vector<string>& arr) {
        vector<int> str;
        for (string& s : arr) {
            unordered_set<char> st(s.begin(), s.end());
            if (st.size() != s.size()) {
                continue;
            }

            int val = 0;
            for (char& ch : s) {
                val = val | (1 << (ch - 'a'));
            }
            str.push_back(val);
        }

        int temp = 0;
        int result = 0;

        solve(0, temp, result, str);
        return result;
    }
};