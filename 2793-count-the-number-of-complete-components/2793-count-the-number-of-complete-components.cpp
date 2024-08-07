// class Solution {
//     private:
//     void dfs(int node , vector<int>& vis , vector<vector<int>>& adj){
//         vis[node] =1;
//         for(auto it:adj[node]){
//             if(!vis[it]){
//                 dfs(it , vis , adj);
//             }
//         }



//     }
// public:
//     int countCompleteComponents(int n, vector<vector<int>>& edges) {
//         vector<vector<int>> adj(n);
//         for (const auto& edge : edges) {
//             adj[edge[0]].push_back(edge[1]);
//             adj[edge[1]].push_back(edge[0]);
//         }

//         vector<int> vis(n , 0);
//         int cnt =0;
//         for(int i =0 ; i<n ; i++){
//             if(!vis[i]){
//                 cnt++;
//                 dfs(i , vis , adj);
//             }
//         }
//         return cnt;
        
//     }
// };

class Solution {
private:
    void dfs(int node, vector<int>& vis, vector<vector<int>>& adj, vector<int>& component) {
        vis[node] = 1;
        component.push_back(node);
        for (auto it : adj[node]) {
            if (!vis[it]) {
                dfs(it, vis, adj, component);
            }
        }
    }

    bool isComplete(const vector<int>& component, const vector<vector<int>>& adj) {
        int size = component.size();
        for (int i = 0; i < size; ++i) {
            for (int j = i + 1; j < size; ++j) {
                // Check if every pair of nodes in the component has an edge between them
                if (find(adj[component[i]].begin(), adj[component[i]].end(), component[j]) == adj[component[i]].end()) {
                    return false;
                }
            }
        }
        return true;
    }

public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        
        // Construct the adjacency list from the edges
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<int> vis(n, 0);
        int completeComponentCount = 0;

        // Find all connected components
        for (int i = 0; i < n; ++i) {
            if (!vis[i]) {
                vector<int> component;
                dfs(i, vis, adj, component);
                if (isComplete(component, adj)) {
                    ++completeComponentCount;
                }
            }
        }

        return completeComponentCount;
    }
};
