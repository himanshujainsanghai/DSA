class Solution {
public:
    int maximumLength(string s) {

        // brute-force
        // find out all special substrings
        // store them in a map
        // filter them out

        int n = s.size();

        map<pair<char , int>, int> mpp;

        for (int i = 0; i < n; i++) {

            int len =0;
            for (int j = i; j < n; j++) {

                if (j > i && s[j] != s[i]) {
                    break;
                }

                len++;
                mpp[{s[i] , len}]++;
            }
        }


        int maxi = -1;
        for (auto& mp : mpp) {
            if (mp.second >= 3) {
                int val = mp.first.second;

                if (val > maxi) {
                    maxi = val;
                }
            }
        }

        return maxi;
    }
};