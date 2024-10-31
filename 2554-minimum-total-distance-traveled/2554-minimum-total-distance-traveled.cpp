// class Solution {
// public:
//     long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        
//     }
// };
// using ll = long long;

// class Solution {
// public:
//     long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
//         sort(robot.begin(), robot.end());
//         sort(factory.begin(), factory.end());
//         vector<vector<ll>> f(robot.size(), vector<ll>(factory.size()));
//         function<ll(int i, int j)> dfs = [&](int i, int j) -> ll {
//             if (i == robot.size()) return 0;
//             if (j == factory.size()) return 1e15;
//             if (f[i][j]) return f[i][j];
//             ll ans = dfs(i, j + 1);
//             ll t = 0;
//             for (int k = 0; k < factory[j][1]; ++k) {
//                 if (i + k >= robot.size()) break;
//                 t += abs(robot[i + k] - factory[j][0]);
//                 ans = min(ans, t + dfs(i + k + 1, j + 1));
//             }
//             f[i][j] = ans;
//             return ans;
//         };
//         return dfs(0, 0);
//     }
// };

class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        int n = robot.size();
        int m = factory.size();
        vector<long long> dp(n + 1, 10e12);
        dp[0] = 0;
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());
        for (int i = 0; i < m; i++) {
            int position = factory[i][0];
            int limit = factory[i][1];
            while (limit--) {
                for (int j = n - 1; j >= 0; j--) {
                    dp[j + 1] = min(dp[j + 1], abs(robot[j] - position) + dp[j]);
                }
            }
        }
        return dp[n];
    }
};