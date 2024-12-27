class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();
        // values[i] + values[j] + i -j -> consider it as (values[i]+i) + (values[j] -j);  
        // so for every j we just need prev-max value of (values[i]+i);
        // since (values[j]-j) is highly volatile 

        
        int maxScore = INT_MIN , score =0 , prevMaxValue = values[0];
        for(int j=1 ; j<n ; j++){
            score = prevMaxValue + values[j] -j;
            maxScore = max(maxScore , score);
            prevMaxValue = max(values[j]+j , prevMaxValue); 
        }
        return maxScore;
        
    }
};