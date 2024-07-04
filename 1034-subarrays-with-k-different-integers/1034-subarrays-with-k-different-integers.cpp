class Solution {
public:
    int funct(vector<int>& a, int k) {
        int l = 0, r = 0, cnt = 0;
        unordered_map<int, int> mpp;
        while (r < a.size()) {
            mpp[a[r]]++;
            while(mpp.size() > k) {
                mpp[a[l]]--;
                if (mpp[a[l]] == 0) {
                    mpp.erase(a[l]);
                }
                l++;
            }
            cnt += (r - l + 1);
            r++;
        }
        return cnt;
    }

public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return (funct(nums, k) - funct(nums, k - 1));
    }
};