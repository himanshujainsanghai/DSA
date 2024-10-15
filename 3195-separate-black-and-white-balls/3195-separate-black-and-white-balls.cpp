class Solution {
public:
    long long minimumSteps(string s) {
        ios::sync_with_stdio(false); // Disable synchronization with C I/O
        cin.tie(NULL);               // Untie cin from cout
        cout.tie(NULL);
        int n = s.size();
        if (n == 0)
            return 0;
        int black = 0;
        long long cnt = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                cnt += black;
            } else {
                black++;
            }
        }
        return cnt;
    }
};