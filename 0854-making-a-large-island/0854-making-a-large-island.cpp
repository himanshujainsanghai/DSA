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
    private:
    bool isValid(int nrow  , int ncol , int n){
        return nrow>=0 && nrow<n && ncol>=0 && ncol<n;
    }
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n*n);
        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};
        for(int row=0 ; row<n ; row++){
            for(int col =0 ; col<n ; col++){
                if(grid[row][col] == 0) continue;
                for(int i =0 ; i<4 ; i++){
                    int nrow = row + dr[i];
                    int ncol = col + dc[i];
                    if(isValid(nrow  , ncol , n) && grid[nrow][ncol] == 1){
                        int node = row*n + col;
                        int adjnode = nrow*n + ncol;
                        ds.unionBySize(node , adjnode);


                    }
                }
            }
        }

        int maxi = 0;
        for(int  row =0 ; row<n ; row++){
            for(int col =0 ; col<n ; col++){
                if(grid[row][col] == 1) continue;
                set<int> comp;
                for(int i =0 ; i<4 ; i++){
                    int newr = row + dr[i];
                    int newc = col + dc[i];
                    if(isValid(newr , newc , n)){
                        if(grid[newr][newc]==1){
                            comp.insert(ds.findpar(newr*n + newc));
                        }
                    }
                } 
                int size =0;
                for(auto it:comp){
                    size += ds.size[it];
                }
                maxi = max(maxi , size+1);
            }
        }
        // for(int cell =0 ; cell<n*n ; cell++){
        //     maxi = max(maxi , ds.size[ds.findpar(cell)]);
        // }
        maxi=max(maxi,ds.size[0]);
        return maxi;
    }
};