class Solution {
public:
    bool dfs(int node, int col, vector<int>& color,
             vector<vector<int>>& graph) {
        color[node] = col;
        for (auto it : graph[node]) {
            if (color[it] == -1) {
                if (!dfs(it, !col, color, graph)) {
                    return false;
                }
            } else if (color[it] == col) {
                return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);
        // queue<int> q;

        for (int i = 0; i < n; i++) {
            // if (color[i] == -1) {
            //     q.push(i);
            //     color[i] = 0;
            //     while (!q.empty()) {
            //         int node = q.front();
            //         q.pop();
            //         for (auto it : graph[node]) {
            //             if (color[it] == -1) {
            //                 color[it] = !color[node];
            //                 q.push(it);
            //             } else if (color[it] == color[node]) {
            //                 return false;
            //             }
            //         }
            //     }
            // }

            if (color[i] == -1) {
                if (!dfs(i, 0, color, graph)) {
                    return false;
                }
            }
        }

        return true;
    }
};