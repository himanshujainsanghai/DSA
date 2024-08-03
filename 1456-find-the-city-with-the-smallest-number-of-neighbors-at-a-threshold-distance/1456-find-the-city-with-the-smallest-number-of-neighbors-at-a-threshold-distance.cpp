class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        for (auto it : edges) {
            if (it[2] <= distanceThreshold) {
                dist[it[0]][it[1]] = it[2];
                dist[it[1]][it[0]] = it[2];
            }
        }
        for (int i = 0; i < n; i++) {
            dist[i][i] = 0;
        }

        for (int val = 0; val < n; val++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (dist[i][val] == INT_MAX || dist[val][j] == INT_MAX)
                        continue;
                    dist[i][j] = min(dist[i][j], dist[i][val] + dist[val][j]);
                }
            }
        }
        int cntcity = n;
        int cityNo = -1;
        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                if (dist[i][j] <= distanceThreshold) {
                    cnt++;
                }
            }

            if (cnt <= cntcity) {
                cntcity = cnt;
                cityNo = i;
            }
        }
        return cityNo;
    }
};