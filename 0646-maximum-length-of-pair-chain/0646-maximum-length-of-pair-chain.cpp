#include <bits/stdc++.h>
class Data{
    public:
    int start;
    int end;
};
class Solution {
    

public:
    static bool comparator(const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        // sort(pairs.begin(), pairs.end(), comparator);
        // int cnt = 1, freetime = pairs[0][1];
        // for (int i = 1; i < pairs.size(); i++) {
        //     if (pairs[i][0] > freetime) {
        //         cnt++;
        //         freetime = pairs[i][1];
        //     }
        // }
        // return cnt;



        // solution 2
        int n = pairs.size();
        vector<Data> arr(n);
        for(int i =0 ; i<n ; i++){
            arr[i].start=pairs[i][0];
            arr[i].end=pairs[i][1];
        }
        sort(arr.begin() , arr.end() ,[](Data a , Data b){
            return a.end < b.end;
        } );
        int cnt =1 , freetime = arr[0].end;
        for(int i =1 ; i<arr.size() ; i++){
            if(arr[i].start > freetime){
                cnt++;
                freetime = arr[i].end;
            }
        }
        return cnt;

    }
};