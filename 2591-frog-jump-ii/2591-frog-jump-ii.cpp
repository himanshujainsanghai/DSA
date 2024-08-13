// class Solution {
// private:
//     int n;
//     int fnc(int ind, vector<int>& stones) {
//         if (ind == 0)
//             return 0;
//         int minSteps = INT_MAX;
//         for (int j = 1; j <= n-1; j++) {
//             if (ind - j >= 0) {
//                 int jump =
//                     fnc(ind - j, stones) + abs(stones[ind] - stones[ind - j]);
//                 minSteps = min(minSteps, jump);
//             }
//         }
//         return minSteps;
//     }

// public:
//     int maxJump(vector<int>& stones) {
//         n = stones.size();
//         // vector<int> dp(n + 1, -1);
//         // dp[0] = 0;
//         // for (int i = 1; i < n; i++) {
//         //     int minsteps = INT_MAX;
//         //     int jump = INT_MAX;
//         //     for (int j = 1; j < n; j++) {
//         //         if (i - j >= 0) {
//         //             jump = dp[i - j] + abs(stones[i] - stones[i - j]);
//         //         }
//         //         minsteps = min(minsteps, jump);
//         //     }
//         //     dp[i] = minsteps;
//         // }
//         // return dp[n - 1];
//         return fnc(n-1 , stones);
//     }
// };

class Solution {
public:
    int maxJump(vector<int>& stones) {
        int n = stones.size();
        if(n<=2) return stones.back();

        int max_jump = 0;

        // Check the jumps when moving forward
        for (int i = 2; i < n; i += 2) {
            max_jump = max(max_jump, stones[i] - stones[i - 2]);
        }

        // Check the jumps when moving backward
        for (int i = 1; i < n; i += 2) {
            if (i - 2 >= 0) { // Ensure we don't access out of bounds
                max_jump = max(max_jump, stones[i] - stones[i - 2]);
            }
        }
        // for(int i = 0; i + 2 < n; i++) {
        //     max_jump = std::max(max_jump, stones[i + 2] - stones[i]);
        // }

        return max_jump;
    }
};
