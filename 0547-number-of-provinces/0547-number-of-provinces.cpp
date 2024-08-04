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

class DisjointSet{
    
    
    public:
    vector<int> rank , parent , size;
    DisjointSet(int n){
        rank.resize(n+1 , 0);
        parent.resize(n+1);
        size.resize(n+1);
        for(int i =0 ; i<n ;i++){
            parent[i]=i;
            size[i] =1;
        }
        
    }
    
    int findpar(int node){
        if(node == parent[node]){
            return node;
            
        }
        return parent[node] = findpar(parent[node]);
    }
    
    void unionByRank(int  u , int v){
        int ulp_u = findpar(u);
        int ulp_v = findpar(v);
        if(ulp_u == ulp_v) return;
        if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }
        else if(rank[ulp_v] < rank[ulp_u]){
            parent[ulp_v] = ulp_u;
        }
        else{
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
    
    void unionBySize(int  u , int v){
        int ulp_u = findpar(u);
        int ulp_v = findpar(v);
        if(ulp_u == ulp_v) return;
        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
    
};
class Solution {
// private:
//     void dfs(int node, vector<vector<int>>& isConnected, vector<bool>& vis) {
//         vis[node] = true;
//         for (int i = 0; i < isConnected[node].size(); ++i) {
//             if (isConnected[node][i] == 1 && !vis[i]) {
//                 dfs(i, isConnected, vis);
//             }
//         }
//     }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        // vector<bool> vis(n, false);
        // int cnt = 0;
        // for (int i = 0; i < n; ++i) { // Start from 0 and go to n-1
        //     if (!vis[i]) {
        //         ++cnt;
        //         dfs(i, isConnected, vis);
        //     }
        // }

        DisjointSet ds(n);
        for(int i =0 ; i<n ; i++){
            for(int j =0 ; j<n ; j++){
                if(isConnected[i][j] == 1){
                    ds.unionBySize(i, j);
                }
            }
        }
        int cnt =0;
        for(int i =0 ; i<n ;i++){
            if(ds.parent[i] == i){
                cnt++;
            }
        }
        return cnt;
    }
};
