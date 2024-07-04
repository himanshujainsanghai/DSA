class Solution {
public:
    string minWindow(string s, string t) {
        if (t.empty() || s.empty())
            return "";
        int l = 0, r = 0, minlen = INT_MAX, sIndex = -1, cnt = 0;
        unordered_map<char, int> mpp;
        for (int i = 0; i < t.size(); i++) {
            mpp[t[i]]++;
        }
        while (r < s.size()) {
            if (mpp[s[r]] > 0)
                cnt++;
            mpp[s[r]]--;
            while (cnt == t.size()) {
                if (r - l + 1 < minlen) {
                    minlen = r - l + 1;
                    sIndex = l;
                }
                if (mpp.find(s[l]) != mpp.end()) {
                    if (++mpp[s[l]] > 0) {
                        cnt--;
                    }
                }

                l++;
            }
            r++;
        }
        return (sIndex == -1)? "" : s.substr(sIndex, minlen);

        // std::unordered_map<char, int> t_map;
        // for (char c : t) {
        //     t_map[c]++;
        // }

        // int left = 0, right = 0, min_len = INT_MAX, start = 0, count = 0;
        // for (right = 0; right < s.size(); right++) {
        //     if (t_map.find(s[right]) != t_map.end()) {
        //         if (--t_map[s[right]] >= 0) {
        //             count++;
        //         }
        //     }

        //     while (count == t.size()) {
        //         if (right - left + 1 < min_len) {
        //             min_len = right - left + 1;
        //             start = left;
        //         }
        //         if (t_map.find(s[left]) != t_map.end()) {
        //             if (++t_map[s[left]] > 0) {
        //                 count--;
        //             }
        //         }
        //         left++;
        //     }
        // }

        // return (min_len == INT_MAX) ? "" : s.substr(start, min_len);
    }
};