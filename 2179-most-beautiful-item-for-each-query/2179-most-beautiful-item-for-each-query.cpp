class Solution {
    private:
    int customBinarySearch(vector<vector<int>>& items , int queryVal , int n){
        int l=0;
        int r=n-1;
        int mid=0;
        int val =0;
        while(l<=r){
            mid = l+(r-l)/2;

            if(queryVal >= items[mid][0]){
                l=mid+1;
                val =items[mid][1];
            }
            else{
                r=mid-1;
            }
        }
        return val;
    }
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin() , items.end());
        int n = items.size();
        int maxBeautySeen = 0;
        for(int i=0 ; i<n ; i++){
            maxBeautySeen = max(maxBeautySeen , items[i][1]);
            items[i][1] = maxBeautySeen;
        }

        vector<int> ans;
        int m = queries.size();
        for(int i=0 ; i<m ; i++ ){
            int res = customBinarySearch(items , queries[i] , n);
            ans.push_back(res);
        }
        

        return ans;
    }
};