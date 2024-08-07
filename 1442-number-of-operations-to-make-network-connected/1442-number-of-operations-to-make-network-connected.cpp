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
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        int cntE = 0;
        for(auto it: connections){
            int u = it[0];
            int v = it[1];
            if(ds.findpar(u) != ds.findpar(v)){
                ds.unionBySize(u,v);
            }
            else{
                cntE++;
            } 

        }
        int comp =0;
        for(int i =0 ; i<n ; i++){
            if(ds.parent[i] == i) comp++;
        }
        
        if(cntE >= comp-1){
            return comp-1;
        }
        return -1;
        
    }
};