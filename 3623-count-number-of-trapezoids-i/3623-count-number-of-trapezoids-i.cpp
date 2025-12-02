class Solution {
public:
    int m = 1e9+7;
    int countTrapezoids(vector<vector<int>>& points) {
        map<int , int> mpp;

        for(auto &it:points){
            mpp[it[1]]++;
        }
        long long totalLines = 0;
        long long result = 0;
        for(auto &it:mpp){
            long long cnt = it.second;

            long long lines = (cnt*(cnt-1))/2;
            result += (lines * totalLines);

            totalLines += lines;
        
        }

        return result % m;
    }
};