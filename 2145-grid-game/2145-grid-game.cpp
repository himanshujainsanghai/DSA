class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {

        long long firstRowRemaining = accumulate(grid[0].begin() , grid[0].end() , 0LL);
        long long secondRowRemaining = 0;

        long long minForRobot2 = LONG_LONG_MAX;

        for(int robo1=0 ; robo1 < grid[0].size() ; robo1++){
            firstRowRemaining -= grid[0][robo1];

            long long robo2CurrVals = max(secondRowRemaining, firstRowRemaining);

            minForRobot2 = min(minForRobot2 ,robo2CurrVals);
            secondRowRemaining += grid[1][robo1];
        }

        return minForRobot2;
        
    }
};