class Solution {
private:
    int func(int currday, vector<int>& days, vector<int>& costs, set<int> st,
             vector<int>& dp) {
        // Base cases
        if (currday > days[days.size() - 1]) {
            dp[currday] = 0;
            return 0;
        }

        if (dp[currday] != -1) {
            return dp[currday];
        }

        if (st.find(currday) == st.end()) {
            return dp[currday] = func(currday + 1, days, costs, st, dp);
        }

        int one = costs[0] + func(currday + 1, days, costs, st, dp);
        int seven = costs[1] + func(currday + 7, days, costs, st, dp);
        int thirty = costs[2] + func(currday + 30, days, costs, st, dp);

        return dp[currday] = min({one, seven, thirty});
    }

public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int maxday = days[days.size() - 1] + 30;

        set<int> st(days.begin(), days.end());

        // vector<int> dp(maxday+1 , -1);

        // return func(days[0] , days , costs , st , dp);

        // tabulation
        vector<int> dp(maxday + 1, 0);
        // base case
        

        for (int currday = maxday - 1; currday >= days[0]; currday--) {

            if (st.find(currday) == st.end()) {
                dp[currday] = dp[currday+1]; //func(currday + 1, days, costs, st, dp);
                continue;
            }

            int one = costs[0] +  dp[currday+1];//func(currday + 1, days, costs, st, dp);
            int seven = costs[1] + dp[currday+7]; //func(currday + 7, days, costs, st, dp);
            int thirty = costs[2] + dp[currday+30]; //func(currday + 30, days, costs, st, dp);

            dp[currday] = min({one, seven, thirty});
        }

        return dp[days[0]];
    }
};