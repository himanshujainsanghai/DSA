class Solution {
public:
    bool isIsomorphic(string s, string t) {
        ios::sync_with_stdio(false); // Disable synchronization with C I/O
        cin.tie(NULL);               // Untie cin from cout
        cout.tie(NULL);
        if (s.size() != t.size())
            return false;

        char map1[128] = {0};
        char map2[128] = {0};
        for (int i = 0; i < s.size(); i++) {
            if (map1[s[i]] != map2[t[i]])
                return false;
            map1[s[i]] = i + 1;
            map2[t[i]] = i + 1;
        }
        return true;
    }
};