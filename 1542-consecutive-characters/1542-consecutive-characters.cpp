class Solution {
public:
    int maxPower(string s) {
        ios::sync_with_stdio(false); // Disable synchronization with C I/O
        cin.tie(NULL);               // Untie cin from cout
        cout.tie(NULL);
        int n = s.size();
        if (n == 0)
            return 0;
        int cnt = 1, ans = 1;
        int prev = -1;

        for (int i = 0; i < n; i++) {
            if (s[i] - 'a' == prev) {
                cnt++;

            } else {
                ans = max(ans, cnt);
                prev = s[i] - 'a';
                cnt = 1;
            }
        }
        ans = max(ans, cnt);
        return ans;
    }
};