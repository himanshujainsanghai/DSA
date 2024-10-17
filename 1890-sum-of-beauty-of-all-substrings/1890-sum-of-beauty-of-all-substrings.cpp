class Solution {
private:
    int func(vector<int>& vis) {
        int mf = -1;
        int lf = 1e4;
        for (int i = 0; i < 26; i++) {
            mf = max(mf, vis[i]);
            if (vis[i] >= 1) {
                lf = min(lf, vis[i]);
            }
        }
        return mf - lf;
    }

public:
    int beautySum(string s) {
        ios::sync_with_stdio(false); // Disable synchronization with C I/O
        cin.tie(NULL);               // Untie cin from cout
        cout.tie(NULL);
        int n = s.size();
        int sum = 0;
        for (int i = 0; i < n; i++) {
            vector<int> vis(26, 0);
            for (int j = i; j < n; j++) {
                vis[s[j] - 'a']++;
                // sum += func(vis);

                int mf = -1;
                int lf = 1e4;
                for (int i = 0; i < 26; i++) {
                    mf = max(mf, vis[i]);
                    if (vis[i] >= 1) {
                        lf = min(lf, vis[i]);
                    }
                }

                sum += mf-lf;
            }
        }
        return sum;
    }
};