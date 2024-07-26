// class Solution {
// private:
//     void dfs(int node, vector<vector<int>>& isConnected, vector<bool>& vis) {
//         vis[node] = true;
//         for (int i = 0; i < isConnected.size(); ++i) {
//             if (isConnected[node][i] == 1 && !vis[i]) {
//                 dfs(i, isConnected, vis);
//             }
//         }
//     }

// public:
//     int findCircleNum(vector<vector<int>>& isConnected) {
//         int n = isConnected.size();
//         // vector<int> listt[n];
//         // for (int i = 0 ; i < n; i++) {
//         //     for (int j = 0; j < n; j++) {
//         //         if (isConnected[i][j] == 1 && i != j) {
//         //             listt[i].push_back(j);
//         //             listt[j].push_back(i);
//         //         }
//         //     }
//         // }
//         vector<bool> vis(n, false);
//         int cnt = 0;
//         for (int i = 1; i <= n; i++) {
//             if (!vis[i]) {
//                 cnt++;
//                 dfs(i , isConnected , vis);
//             }
//         }
//         return cnt;
//     }
// };


class Solution {
private:
    void dfs(int node, vector<vector<int>>& isConnected, vector<bool>& vis) {
        vis[node] = true;
        for (int i = 0; i < isConnected[node].size(); ++i) {
            if (isConnected[node][i] == 1 && !vis[i]) {
                dfs(i, isConnected, vis);
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> vis(n, false);
        int cnt = 0;
        for (int i = 0; i < n; ++i) { // Start from 0 and go to n-1
            if (!vis[i]) {
                ++cnt;
                dfs(i, isConnected, vis);
            }
        }
        return cnt;
    }
};
