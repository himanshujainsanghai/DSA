class Solution {
public:
    static bool comp(const vector<int>& a, const vector<int>& b){
        return a[1] < b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& inter) {
        // sort(inter.begin() , inter.end() , comp);
        sort(inter.begin(), inter.end(), [](auto &a, auto &b) {
            return a[1] < b[1];
        });
        int cnt = 1  ,  free = inter[0][1];
        int n = inter.size();
        for(int i=1 ; i<n ; i++){
            if(inter[i][0] >= free){
                cnt++;
                free= inter[i][1];
            }
        }


        return n-cnt;
    }
};