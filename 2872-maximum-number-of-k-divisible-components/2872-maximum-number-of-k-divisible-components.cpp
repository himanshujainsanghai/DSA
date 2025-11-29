class Solution {
public:
    int count;
    int dfs(int i , int parent , unordered_map<int , vector<int>> &adj ,  vector<int>& values, int k){
        int sum = values[i];

        for(auto &ngbr:adj[i]){
            if(ngbr != parent){
                sum += dfs(ngbr , i , adj , values , k);
                sum %= k;
            }
        }

        sum %= k;

        if(sum == 0) count++;

        return sum;
    }
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        unordered_map<int , vector<int>> adj;

        for(auto &edge:edges){
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        count = 0;
        dfs(0 , -1 , adj , values , k);
        return count;
    }
};