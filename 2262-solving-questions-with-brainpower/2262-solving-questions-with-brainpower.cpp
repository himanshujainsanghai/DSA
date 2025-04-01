class Solution {
public:
    long long func(int ind , vector<vector<int>>& questions , int n , vector<long long>& dp){
        // base cases
        if(ind >= n) return 0;

        if(dp[ind] != -1) return dp[ind];


        // recursive cases
        long long take = questions[ind][0] + func(ind + questions[ind][1]+1 , questions , n , dp);
        long long skip = func(ind+1 , questions , n , dp);
        return dp[ind] = max(take , skip);
    }

    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        // vector<long long> dp(n+1 , -1);

        // return func(0 , questions , n , dp);
        
        vector<long long> dp(n+1 ,0);
        for(int i=n-1 ; i>=0 ; i--){
             int next = i + questions[i][1] + 1; // Next question index if taken
            long long take = questions[i][0] + (next < n ? dp[next] : 0); // Take the question
            long long skip = dp[i + 1]; // Skip the question

            dp[i] = max(take, skip);
        }
        return dp[0];
    }
};