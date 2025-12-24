#include <bits/stdc++.h>

class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int numApples = accumulate(apple.begin() , apple.end(), 0);
        sort(capacity.begin() , capacity.end() , [](int a , int b){
            return a>b;
        });

        int count = 0;
        int sum = 0;
        for(int i=0 ; i<capacity.size() ; i++){
            sum += capacity[i];
            count++;
            if(sum>=numApples) return count;

        }

        return count;
        
    }
};