class Solution {
public:
    int maximumLength(string s) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        int n = s.size();
        vector<vector<int>> matrix(26, vector<int>(n + 1, 0));
        char ch = s[0];
        int len = 1;
        matrix[ch - 'a'][len]++;

        for (int i = 1; i < n; i++) {

            if (s[i] != ch) {
                ch = s[i];
                len = 1;
                matrix[ch - 'a'][len]++;
                continue;
            }
            len++;
            matrix[ch - 'a'][len]++;
        }

        int maxi = -1, cumulativeSum = 0;
        for (vector<int>& vec : matrix) {
            cumulativeSum = 0;
            for (int j = n; j > 0; j--) {
                cumulativeSum += vec[j];
                if (cumulativeSum >= 3) {

                    if (j > maxi) {
                        maxi = j;
                    }
                }
            }
        }

        return maxi;
    }
};