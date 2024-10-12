class Solution {
public:
    bool isAnagram(string s, string t) {
        ios::sync_with_stdio(false); // Disable synchronization with C I/O
        cin.tie(NULL);               // Untie cin from cout
        cout.tie(NULL);
        if (s.size() != t.size())
            return false;
        unordered_map<int, int> mpp1, mpp2;
        for (int i = 0; i < s.size(); i++) {
            mpp1[s[i] - 'a']++;
            mpp2[t[i] - 'a']++;
        }
        return mpp1 == mpp2;
    }
};