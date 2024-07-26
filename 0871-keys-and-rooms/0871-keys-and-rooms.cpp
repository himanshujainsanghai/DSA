class Solution {
private:
    void dfs(vector<vector<int>>& rooms, vector<bool>& vis, int room) {
        vis[room] = true;

        for (int key : rooms[room]) {
            if (!vis[key]) {
                dfs(rooms, vis, key);
            }
        }
    }

public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> vis(n, false);
        // vis[0] = true;
        // stack<int> q;
        // q.push(0);
        // while (!q.empty()) {
        //     int node = q.top();
        //     q.pop();
        //     for (auto it : rooms[node]) {
        //         if (!vis[it]) {
        //             vis[it] = true;
        //             q.push(it);
        //         }
        //     }
        // }
        dfs(rooms, vis, 0);
        for (bool roomVisited : vis) {
            if (!roomVisited)
                return false;
        }
        return true;
    }
};